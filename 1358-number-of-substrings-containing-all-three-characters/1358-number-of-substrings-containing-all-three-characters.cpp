class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.length();
        vector<int>cnt(3,0);
        int left=0,right=0,ans=0;
        for(right =0;right<n;right++){
            cnt[s[right]-'a']++;
            while(cnt[0]>0 && cnt[1]>0 && cnt[2] >0){
                ans+=(n-right);
                cnt[s[left]-'a']--;
                left++;
            }
        }
        return ans;
    }
};