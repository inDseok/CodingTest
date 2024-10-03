#include <iostream>
#include <algorithm>
using namespace std;
char arr[201][201];
int bumb[201][201];
int n,k;
int dy[5]={-1,0,1,0,0};
int dx[5]={0,1,0,-1,0};
int main() {
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>arr[i][j];
			bumb[i][j]=0;
		}
	}
	while(k--){
		int y,x;
		cin>>y>>x;
		for(int i=0;i<5;i++){
			int yy=y+dy[i];
			int xx=x+dx[i];
			if(yy>0&&yy<=n&&xx>0&&xx<=n){
				if(arr[yy][xx]=='0'){
					bumb[yy][xx]+=1;
				}
				else if(arr[yy][xx]=='#'){
					continue;
				}
				else if(arr[yy][xx]=='@'){
					bumb[yy][xx]+=2;
				}
			}
		}
	}
	int maxnum=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			maxnum=max(maxnum,bumb[i][j]);
		}
	}
	cout<<maxnum;
	return 0;
}