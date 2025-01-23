#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 510, M = 100010;

int h[N], e[M], ne[M], w[M], idx; //邻接表存储图
int state[N]; // state 记录是否找到了原点到该节点的最短聚类
int dist[N]; // dist 数组保存源点到其余哥哥节点的距离
int n, m;

void add(int a, int b , int c){
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

void Dijkstra(){
    memset(dist, 0x3f, sizeof(dist)); // dist 数组的各个元素为无穷大
    dist[1] = 0; // 源点到源点的距离设置为0
    for(int i = 0; i < n; i++){
        int t = -1;
        for(int j = 1; j <= n; j++) { // 遍历dist数组， 找到没有确定最短路径的节点中距离源点最近的点t
            if(!state[j] && (t == -1 || dist[j] < dist[t])){
                t = j;
            }
            
        }
        state[t] = 1; // 表示当前点t被访问了
        for(int j = h[t]; j != -1; j = ne[j]){ // 遍历t所有可以到达的节点i
            int i = e[j];
            dist[i] = min(dist[i], dist[t] + w[j]);
        }
        
    }
    
}

int main(){
    memset(h, -1, sizeof(h)); // 邻接表初始化
    
    cin >> n >> m;
    
    while(m--){ // 读入m条边
        int a, b, w;
        cin >> a >> b >> w;
        add(a, b, w);
    }
    Dijkstra();
    if(dist[n] != 0x3f3f3f3f){
        cout << dist[n];
    }else{
        cout << "-1";
    }
    
    return 0;
    
    
}

