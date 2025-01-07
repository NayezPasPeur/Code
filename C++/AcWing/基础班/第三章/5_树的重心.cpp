#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
const int N = 1e5 + 10, M = 2 * N;

int n, m;


int h[N], e[M], ne[M], idx;

bool st[N];

int ans = N;

// 在a对应的单链表中插入b
// 怎么插入的呢？
void add(int a, int b){
    e[idx] = b;  // 表示idx条边指向b
    ne[idx] = h[a]; // 表示idx条边的下一条边指向 a点的临接链表的第一条边
    h[a] = idx++; // 表示 a点的邻接链表的第一条边是 idx
}


int dfs(int u){
    st[u] = true;  // 标记一下， 当前这个点已经被搜索过

    int sum = 1;  // 记录当前子树大小
    int res = 0;  // 把u这个点删除之后， 每一个联通块的最大值
    // 遍历当前点对应链表的邻接链表
    for (int i = h[u]; i != -1; i = ne[i]) {
        int j = e[i];  // 当前这个链表中的节点， 对应图中的点的编号是多少
        if (!st[j]) {
            int s = dfs(j);     // j这棵子树的大小
            res = max(res, s);  //最大的联通块大小
            sum += s;
        }
    }
    res = max(res, n - sum);
    ans = min(ans, res);
    
    return sum;

}

int main(){
    memset(h, -1, sizeof(h));
    cin >> n;
    
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        add(a, b);
        add(b, a);
    }
    dfs(1);
    
    cout << ans << endl;
    
    return 0;
    
}