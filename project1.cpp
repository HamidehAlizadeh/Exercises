#include<iostream>
#include<conio.h>
using namespace std;
void sort(float * A, int n)
{
	int i,  j;
	float t;

	for (i = 1; i<n; i++)
	{
		t = A[i];
		for (j = i - 1; j >= 0; j--)

		{
			if (A[j]>t)
				A[j + 1] = A[j];
			else break;
		}
		A[j + 1] = t;
	}
}

float Avg(float *A, int n)
{
	float sum=0;

	for (int i = 0; i < n; i++)
		sum += A[i];

	return sum/n;
}

float min(float *A, int n)
{
	return A[0];
}

float max(float *A, int n)
{
	return A[n - 1];
}

float median(float *A,int n)
{
	if (n % 2 == 1)
		return A[n / 2];
	else
		return (A[n / 2] + A[n / 2 - 1]) / 2;
}

float Q1(float *A, int n)
{
	if (n % 2 == 1)
	{
		n = n / 2 ;
	}
	else n = n / 2 -1;
	return median( A,  n);
}

float Q3(float *A, int n)
{
	float *B;
	int m;
	if (n % 2 == 1)
		m = n / 2 ;
	else m = n / 2 - 1;
	B = new float[m];
	int j = 0;
	for (int i = n/2+1; i < n; i++)
	{
		B[j] = A[i];
		j++;
	}
	float f=median(B, m);
	delete[]B;
	return f;
}

void outlier(float *A, int n)
{
	float o1 = Q1(A, n) - (1.5*(Q3(A, n) - Q1(A, n)));
	float o2 = Q3(A, n) + (1.5*(Q3(A, n) - Q1(A, n)));
	for (int i = 0; i < n; i++)
	{
		if (A[i] < o1)
			cout << A[i] << " ";
		else break;
	}
	cout << "\n";
	for (int i = n-1; i >= 0; i--)
	{
		if (A[i] > o2)
			cout << A[i] << " ";
		else break;
	}
	if (A[0] >= o1 && A[n - 1] <= o2) cout << "Dont have outlier";

}

int main()
{
	float *A;
	int n;
	cin >> n;
	A = new float[n];
	for (int i = 0; i < n; i++)
		cin >> A[i];
	sort(A, n);
	float a = median(A, n);
	cout <<"median="<< a << "\n";
	a = Avg(A, n);
	cout << "Avg= " << a << "\n";
	a = min(A, n);
	cout <<"min= "<< a << "\n";
	a = max(A, n);
	cout <<"MAx= "<< a << "\n";
	a = Q1(A, n);
	cout <<"Q!= "<< a << "\n";
	a = Q3(A, n);
	cout <<"Q3= "<<a<< "\n";
	outlier(A, n);
	delete[]A;

	getch();
	return 0;
}