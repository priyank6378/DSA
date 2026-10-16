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
    vector<vector<long>> a(n, vector<long>(n, 0));
    vector<string> b;
    for (int i = 0 ; i<n; i++){
        for (int j = 0; j<n; j++){
            string s;
            cin >> s;
            b.push_back(s);
        }
    }
    for (int i = 0 ; i<1; i++){
        for (int j = 0; j<n; j++){
            if (b[i][j] == '.') {
                a[i][j] = 1;
            }
            else {
                break;
            }
        }
    }

    for (int j = 0 ; j<1; j++){
        for (int i = 0; i<n; i++){
            if (b[i][j] == '.') {
                a[i][j] = 1;
            }
            else {
                break;
            }
        }
    }

    for (int i = 1 ; i<n; i++){
        for (int j = 1; j<n; j++){
            char c = b[i][j];
            if (b[i][j] == '.') {
                a[i][j] = a[i-1][j] + a[i][j-1];
                a[i][j] %= MOD;
            }
        }
    }
    cout << a[n-1][n-1] << endl;   
 
}


int main() {
    ios::sync_with_stdio(false);  // faster I/O
    cin.tie(nullptr);

    // int n; cin >> n; while (n--)
    solve();

    return 0;
}
