//
//
//  Tri_Tiling
//
//  Created by Devil on 2019/3/20 20:01:17.
//  Copyright © 2019 Devil. All rights reserved.
//
// 
#include<iostream>
using namespace std;
int a[30];
void cal()
{
	a[0] = 1;
	a[2] = 3;
	for (int i = 4; i <= 30; i = i + 2)
		a[i] = 4 * a[i - 2] - a[i - 4];
}
int main()
{
	int k;
	memset(a, 0, sizeof(a));
	cal();
	while (cin >> k && k != -1)
	{
		cout << a[k] << endl;
	}
	return 0;
}
