class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>temp;
        f(0,s,ans,temp);
        return ans;
    }
    void f(int ind,string s,vector<vector<string>>&ans,vector<string>&temp){
        if(ind ==s.size()){
            ans.push_back(temp);
            return;
        }
        for(int i=ind;i<s.size();i++){
            if(isp(s,ind,i)){
                temp.push_back(s.substr(ind,i-ind+1));
                f(i+1,s,ans,temp);
                temp.pop_back();
            }
        }
    }
    bool isp(string s,int start,int end){
        while(start<=end){
            if(s[start++] != s[end--]){
                return false;
            }
        }
        return true;
    }
};