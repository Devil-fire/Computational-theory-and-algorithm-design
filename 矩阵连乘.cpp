//
//
//  矩阵连乘
//
//  Created by Devil on 2019/3/19 19:55:23.
//  Copyright © 2019 Devil. All rights reserved.
//
// 
#include<iostream>
#include<cstring> 
using namespace std;
int m[105][105], s[105][105];
void Matrix(int p[], int n)
{
	for (int i = 1; i <= n; i++)
		m[i][i] = 0;
	for (int r = 1; r < n; r++)
	{
		for (int i = 1; i <= n - r; i++)
		{
			int j = i + r;
			m[i][j] = m[i + 1][j] + p[i - 1] * p[i] * p[j];
			s[i][j] = i;
			//cout << m[i][j] << " " << i << " " << j << endl;
			for (int k = i + 1; k < j; k++)
			{
				int t = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
				//cout << t << "   "<<i <<"   " <<j << endl;
				if (t < m[i][j])
				{
					m[i][j] = t;
					s[i][j] = k;
				}
			}
		}
	}	
}
void Trackback(int i, int j)
{
	if (i == j) cout << "A" << i;
	else 
	{
		cout << "(";
		Trackback(i, s[i][j]);
		Trackback(s[i][j] + 1, j);
		cout << ")";
	}
		
}
int main()
{
	int n;
	int p[105];
	memset(p, 0, sizeof(p));
	cin >> n;
	for (int i = 0; i <= n; i++)
		cin >> p[i];
	Matrix(p, n);
	cout << m[1][n] << endl;
	if (n == 1) cout << "(";
	Trackback(1, n);
	if (n == 1)cout << ")";
	cout << endl;
	return 0;
}
