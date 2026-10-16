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

int knapsack01(vector<int> & value, vector<int>& costs , int w){
    int a[value.size()+1][w+1];
    for (int i = 0 ;i<w+1 ;i++){
        a[0][i] = 0;
    }
    for (int i =0  ;i<value.size()+1; i++){
        a[i][0] = 0;
    }
    for (int i = 1 ;i<value.size()+1 ;i++){
        for (int j = 1 ;j<w+1 and j < costs[i-1] ; j++){
            a[i][j] = a[i-1][j];
        }
        for (int j = costs[i-1] ;j<=w ;j++){
            a[i][j] = max( a[i-1][j], value[i-1]+ a[i-1][j-costs[i-1]]);
        }
    }
    return a[value.size()][w];
}

void solve() {
    int n; cin >> n;
    int w; cin >> w;

    vector<int> costs, value; 
    for (int i = 0 ; i<n; i++) {
        int x ; cin >> x;
        costs.push_back(x);
    }
    for (int i = 0 ; i<n; i++) {
        int x ; cin >> x;
        value.push_back(x);
    }
    cout << knapsack01(value, costs, w) << endl;
}


int main() {
    ios::sync_with_stdio(false);  // faster I/O
    cin.tie(nullptr);

    // int n; cin >> n; while (n--)
    solve();

    return 0;
}
