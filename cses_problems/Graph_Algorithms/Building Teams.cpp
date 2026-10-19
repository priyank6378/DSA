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

int impossible = 0;

void find_even_loops(vector<vector<int>> &g, vector<int> &visited, vector<int> &part, int u, int prev) {
    if (impossible) return; 
    if (visited[u]) {
        return ;
    }
    visited[u] = 1;
    int cur_team = part[u];
    int next_team = 1;
    if (cur_team == 1) next_team++;
    for (auto v : g[u]) {
        if (impossible) return; 
        if (part[v] == 0) {
            part[v] = next_team;
            find_even_loops(g, visited, part, v, u);
        }
        else if (part[v] == cur_team) {
            impossible = 1;
        }
        else {
            part[v] = next_team;
        }
    }
}

void solve() {
    int n; cin >> n;
    int m; cin >> m;
 
    vector<vector<int>> a(n+1);
    vector<int> visited(n+1, 0), part(n+1, 0);
    part[0] = 1;

    int start = 1, end = n;
    for (int i = 0; i<m; i++){
        int x, y; cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    } 
 
    for (int i = 1; i<=n;  i++){
        if (visited[i] == 0)  {
            part[i] = 2;
            find_even_loops(a, visited, part, i, 0);
        }
        if (impossible) break;
    }

    if (impossible) {
        cout << "IMPOSSIBLE" << endl;
    }
    else {
        for (int i = 1; i<=n; i++) cout << part[i] << ' ' ; cout << endl; 
    }

 
}


int main() {
    ios::sync_with_stdio(false);  // faster I/O
    cin.tie(nullptr);

    // int n; cin >> n; while (n--)
    solve();

    return 0;
}
