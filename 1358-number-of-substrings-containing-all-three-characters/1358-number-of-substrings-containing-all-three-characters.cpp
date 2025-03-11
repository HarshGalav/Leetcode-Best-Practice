class Solution {
public:
    int numberOfSubstrings(string s) {
        unordered_map<char,int>mp;
        int i=0,j=0,cnt=0;
        int n=s.size();
        while(j<n && i<n){
            mp[s[j]]++;
            if(mp.size()==3){
                while(mp.size()==3){
                    cnt+=n-j;
                    mp[s[i]]--;
                    if(mp[s[i]]==0){
                        mp.erase(s[i]);
                    }
                    i++;
                }
            }
            j++;
        }
        return cnt;
    }
};