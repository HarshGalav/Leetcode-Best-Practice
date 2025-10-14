class Solution {
public:
    int f(int idx,string &s,vector<int>&dp){
        if(idx==s.size()){
            return 1;
        }
        if(s[idx]=='0') return 0;
        if (dp[idx] != -1) return dp[idx];
        
        int take_one=f(idx+1,s,dp);
        int take_two=0;
        if(idx+1<s.size()){
            int num=(s[idx]-'0')*10 +(s[idx+1]-'0');
            if(num>=10 && num <=26){
                take_two=f(idx+2,s,dp);
            }
        }
        return dp[idx]=take_one+take_two;

    }
    int numDecodings(string s) {
        int n=s.size();
        vector<int>dp(n,-1);
        return f(0,s,dp);
    }
};