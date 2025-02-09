class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());
        int n=strs.size();
        int l=min(strs[0].size(),strs[n-1].size());
        string ans="";
        for(int i=0;i<l;i++){
            if(strs[0][i]==strs[n-1][i]){
                ans=ans+strs[0][i];
            }
            else{
                break;
            }
        }
        return ans;
    }
};