#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 2 * (1e5 + 10);

int e[N], ne[N], idx;
int h[N];
int color[N]; // 保留各个点的颜色， 0 未染色 1 红色 2 黑色
int n, m; // 点和边
int add (int a, int b){
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}


bool dfs(int u, int c){
    color[u] = c; // u点染成c色
    
    for(int i = h[u]; i != -1; i = ne[i]){
        int b = e[i];
        if(!color[b]){
            if(!dfs(b, 3 - c)){
                return false;
            }
        }else if(color[b] != 3 - c){
            return false;
        }
    }
    return true;
    
}

int main(){
    memset(h, -1, sizeof(h));
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        add(a, b);
        add(b, a);
        
    }
    
    for(int i = 1; i <= n; i++){
        if(!color[i]){
            if(!dfs(i, 1)){
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;
    return 0;
    
}
