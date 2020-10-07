//
//  Cable_master
//
//  Created by Devil on 2019/3/18 15:14:35.
//  Copyright © 2019 Devil. All rights reserved.
//
#include<iostream>
using namespace std;
float a[10005];
int n, k;
bool fuction(long long x)
{
	int sum = 0;
	for (int i = 0; i < n; i++)
		sum += (int)(a[i] / x + 1e-8);
	if (sum >= k) return 1;
	else return 0;
}
int main()
{
	cin >> n >> k;
	float sum = 0.0;
	long long mid = 0;	
	long long l = 1;
	long long r = 0;
	double t;
	for (int i = 0; i < n; i++)
	{
		cin >>t;
		a[i] = t * 100;
		sum += a[i];
		if (a[i] > r) r = a[i] + 1e-8;
	}
	//cout << sum << endl;
	if (sum / k < r) r = sum / k;
	if (sum < k) cout << "0.00" << endl;
	else
	{
		while (r >= l)
		{
			mid = (l + r) / 2;
			//cout << mid<< endl;
			if (fuction(mid))
				l = mid + 1;
			else r = mid - 1;
		}
		printf("%0.2f\n", r*0.01);
	}
		
	return 0;
}