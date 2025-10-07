class Solution {
    private: bool f(int i,int oc,string &s, vector<vector<int>>& dp){
        if(i==s.size()) return (oc==0);

        if(dp[i][oc] != -1) return dp[i][oc];
        bool iv=false;
        if(s[i] =='*'){
            iv=iv|f(i+1,oc+1,s,dp);
            if(oc>0){
                iv=iv|f(i+1,oc-1,s,dp);
            }
            iv=iv|f(i+1,oc,s,dp);
        }
        else{
            if(s[i]=='('){
                iv=f(i+1,oc+1,s,dp);
            }
            else if(oc){
                iv=f(i+1,oc-1,s,dp);
            }
        }
        return dp[i][oc]=iv;
    }
public:
    bool checkValidString(string s) {
        int x=s.size();
        vector<vector<int>>dp(x,vector<int>(x,-1));
        return f(0,0,s,dp);    

    }
};