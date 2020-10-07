//
//
//  油管问题
//
//  Created by Devil on 2019/3/18 20:37:32.
//  Copyright © 2019 Devil. All rights reserved.
//
// 
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int a[2000005];
/*void Insertsort(int L[], int N) {
	int i, j, temp;
	for (i = 1; i < N; i++) {
		if (L[i] < L[i - 1]) {
			temp = L[i];
			L[i] = L[i - 1];
			for (j = i - 1; j >= 0 && temp < L[j]; j--) {
				L[j + 1] = L[j];
			}
			L[j + 1] = temp;
		}
	}
}*/
void bubblesort(int p, int r) {
	for (int i = p; i < r; i++) {
		for (int j = i + 1; j <= r; j++) {
			if (a[j] < a[i])swap(a[i], a[j]);
		}
	}
}
int partition(int a[], int p, int r, int val) {
	int i = p - 1, j = r + 1, x = val;
	while (1) 
	{
		while (a[++i] < x&&i < r);
		while (a[--j] > x);
		if (i >= j)break;
		swap(a[i], a[j]);
	}
	//swap(a[p], a[j]);
	return j;
}
int select(int a[], int p,int r,int k)
{
	int x, i, j;
	if (r - p < 75)
	{
		bubblesort(p, r);
		//Insertsort(a + p, r - p + 1);
		return a[p + k - 1];
	}
	for (int z = 0; z <= (r - p - 4) / 5; z++)
	{
		bubblesort(p + 5 * z, p + 5 * z + 4);
		//Insertsort(a + p + 5 * z, 5);
		swap(a[p + z], a[p + 5 * z + 2]);
	}
	x = select(a, p, p + (r - p - 4) / 5, (r - p - 4) / 10);
	i = partition(a, p, r, x);
	j = i - p + 1;
	if (k <= j) return select(a, p, i, k);
	else return select(a, i + 1, r, k - j);

}

int main()
{
	int ans; int x, y, i = 0;
	while (scanf("%d,%d", &y, &x) != EOF)
		a[i++] = x;
	ans = select(a, 0, i - 1, (i + 1) / 2);
	cout << ans << endl;
}