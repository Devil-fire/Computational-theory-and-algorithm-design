//
//
//  Yogurt_factory
//
//  Created by Devil on 2019/3/20 11:19:28.
//  Copyright © 2019 Devil. All rights reserved.
//
// 
#include<iostream>
using namespace std;
int main()
{
	int n, s, c, y;
	int min = 0x3f3f3f;
	long long sum = 0;
	cin >> n >> s;
	for (int i = 0; i < n; i++)
	{
		cin >> c >> y;
		if (min > c)min = c;
		sum += min * y;
		//cout << min << endl;
		min += s;
	}
	cout << sum << endl;
	return 0;
}
