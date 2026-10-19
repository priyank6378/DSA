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
 
    vector<vector<int>> a(n+1);
    vector<int> visited(n+1, 0), previous(n+1, 0);
    previous[1] = -1;

    int start = 1, end = n;
    for (int i = 0; i<m; i++){
        int x, y; cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    } 
 
    queue<int> q;
    q.push(start);
    vector<int> ans; 
    while (!q.empty()){
        int cur = q.front();

        q.pop();
        
        if (visited[cur]) continue;
        
        visited[cur] = 1;
        if (cur == end) {
            int y = cur;
            while (y != -1) {
                ans.push_back(y);
                y = previous[y];
            }
            reverse(ans.begin(), ans.end());
            break;
        }

        for (auto u : a[cur]){
            if (previous[u] == 0) 
                previous[u] = cur;
            q.push(u);
        }
    }
 
    if (ans.size()) {
        cout << ans.size() << endl; 
        for (auto i: ans) cout << i << ' ' ;
        cout << endl; 
    }
    else {
        cout << "IMPOSSIBLE" << endl; 
    }
 
}


int main() {
    ios::sync_with_stdio(false);  // faster I/O
    cin.tie(nullptr);

    // int n; cin >> n; while (n--)
    solve();

    return 0;
}
