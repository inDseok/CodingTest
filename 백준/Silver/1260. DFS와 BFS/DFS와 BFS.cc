#include <stdio.h>
#include<iostream>
#include <queue>
using namespace std;

#define max 1001

int graph[max][max];
int visited[max];

void init(int N) {
	for (int i = 1; i <= N; i++) {
		visited[i] = 0;
	}
}

void dfs(int N,int v) {
	visited[v] = 1;
	cout << v << " ";
	for (int i = 1; i <= N; i++) {
		if (graph[v][i] == 1 && visited[i] == 0)
			dfs(N,i);
	}
}

void bfs(int N,int v) {
	queue<int> Q;
	Q.push(v);
	visited[v] = 1;
	cout << v << " ";
	
	while (!Q.empty()) {
		v = Q.front();
		Q.pop();
		for (int i = 1; i <= N; i++) {
			if (graph[v][i] == 1 && visited[i] == 0) {
				Q.push(i);
				visited[i] = 1;
				cout << i << " ";
			}
		}
	}
}

int main() {
	int N, M, V;
	cin >> N>> M >>V;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		graph[a][b] = 1;
		graph[b][a] = 1;
	}
	init(N);
	dfs(N,V);
	cout << '\n';
	init(N);
	bfs(N,V);

	return 0;
}