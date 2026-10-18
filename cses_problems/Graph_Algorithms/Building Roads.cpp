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

void fill_island(vector<vector<int>> &g, int v, vector<int> &visited) {
    if (visited[v]) return ;
    visited[v] = 1;
    for (auto u: g[v]) {
        fill_island(g, u, visited);
    }
}

void solve() {
    int n; cin >> n;
    int m; cin >> m;

    vector<vector<int>> g(n);
    for (int i = 0 ; i<m; i++){
        int a,b; cin >> a >> b;
        a--;b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    vector<int> visited(n, 0);
    vector<int> ans;
    for (int i = 0 ; i<n; i++){
        if (visited[i] == 0){
            ans.push_back(i+1);
            fill_island(g,i,visited);
        }
    }
    cout << ans.size() - 1 << endl; 
    for (int i = 1; i<ans.size() ; i++){
        cout << ans[i-1] << ' ' << ans[i] << endl; 
    }
}

int main() {
    ios::sync_with_stdio(false);  // faster I/O
    cin.tie(nullptr);

    // int n; cin >> n; while (n--)
    solve();

    return 0;
}
