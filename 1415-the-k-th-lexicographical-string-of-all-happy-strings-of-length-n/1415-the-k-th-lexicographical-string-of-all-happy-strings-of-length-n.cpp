class Solution {
public:
    string ans;
    void f(int ind,vector<char>&v,string &s,int& k,int n){
        if(ind==n){
            if(--k==0){
                ans=s;
            }
            return;
        }
        for(int i=0;i<3;i++){
            if(ind ==0 || v[i]!=s.back()){
                s.push_back(v[i]);
                f(ind+1,v,s,k,n);
                s.pop_back();
                if(k==0){
                    return ;
                }
            }
        }
        
    }
    string getHappyString(int n, int k) {
        vector<char>v={'a','b','c'};
         ans="";
         string s;
        int cnt=0;
         f(0,v,s,k,n);
         return ans;
        
    }
};