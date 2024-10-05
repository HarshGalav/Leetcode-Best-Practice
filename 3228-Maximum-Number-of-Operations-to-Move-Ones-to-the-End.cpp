class Solution {
public:
    int maxOperations(string s) {
        int n=s.length();
        int i=0;
        int oness=0;
        int ans=0;
        vector<int>v;
        int flag=0;
        while(i<n){
            if(s[i]=='1'){
                oness++;
                flag=1;
            }
            if(s[i]=='0' && flag==1){
                ans=ans+oness;
                flag=0;
            }
        i++;
        }
        return ans;
    }
};