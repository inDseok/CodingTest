#include<iostream>
#include<stack>
using namespace std;

int graph[101][101];
int visited[101];
int cnt=0;

void dfs(int vertex, int start)
{
	visited[start] = 1;
	for (int i = 1; i <= vertex; i++)
	{
		if (graph[start][i] == 1 && visited[i] == 0) {
			cnt++;
			dfs(vertex, i);
		}
	}
}

int main()
{
	int computer,edge;
	int count = 0;
	cin >> computer >> edge;
	for (int i = 1; i <= edge; i++)
	{
		int x,y;
		cin >> x >> y;
		graph[x][y] = 1;
		graph[y][x] = 1;
	}
	dfs(computer, 1);
	cout << cnt;
}
