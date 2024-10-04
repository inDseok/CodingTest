#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;
vector<int> vec[1001];
int dist[1001];
int main() {
	int n,m,s,e;
	cin>>n>>m>>s>>e;
	for(int i=0;i<m;i++){
		int u,v;
		cin>>u>>v;
		vec[u].push_back(v);
		vec[v].push_back(u);
	}
	for(int i=1;i<=n;i++){
		dist[i]=-1;
	}
	for(int k=1;k<=n;k++){
		if (s == k) {
				cout << "-1\n";
				continue;
		}
		memset(dist,-1,sizeof(dist));
		queue<int> q;
		q.push(s);
		dist[s]=1;
		while(!q.empty()){
			int cur=q.front();
			q.pop();
			for(int i=0;i<vec[cur].size();i++){
				int next=vec[cur][i];
				if(next==k)
					continue;
				if(dist[next]==-1){
					dist[next]=dist[cur]+1;
					q.push(next);
				}
			}
		}
		if(dist[e]==-1)
			cout<<"-1\n";
		else{
			cout<<dist[e]<<"\n";
		}
	}
}