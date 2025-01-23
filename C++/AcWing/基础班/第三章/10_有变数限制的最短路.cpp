#include <bits/stdc++.h>
using namespace std;

const int N = 100010;
int dist[N], backup[N];
int k, n, m;
struct edge{
    int a;
    int b;
    int w;
}edge[N];

int bellman_ford(){
    memset(dist, 0x3f, sizeof(dist));
    dist[1] = 0;
    for(int i = 1; i <= k; i++){
        // 最多有k条边
        memcpy(backup, dist, sizeof(dist));
        
        for(int j = 1; j <= m; j++){
            // 遍历m条边
            int a = edge[j].a;
            int b = edge[j].b;
            int w = edge[j].w;
            
            dist[b] = min(dist[b], backup[a] + w);
        }
    }
    return dist[n];
}

int main(){
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        edge[i].a = a;
        edge[i].b = b;
        edge[i].w = c;
    }
    int t = bellman_ford();
    
    if(t >= 0x3f3f3f3f /2  ){
        puts("impossible");
    }else{
        cout << t << endl;
    }
    
    return 0;
}
