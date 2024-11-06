#include<iostream>
#include<queue>
#include<stdio.h>
using namespace std;
int maze[101][101];
int visited[101][101];
bool check(int y, int x,int N,int M)
{
	if (y<1 || y>N || x<1 || x>M)
		return false;
	if (maze[y][x] == 0)
		return false;
	if (visited[y][x] == 1)
		return false;
	return true;
}
int main()
{
	int line, colume;
	cin >> line >> colume;
	for (int i = 1; i <= line; i++) 
	{
		for (int j = 1; j <= colume; j++)
		{
			scanf("%1d", &maze[i][j]);
		}
	}
	queue<int> qx,qy,qc;
	qx.push(1);
	qy.push(1);
	qc.push(1);
	int count = 0;
	while (!qy.empty())
	{
		int cy = qy.front();
		qy.pop();
		int cx = qx.front();
		qx.pop();
		int cc = qc.front();
		qc.pop();
		if (visited[cy][cx]) {
			continue;
		}
		visited[cy][cx] = 1;
		
		if(cy==line&&cx==colume)
		{
			count = cc;
			break;
		}
		if (check(cy+1, cx, line, colume)) {
			qy.push(cy + 1), qx.push(cx), qc.push(cc + 1);
		}
		if (check(cy-1, cx, line, colume)) {
			qy.push(cy - 1), qx.push(cx), qc.push(cc + 1);
		}
		if (check(cy, cx-1, line, colume)) {
			qy.push(cy), qx.push(cx - 1), qc.push(cc + 1);
		}
		if (check(cy, cx+1, line, colume)) {
			qy.push(cy), qx.push(cx + 1), qc.push(cc + 1);
		}
	}
	cout << count;
}