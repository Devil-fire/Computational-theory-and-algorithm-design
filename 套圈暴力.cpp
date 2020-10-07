//
//
//  套圈暴力
//
//  Created by Devil on 2019/4/8 18:26:49.
//  Copyright © 2019 Devil. All rights reserved.
//
// 
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
typedef struct point
{
	double x, y;
}point;
point node[100005];
bool cmp(point a, point b)
{
	if (a.x != b.x)
		return a.x < b.x;
	else return a.y < b.y;
}
int main()
{
	int n;
	while (scanf("%d", &n) && n != 0)
	{
		double dx = 0.0, dy = 0.0; double min = 999999999.999;
		for (int i = 0; i < n; i++)
			scanf("%lf %lf", &node[i].x, &node[i].y);
		sort(node, node + n, cmp);
		//for (int i = 0; i < n; i++)
		//	cout << node[i].x << " " << node[i].y << endl;
		for (int i = 0; i < n - 1; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				dx = node[j].x - node[i].x; dy = node[j].y - node[i].y;
				if (dx >= min && dy >= min) break;
				double distance = sqrt(dx * dx + dy * dy);
				if (min > distance) min = distance;
			}
		}
		printf("%.2lf\n", min / 2);
	}
	return 0;
}