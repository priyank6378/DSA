#include <iostream>
#include <vector>  
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
#include <climits>

using namespace std;

const long long MOD = 1e9 + 7;


void solve() {
    int n; cin >> n;
    int m; cin >> m;
 
    vector<vector<pair<int,int>>> a(n+1);
    vector<long long> distance(n+1, LONG_MAX);
    vector<int> visited(n+1, 0);

    distance[1] = 0;

    for (int i = 0; i<m; i++){
        int x, y; cin >> x >> y;
        int z ; cin >> z;
        a[x].push_back({y,z});
    } 

    priority_queue<pair<long, int>> q;
    q.push({0, 1});
    while (!q.empty()){
        auto tmp = q.top();
        long long dis = -tmp.first;
        int u = tmp.second;
        q.pop();
        if (visited[u]) {
            continue;
        }
        for (auto v: a[u]) {
            if (distance[v.first] > dis + v.second)
            {
                distance[v.first] =  dis + v.second;
                q.push({-dis - v.second , v.first});
            }
        }
        visited[u] = 1;
    }
    for (int i = 1; i<=n; i++) cout << distance[i] << ' ' ; cout << endl; 
    
 
}


int main() {
    ios::sync_with_stdio(false);  // faster I/O
    cin.tie(nullptr);

    // int n; cin >> n; while (n--)
    solve();

    return 0;
}
