#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <queue>

// 限制是所有边都是非负值， 图中可能存在重边和自环
using namespace std;
typedef pair<int, int> PII;

const int N = 150010;
int h[N], e[N], ne[N], idx;
int w[N];
int dist[N];
bool st[N];

int n, m;
void add(int a, int b, int c){
    w[idx] = c;
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}

int dijstra(){
    memset(dist, 0x3f, sizeof(dist));
    dist[1] = 0;
    priority_queue<PII, vector<PII>, greater<PII>> heap;
    heap.push({0, 1});
    while(heap.size()){
        PII k = heap.top();
        heap.pop();
        int ver = k.second, distance = k.first;
        
        if(st[ver]){
            continue;
        }
        st[ver] = true;
        for(int i = h[ver]; i != -1; i = ne[i]){
            int j = e[i]; 
            if(dist[j] > distance + w[i]){
                dist[j] = distance + w[i];
                heap.push({dist[j], j});
            }
        }
    }
    if(dist[n] == 0x3f3f3f3f){
        return -1;
    }
    return dist[n];
}

int main(){
    memset(h, -1, sizeof(h));
    cin >> n >> m;
    
    while(m--){
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b , c);
    }
    
    cout << dijstra() << endl;
    
    return 0;
}

