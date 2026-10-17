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

void count_islands(vector<vector<int>> &g, int i, int j, vector<vector<int>> &visited) {
    if (i>=g.size() or i<0) return ;
    if (j>=g[0].size() or j<0) return ;
    if (visited[i][j] or g[i][j] == 0) return; 
    visited[i][j] = 1;
    count_islands(g, i+1, j, visited);
    count_islands(g, i-1, j, visited);
    count_islands(g, i, j-1, visited);
    count_islands(g, i, j+1, visited);
}

void solve() {
    int n; cin >> n;
    int m; cin >> m;

    vector<vector<int>> a(n, vector<int>(m, 0)), visited(n, vector<int>(m, 0));
    for (int i = 0; i<n; i++){
        string s; cin >> s;
        for (int j = 0 ; j<m; j++){
            if (s[j] == '.') {
                a[i][j] = 1;
            }
        }
    } 
    int ans = 0 ;
    for (int i = 0 ; i<n; i++){
        for (int j = 0 ; j<m; j++){
            if (visited[i][j] == 0 and a[i][j] == 1) {
                count_islands(a, i, j, visited);
                ans ++ ;
            }
        }
    }
    cout << ans << endl; 

}


int main() {
    ios::sync_with_stdio(false);  // faster I/O
    cin.tie(nullptr);

    // int n; cin >> n; while (n--)
    solve();

    return 0;
}
