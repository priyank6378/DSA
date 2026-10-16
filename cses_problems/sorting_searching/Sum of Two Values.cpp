#include <iostream>
#include <vector>  
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>

using namespace std;


void solve() {
    int n; cin >> n;

    int t; cin >> t; 

    map<int,int> m;
    
    int found = 0;
    int y,z;
    for (int i = 0 ; i<n; i++){
        int x ; cin >> x;
        if (m.find(t-x)!=m.end()) {
            y = m[t-x];
            z = i+1; 
            found = 1;
        }
        m[x] = i+1;

    }
    if (found) {
        cout << y << ' ' << z << endl; 
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
