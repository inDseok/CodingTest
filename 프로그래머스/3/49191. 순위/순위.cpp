#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    vector<vector<bool>> rank(n+1,vector<bool>(n+1,false));
    for(int i=0;i<results.size();i++){
        rank[results[i][0]][results[i][1]]=1;
    }
    for(int via=1;via<=n;via++){
        for(int from=1;from<=n;from++){
            for(int to=1;to<=n;to++){
                if(rank[from][via]==true&&rank[via][to]==true)
                    rank[from][to]=true;
            }
        }
    }
    for(int i=1;i<=n;i++){
        int cnt=0;
        for(int j=1;j<=n;j++){
            if(i==j)
                continue;
            if(rank[i][j]||rank[j][i])
                cnt++;
            if(cnt==n-1)
                answer++;
        }
    }
    return answer;
}