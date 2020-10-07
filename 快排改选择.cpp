//
//
//  快排改选择
//
//  Created by Devil on 2019/3/18 22:27:34.
//  Copyright © 2019 Devil. All rights reserved.
//
// 
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
using namespace std;
int a[2000005];
int position(int p, int r)
{
	int x = a[p];
	int temp;
	int i = p + 1, j = r;
	while (i < j)
	{
		while (a[i] < x&&i < j) i++;
		while (a[j] > x) j--;
		if (i >= j) break;
		else
		{
			temp = a[i];
			a[i] = a[j];
			a[j] = temp;
		}

	}
	temp = a[p];
	a[p] = a[j];
	a[j] = temp;
	return j;
}

int select(int p, int r, int k)
{
	if (p == r) return a[p];
	int middle = position(p, r);
	if(middle>k) return select(p, middle - 1, k);
	else return select(middle + 1, r, k);
}
int main()
{
	int x, i = 0;
	while (scanf("%d,%d", &x, &a[++i]) != EOF);
	i = i - 2;
	int ans = select(0, i, i / 2 + 1);
	cout << ans << endl;
	return 0;
}
