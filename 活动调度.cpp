//
//
//  活动调度
//
//  Created by Devil on 2019/4/3 15:34:17.
//  Copyright © 2019 Devil. All rights reserved.
//
// 
#include<iostream>
#include<algorithm>
using namespace std;
long long s[1000005];
long long f[1000005];
int main()
{
	int n;
	int count = 0, max = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> s[i] >> f[i];
	}	
	sort(s, s + n);
	sort(f, f + n);
	for (int i = 0, j = 0; i < n&&j < n;)
	{
		if (s[i] < f[j])
		{
			i++;
			count++;
			if (count > max) max = count;
		}
		else if (s[i] > f[j])
		{
			j++;
			count--;
		}
		else
		{
			i++; j++;
		}
	}
	cout << max << endl;
	return 0;
}
