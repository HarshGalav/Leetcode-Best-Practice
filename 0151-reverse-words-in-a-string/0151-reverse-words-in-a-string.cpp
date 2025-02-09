class Solution {
public:
    string reverseWords(string s) {
        int n=s.size();
        string ans="";
        string word;
        stringstream ss(s);
        while(ss>>word){
            if(!ans.empty()){
                ans=" "+ans;
            }
            ans=word+ans;
        }
        return ans;
    }
};