class Solution {
public:
    vector<string> createGrid(int m, int n) {
        int t = m;
        m = n;
        n = t;
        vector<string> ans;
        string s ;
        for (int i = 0 ; i<m; i++) s += '.';
        ans.push_back(s);
        for (int i = 1; i<n; i++){
            string x; 
            for (int j = 0 ; j<m-1; j++) x += "#";
            x  += '.';
            ans.push_back(x);
        }      
        return ans;
    }
};