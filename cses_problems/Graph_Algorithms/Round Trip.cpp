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

int impossible = 1;
vector<int> ans ; 

void find_loop_with_3_or_more_nodes(vector<vector<int>> &g, vector<int> &visited, int u, int prev) {
    // for (auto i: ans) cout << i << ' ' ; cout << endl; 
    if (impossible == 0) return; 
    if (ans.size() >= 3 and visited[u]) {
        impossible = 0;
        return ;
    }
    visited[u] = 1;
    for (auto v : g[u]) {
        if (impossible == 0) return;

        if (v != prev) {
        ans.push_back(v);
        find_loop_with_3_or_more_nodes(g, visited, v, u);
        if (impossible) ans.pop_back(); }
    }
}

void solve() {
    int n; cin >> n;
    int m; cin >> m;
 
    vector<vector<int>> a(n+1);
    vector<int> visited(n+1, 0);

    int start = 1, end = n;
    for (int i = 0; i<m; i++){
        int x, y; cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    } 
 
    for (int i = 1; i<=n;  i++){
        if (visited[i] == 0)  {
            ans.push_back(i);
            find_loop_with_3_or_more_nodes(a, visited, i, -1);
            if (impossible) ans.pop_back();
        }
        if (impossible == 0) {
            break;
        }
    }

    if (impossible) {
        cout << "IMPOSSIBLE" << endl;
    }
    else {
        int i = 0;
        while (ans[ans.size()-1] != ans[i]) i++;
        cout << ans.size() - i << endl; 
        while (i< ans.size()) cout << ans[i++] << ' ' ; cout  << endl; 
    }

 
}


int main() {
    ios::sync_with_stdio(false);  // faster I/O
    cin.tie(nullptr);

    // int n; cin >> n; while (n--)
    solve();

    return 0;
}
