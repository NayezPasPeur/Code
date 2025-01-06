#include <iostream>
#include <queue>
#include <cstring>

using namespace std;
const int N = 110, M = 110;
int n, m;
typedef pair<int, int> PII;
int g[N][M], d[N][M];
queue<PII> q;

int bfs(){
    memset(d, -1, sizeof(d));
    
    d[0][0] = 0;
    q.push({0, 0});
    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
    while(!q.empty()){
        PII t = q.front();
        q.pop();
        for(int i = 0; i < 4; i++){
            int a = t.first + dx[i], b = t.second + dy[i];
            if(a >= 0 && a < n && b >= 0 && b < m && g[a][b] ==0 && d[a][b] == -1){
                d[a][b] = d[t.first][t.second] + 1;
                q.push({a, b});
            }
        }
    }
    return d[n-1][m-1];
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> g[i][j];
        }
    }
    cout << bfs() << endl;
    
    return 0;
    
}