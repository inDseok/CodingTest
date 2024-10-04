#include <iostream>
using namespace std;
int arr[501][501]={0};
int visited[501];
int result=1;
int n,m;
void dfs(int start){
	visited[start]=1;
	for(int i=1;i<=n;i++){
		if(i==start)
			continue;
		if(arr[start][i]==1&&!visited[i]){
			result++;
			dfs(i);
		}
	}
}
int main() {
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int u,v;
		cin>>u>>v;
		arr[u][v]=1;
		arr[v][u]=1;
	}
	dfs(1);
	cout<<result;
}