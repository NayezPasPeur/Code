#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;


const int N = 100010;

int n, m;
int h[N], e[N], ne[N], idx;
int d[N];

void add(int a, int b){
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}

int bfs(){
    memset(d, -1, sizeof d);
    queue<int> q;
    d[1] = 0;
    q.push(1);
    
    while(q.size()){
        int t = q.front();
        q.pop();
        
        
        for(int i = h[t]; i != -1; i = ne[i]){
            int j = e[i]; //向前走一步
            if(d[j] == -1){ // 没有被遍历过
                d[j] = d[t] + 1;
                q.push(j);
            }
        }
    }
    return d[n];
}

int main(){
    // cin >> n >> m;
    scanf("%d%d", &n, &m);

    memset(h, -1, sizeof h);
    for(int i = 0; i < m; i++){
        int a, b;
        // cin >> a >> b;
        scanf("%d%d", &a, &b);

        add(a, b); // 有向边
        
    }
    cout << bfs() << endl;
    
    return 0;
    
}


