class Solution {
public:
    vector<int> diStringMatch(string s) {
        int n=s.length();
        vector<int> ans;
        vector<int>temp;
        for(int i=0;i<=n;i++){
            temp.push_back(i);
        }
        int l=0,r=n;
        for(int i=0;i<n;i++){
            if(s[i]=='I'){
                ans.push_back(temp[l]);
                l++;
            }
            else{
                ans.push_back(temp[r]);
                r--;
            }
        }
        ans.push_back(temp[l]);
        return ans;

    }
};