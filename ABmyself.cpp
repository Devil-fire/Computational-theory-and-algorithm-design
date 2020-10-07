//
//  ABmyself
//
//  Created by Devil on 2019/3/18 18:27:13.
//  Copyright © 2019 Devil. All rights reserved.
//
#include<iostream>
#include<string>
using namespace std;
int x[20015], y[20015], result[42000];
int main()
{
	string s1, s2;
	cin >> s1 >> s2;
	//printf("%d %d\n", (int)s1.length, (int)s2.length);
	int len1 = (int)s1.length(), len2 = (int)s2.length();
	for (int i = 0; i < len1; i++)
		x[i] = s1[len1 - i - 1] - '0';
	for (int i = 0; i < len2; i++)
		y[i] = s2[len2 - i - 1] - '0';
	for (int i = 0; i < len1; i++)
		for (int j = 0; j < len2; j++)
			result[i + j] += x[i] * y[j];
	int len = len1 + len2;
	for(int i=0;i<len;i++)
		if (result[i] >= 10)
		{
			result[i + 1] += result[i] / 10;
			result[i] %= 10;
		}
	while (result[len] == 0) len--;
	if (len < 0) printf("0\n");
	else
	{
		for (; len >= 0; len--)
			cout << result[len];
	}
	cout << endl;
	return 0;
}