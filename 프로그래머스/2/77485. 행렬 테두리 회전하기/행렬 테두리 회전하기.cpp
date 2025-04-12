#include <string>
#include <vector>

using namespace std;
int arr[101][101];
int rotate(int sy,int sx, int ey,int ex){
    int temp=arr[sy][sx];
    int min=temp;
    for(int i=sy;i<ey;i++){ //위
        arr[i][sx]=arr[i+1][sx];
        if(min>arr[i][sx])
            min=arr[i][sx];
    }
    for(int j=sx;j<ex;j++){ //왼
        arr[ey][j]=arr[ey][j+1];
        if(min>arr[ey][j])
            min=arr[ey][j];
    }
    for(int i=ey;i>sy;i--){ //아래
        arr[i][ex]=arr[i-1][ex];
        if(min>arr[i][ex])
            min=arr[i][ex];
    }
    for(int j=ex;j>sx;j--){ //오른
        arr[sy][j]=arr[sy][j-1];
        if(min>arr[sy][j])
            min=arr[sy][j];
    }
    arr[sy][sx+1]=temp;
    return min;
}
vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    int cnt=1;
    for(int i=1;i<=rows;i++){
        for(int j=1;j<=columns;j++){
            arr[i][j]=cnt;
            cnt++;
        }
    }
    for(int i=0;i<queries.size();i++){
        answer.push_back(rotate(queries[i][0],queries[i][1],queries[i][2],queries[i][3]));
    }
    return answer;
}