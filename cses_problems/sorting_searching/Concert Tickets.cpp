#include <bits/stdc++.h>

using namespace std;


void solve() {
    int n,m; cin >> n >> m;

    multiset<int> a;
    for (int i = 0 ; i<n; i++){
        int x ; cin >> x;
        a.insert(x);
    }

    for (int i = 0 ; i<m; i++){
        int x ; cin >> x;
        auto y = a.lower_bound(x);
        if (y != a.end() and *y <= x) {
            cout << *y << endl;
            a.erase(y);
        }
        else {
            if (y != a.begin()) {
                y--;
                if (*y <= x) {
                    cout << *y << endl;
                    a.erase(y);
                }
            }   
            else {
                if (y!= a.end() and *y <= x) {
                    cout << *y << endl; 
                    a.erase(y);
                }
                else cout << -1 << endl; 
            }
        }
    }
    
}

int main() {
    ios::sync_with_stdio(false);  // faster I/O
    cin.tie(nullptr);
    
    // int n; cin >> n; 
    solve();


    return 0;
}
