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

struct node{
    int x; 
    int subs = 0;
    vector<node*> next;
};

int count_subs(node* cur) {
    if (cur->next.size() == 0) return 1;

    int subs = 0;
    for (auto n : cur->next) {
        subs += count_subs(n);
    }
    cur->subs = subs;
    return subs + 1;
}

void solve() {
    int n; cin >> n;
    // int m; cin >> m;
 
    vector<int> a;

    vector<node*> nodes(n+1, NULL);
    for (int i = 1; i<=n; i++) {
        nodes[i] = new node();
        nodes[i]->x = i;
    }
    for (int i = 0; i < n-1; i++){
        int x; cin >> x;
        int p = i+2;
        nodes[x]->next.push_back(nodes[p]);
    }

    count_subs(nodes[1]);
    for (int i = 1; i <= n; i++){
        cout << nodes[i]->subs << ' ' ;
    }
    cout << endl; 
}


int main() {
    ios::sync_with_stdio(false);  // faster I/O
    cin.tie(nullptr);

    // int n; cin >> n; while (n--)
    solve();

    return 0;
}
