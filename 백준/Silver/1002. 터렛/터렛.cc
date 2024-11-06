#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <math.h>
#include <stdlib.h>

int main() {
	int testcase=0;
	int x1, y1, r1, x2, y2, r2;
	scanf("%d", &testcase);
	int result=0;
	for(int i=0;i< testcase;i++)
	{
		scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);
		int r3 = r1 > r2 ? r1 - r2 : r2 - r1;
		double dis=0.0;
		dis = sqrt(pow(x2 - x1,2) + pow(y2 - y1,2));
		if ((dis == 0) && (r1 == r2))
			result = -1;
		else if (dis == r1 + r2 || dis == r3)
			result=1;
		else if ((dis < r1 + r2) && dis > r3)
			result=2;
		else
			result=0;
		printf("%d\n", result);
	}
	return 0;
}