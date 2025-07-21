class Solution {
public:
    string makeFancyString(string s) {
        string ans="";
        ans+=s[0];
        int cnt=1;

        for(int i=1;i<s.length();i++){
            if(s[i]==s[i-1]){
                cnt++;
                if(cnt<=2){
                    ans+=s[i];
                }
            }
            else{
                ans+=s[i];
                cnt=1;
            }
        }
        return ans;
    }
};