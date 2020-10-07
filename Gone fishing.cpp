//
//
//  Gone_fishing
//
//  Created by Devil on 2019/4/8 19:41:42.
//  Copyright © 2019 Devil. All rights reserved.
//
// 
#include<iostream>
#include<cstring>
using namespace std;
int fi[25], di[25], ti[25], t[25], temp1[25], temp2[25], fish[25];
int main()
{
	int k = 0;
	while (1)
	{
		int n, h; int max = 0, t_road = 0 ,sum = 0;
		cin >> n;
		if (n == 0) break;
		cin >> h;
		if (k != 0)cout << endl;
		h *= 60;
		for (int i = 0; i < n; i++)
			cin >> fi[i];
		for (int i = 0; i < n; i++)
			cin >> di[i];
		ti[0] = 0;
		for (int i = 0; i < n - 1; i++)
		{
			cin >> ti[i];
			ti[i] *= 5;
		}
		max = -1;
		for (int i = 0; i < n; i++)
		{
			sum = 0;
			int t_left = h - t_road;
			memset(temp1, 0, sizeof(temp1));
			memset(temp2, 0, sizeof(temp2));
			for (int j = 0; j < n; j++) fish[j] = fi[j];
			while (t_left > 0)
			{
				int most = -1;
				int lake_id;
				for (int j = 0; j <= i; ++j)
				{
					if (fish[j] > most)
					{
						most = fish[j];
						lake_id = j;
					}
				}
				//cout << i << " " << lake_id << endl;
				if (most == 0)
				{
					temp1[0] += t_left / 5 * 5;
					break;    
				}
				temp1[lake_id] += 5;
				sum += fish[lake_id];
				fish[lake_id] -= di[lake_id];
				if (fish[lake_id] < 0) fish[lake_id] = 0;
				t_left -= 5;
			}
			//cout << sum << "  "<<max<<endl;
			if (sum > max)
			{
				max = sum;
				for (int j = 0; j < n; j++)
					t[j] = temp1[j];
				//cout << max<<"jkasjfio"<<endl;
			}
			else if (sum == max)
			{
				for (int k = 0; k < n; k++)
				{
					if (temp1[k] < t[k]) break;
					if (temp1[k] > t[k]) 
						for (int j = 0; j < n; j++)
							t[j] = temp1[j];
				}
			}
			t_road += ti[i];
		}
		cout << t[0];
		for (int i = 1; i < n; i++) cout << ", " << t[i];
		cout << endl << "Number of fish expected: " << max << endl;
		k++;
	}
	return 0;
}
