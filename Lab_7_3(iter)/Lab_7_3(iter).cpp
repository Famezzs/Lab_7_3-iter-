// Lab_7_3(iter).cpp
// Козубенко Андрій
// Лабораторна робота № 7.3
// Опрацювання динамічних багатовимірних масивів.
// Ітераційний спосіб
#include <iostream>
#include <iomanip>
#include <time.h>

using std::cout;
using std::cin;
using std::endl;
using std::setw;
using std::cerr;

void Create(int **a, const int n, const int Low, const int High);
void Print(int **a, const int n);
void LocalMinimum(int **a, const int n, int &k);
int Sum(int **a, const int n);

int main()
{
	srand((unsigned)time(NULL));
	int n;
	int k = 0;
	int Low;
	int High;

	cout << "How many rows and columns should a matrix have?\nn = "; cin >> n;
	if (n < 1)
	{
		cerr << "n should be > 1";
		return -1;
	}

	cout << "What interval should RNG satisfy? (i.e., [A;B], A <= B, A and B are integers)\nA = "; cin >> Low;
	cout << "B = "; cin >> High;
	if (Low > High)
	{
		cerr << "A must be <= B";
		return -2;
	}

	int **Q = new int *[n];
	for (int i = 0; i < n; i++)
		Q[i] = new int[n];

	Create(Q, n, Low, High);
	Print(Q, n);
	LocalMinimum(Q, n, k);
	
	cout << "Number of local minima = " << k << endl;
	cout << "Sum of elements above main diagonal = " << Sum(Q, n) << endl;

	for (int i = 0; i < n; i++)
		delete[] Q[i];
	delete[] Q;

	return 0;
}

void Create(int **a, const int n, const int Low, const int High)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			a[i][j] = Low + rand() % (High - Low + 1);
}

void Print(int **a, const int n)
{
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << setw(4) << a[i][j];
		cout << endl;
	}
	cout << endl;
}

void LocalMinimum(int **a, const int n, int &k)
{
	k = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			int tmp = a[i][j];
			if (i > 0 && tmp >= a[i - 1][j] || j > 0 && tmp >= a[i][j - 1] ||
				i < n - 1 && tmp >= a[i + 1][j] || j < n - 1 && tmp >= a[i][j + 1] || 
				i < n - 1 && j < n - 1 && tmp >= a[i + 1][j + 1] || i > 0 && j > 0 &&
				tmp >= a[i - 1][j - 1] || i > 0 && j < n - 1 && tmp >= a[i - 1][j + 1] || 
				i < n - 1 && j > 0 && tmp >= a[i + 1][j - 1])
				continue;

			k++;
		}
}

int Sum(int **a, const int n)
{
	int S = 0;
	for (int i = 0; i < n; i++)
		for (int j = 1 + i; j < n; j++)
			S += a[i][j];

	return S;
}