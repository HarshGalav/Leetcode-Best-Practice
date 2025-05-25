class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string,int>mp;
        int cnt=0;
        int center=0;
        for(auto i:words){
            string rev=i;
            reverse(rev.begin(),rev.end());
            if(mp[rev]>0){
                mp[rev]--;
                cnt+=4;
            }
            else{
                mp[i]++;
            }
        }
        for (auto [word, freq] : mp) {
            if (word[0] == word[1] && freq > 0) {
                center = 2;
                break;
            }
        }
        return cnt+center;

    }
};