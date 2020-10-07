//
//
//  Trees_Made_to_Order
//
//  Created by Devil on 2019/4/8 23:59:10.
//  Copyright © 2019 Devil. All rights reserved.
//
// 
#include<iostream>
using namespace std;
long long Catalan[25]; 

void print(int k, long long n)
{
	if (k == 1)
	{
		cout << "X";
		return;
	}
	//cout << k << " " << n << " " << Catalan[k] << " " << Catalan[k] - Catalan[k - 1] << endl;
	if (n <= Catalan[k - 1])
	{
		cout << "X(";
		print(k - 1, n);
		cout << ")";
	}
	else if (n > Catalan[k] - Catalan[k - 1])
	{
		cout << "(";
		print(k - 1, n - Catalan[k] + Catalan[k - 1]);
		cout << ")X";
	}
	else
	{
		int t = k - 1, right;
		for (int i = t; i >= 0; i--) 
		{ 
			if (Catalan[i] * Catalan[t - i] < n)
				n -= Catalan[i] * Catalan[t - i];
			else {
				right = i;
				break;
			}
		}
		printf("(");
		print(t - right, n / Catalan[right] + (n % Catalan[right] != 0));
		cout<<")X(";
		print(right, (n - 1) % Catalan[right] + 1);  
		cout << ")";
	}
}
int main()
{
	Catalan[0] = 1;
	int k;
	for (int i = 1; i < 20; i++)
		Catalan[i] = Catalan[i - 1] * (4 * i - 2) / (i + 1);
	long long n;
	while (1)
	{
		cin >> n;
		if (n == 0)break;
		for (int i = 0; n >= Catalan[i]; i++)
		{
			n -= Catalan[i];
			k = i;
		}
		//cout << k << endl;
		print(k + 1, n + 1);
		cout << endl;
	}
	return 0;
}
