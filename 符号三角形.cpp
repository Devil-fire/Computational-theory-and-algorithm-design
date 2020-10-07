//
//
//  符号三角形
//
//  Created by Devil on 2019/4/10 18:40:44.
//  Copyright © 2019 Devil. All rights reserved.
//
// 
#include<iostream>
#include<cstring>
using namespace std;
int cou = 0, half, sum = 0, n;
int p[30][30];
void backtrack(int t)
{
	if (cou > half || t * (t - 1) / 2 - cou > half) return;
	//cout << cou << endl;
	if (t > n)
	{
		sum++;
		return;
	}
	for (int i = 0; i < 2; i++)
	{
		p[1][t] = i;
		cou += i;
		for (int j = 2; j <= t; j++)
		{
			p[j][t - j + 1] = (p[j - 1][t - j + 1] ^ p[j - 1][t - j + 2]);
			cou += p[j][t - j + 1];
		}
		backtrack(t + 1);
		for (int j = 2; j <= t; j++)
			cou -= p[j][t - j + 1];
		cou -= i;
	}
}
int main()
{
	cin >> n;
	memset(p, 0, sizeof(p));
	if ((n * (n + 1) / 2) % 2 == 1) cout << "0" << endl;
	else
	{
		//cout << "1" << endl;
		half = n * (n + 1) / 4;
		backtrack(1);
		cout << sum << endl;
	}
	return 0;
}
