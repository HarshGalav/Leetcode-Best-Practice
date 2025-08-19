class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0,r=0,maxlen=0;
        unordered_set<char>mp;
        for(r=0;r<s.length();r++){
            while(mp.count(s[r])){
                mp.erase(s[l]);
                l++;
            }
            mp.insert(s[r]);
            maxlen=max(maxlen,r-l+1);
        }
        return maxlen;
    }
};