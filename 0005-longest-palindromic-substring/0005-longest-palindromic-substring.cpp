class Solution {
public:
vector<vector<int>>dp;
    bool isp(int i,int j,string &s){
        if(i >= j){
            return true;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==s[j]){
           return dp[i][j]= isp(i+1,j-1,s);
        }
        return false;
    }
    string longestPalindrome(string s) {
        int n=s.size();
        dp.assign(n,vector<int>(n,-1));
        int l=INT_MIN;
        int st=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isp(i,j,s)){
                    if(l<j-i+1){
                        st=i;
                        l=j-i+1;
                    }
                }
            }
        }
        return s.substr(st,l);

    }
};