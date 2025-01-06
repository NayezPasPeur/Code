#include <iostream>

using namespace std;
const int N = 20;
int n;
// vector<vector<char>> map(N, vector<char>(N));
char g[N][N];
bool col[N], dg[N * 2], udg[N * 2]; 


void dfs(int u){
    if(u == n){
        for(int i = 0; i < n; i++){
            puts(g[i]);
        }
        puts("");
    }
    
    // 遍历各个点
    // u表示的其实就是对应的行
    for(int i = 0 ; i < n; i++){
        // 这里的对应关系怎么计算的
        // i代表的是当前列。dg表示的是是在y轴上的截距 y = x + b, b = y - x 为了防止坐标负值， b = y - x + n -> i - u + n
        // y = -x + b   b = y + x -> i + u
        if(!col[i] && !dg[u + i] && !udg[n - u + i]){
            g[u][i] = 'Q';
            col[i] = dg[u + i] = udg[n - u + i] = true;
            dfs(u + 1);
            col[i] = dg[u + i] = udg[n - u + i] = false;
            g[u][i] = '.';
        }
    }
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            g[i][j] = '.';
        }
    }
    
    dfs(0);
    
    return 0;
    
    
}