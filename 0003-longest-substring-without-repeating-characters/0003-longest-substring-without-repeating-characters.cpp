class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>mp;
        int left=0,right=0,maxi=0;
        for(;right<s.size();right++){
            if(mp.find(s[right])!=mp.end()){
                left = max(left, mp[s[right]] + 1);;
            }
            mp[s[right]]=right;
            maxi=max(right-left+1,maxi);
        }
        return maxi;
    }
};