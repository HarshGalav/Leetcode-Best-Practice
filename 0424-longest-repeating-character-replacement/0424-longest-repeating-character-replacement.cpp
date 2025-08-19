class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int>mp;
        int ans=0;
        int i=0,j=0;
        int n=s.size();
        int maxf=0;
        while(j<n){
            mp[s[j]]++;
            maxf=max(maxf,mp[s[j]]);

            if((j-i+1)-maxf>k){
                mp[s[i]]--;
                i++;
            }
            else{
                ans=max(ans,j-i+1);
            }

            j++;
        }
        return ans;
    }
};