#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
#include <unordered_map>

using namespace std;

int bfs(string start){
    string end = "12345678x";
    queue<string> q;
    unordered_map<string, int> d;
    int dx[4] = {0, 1, 0, -1}, dy[4] = {-1, 0, 1, 0};
    d[start] = 0;
    q.push(start);
    
    while(!q.empty()){
        string t = q.front();
        q.pop();
        int distance = d[t];
        int k = t.find('x');
        int x = k / 3, y = k % 3;
        
        if(t == end){
            return distance;
        }
        
        for(int i = 0; i < 4; i++){
            int a = x + dx[i], b = y + dy[i];
            if(a >= 0 && a < 3 && b >=0 && b < 3){
                swap(t[k], t[a * 3 + b]);
                if(!d.count(t)){
                    q.push(t);
                    d[t] = distance + 1;
                }
                // 恢复现场
                swap(t[k], t[a * 3 + b]);
            }
        }
        
        
    }
    return -1;
}

int main(){
    string c, start;
    for(int i = 0; i < 9; i++){
        cin >> c;
        start += c;
    }
    
    cout << bfs(start) << endl;
    
    return 0;
}