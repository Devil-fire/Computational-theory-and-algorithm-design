//
//
//  套圈
//
//  Created by Devil on 2019/3/18 19:22:24.
//  Copyright © 2019 Devil. All rights reserved.
//
// 
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
typedef struct point
{
	int id;
	float x, y;
}point;
void Merge(point c[], point d[], int l, int m, int r)
{
	int i = l, j = m + 1, k = l;
	while ((i <= m) && (j <= r))
	{
		if (c[i].y <= c[j].y)
		{
			d[k++] = c[i++];
		}
		else
		{
			d[k++] = c[j++];
		}
	}

	if (i > m)
	{
		for (int q = j; q <= r; q++)
		{
			d[k++] = c[q];
		}
	}
	else
	{
		for (int q = i; q <= m; q++)
		{
			d[k++] = c[q];
		}
	}
}
float distance(point u, point v)
{
	float dx = u.x - v.x;
	float dy = u.y - v.y;
	return sqrt(dx*dx + dy * dy);
}
int cmp1(const void *a, const void *b)
{
	return (*(point *)a).x > (*(point *)b).x ? 1 : -1;
}
int cmp2(const void *a, const void *b)
{
	return (*(point *)a).y > (*(point *)b).y ? 1 : -1;
}

void closest(point x[], point y[], point z[], int l, int r, float &d)
{
	if (r - l == 1)
	{
		d = distance(x[l], x[r]);
		return;
	}
	else if (r - l == 2)
	{
		float d1 = distance(x[l], x[l + 1]);
		float d2 = distance(x[r], x[l + 1]);
		float d3 = distance(x[l], x[r]);
		if (d1 <= d2 && d1 <= d3)
		{
			d = d1;
			return;
		}
		else if (d2 <= d3)
		{
			d = d2;
			return;
		}
		else 
		{
			d = d3;
			return;
		}
	}
	int m = (l + r) / 2;
	//cout << l << " " << r << endl;
	int f = l, g = m + 1;
	for (int i = l; i <= r; i++)
	{
		if (y[i].id > m)
			z[g++] = y[i];
		else z[f++] = y[i];
	}
	closest(x, z, y, l, m, d);
	float dr;
	closest(x, z, y, m + 1, r, dr);
	if (dr < d)
		d = dr;
	//cout << d << " " << dr << endl;
	//cout << d << endl;
	Merge(z, y, l, m, r);
	//for (int i = l; i < r; i++)
	//	cout << (y + i)->x << " " << (y + i)->y << endl;
	Merge(z, y, l, m, r);
	cout << endl;
	//for (int i = l; i < r; i++)
	//	cout << "a " << (y + i)->x << " " << (y + i)->y << endl;
	int k = 1;
	for (int i = 1; i <= r; i++)
	{
		//cout << y[m].x << " " << y[i].x << endl;
		if (fabs(y[m].x - y[i].x) < d)
			z[k++] = y[i];
	}
	for (int i = l; i < k; i++) cout << "a "<<z[i].x << " " << z[i].y << endl;
	for (int i = l; i < k; i++)
	{
		for (int j = i + 1; j < k&&z[j].y - z[i].y < d; j++)
		{
			float dp = distance(z[i], z[j]);
			cout << dp << " " << z[i].x << " " << z[i].y << " " << z[j].x << " " << z[j].y << endl;
			if (dp < d)
			{
				d = dp;
			}
		}
	}
}
void Cpair(point a[],point b[],point c[],int n, float &d)
{
	qsort(a, n, sizeof(a[0]), cmp1);
	for (int i = 0; i < n; i++)
	{
		b[i].id = i;
		b[i].x = a[i].x;
		b[i].y = a[i].y;
	}
	qsort(b, n, sizeof(b[0]), cmp2);
	//for (int i = 0; i < n; i++) cout << b[i].x << " " << b[i].y << endl;
	closest(a, b, c, 0, n - 1, d);
	return;
}
point a[100005], b[100005], c[100005];
int main()
{
	int n;

	while (cin >> n && n != 0)
	{
		for (int i = 0; i < n; i++)
		{
			scanf("%f %f", &a[i].x, &a[i].y);
			a[i].id = i;
		}	
		float d;
		cout << endl;
		Cpair(a, b, c, n, d);
		printf("%.2f\n", d / 2);
	}
}
