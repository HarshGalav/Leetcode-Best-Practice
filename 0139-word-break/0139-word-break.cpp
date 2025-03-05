class Solution {
public:
    unordered_set<string>st;
    int t[301];
    bool f(int ind,string s){
        if(ind==s.size()){
            return true;
        }
        if(st.count(s)){
            return true;
        }
        if(t[ind]!=-1) return t[ind];
        for(int i=1;i<=s.size();i++){
            string temp=s.substr(ind,i);
            if(st.count(temp)&& f(ind+i,s)){
                return t[ind]= true;
            }
        }
        return t[ind]= false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        memset(t,-1,sizeof(t));
        for(auto i:wordDict){
            st.insert(i);
        }
        return f(0,s);
    }
};