class Solution {
public:
    vector<vector<int>> t;
    int solve(int l,int r,string& s) {
        if(l==r) return 1;
        else if(l>r) return 0;

        if(t[l][r] != -1) return t[l][r];

        int i=l+1;
        while(i<=r && s[i]==s[l]) i++;
        if(i==r+1) return 1;

        int ans1=1+solve(i,r,s);
        
        int ans2=INT_MAX;
        for(int j=i;j<=r;j++) {
            if(s[l]==s[j]) {
                int x = solve(i,j-1,s) + solve(j,r,s);
                ans2=min(ans2,x);
            }
        }
        return t[l][r] = min(ans1,ans2);

    }
    int strangePrinter(string s) {
        int n =  s.length();
        t.resize(n,vector<int>(n+1,-1));
        return solve(0,n-1,s);
    }
};