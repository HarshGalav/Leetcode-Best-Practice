class Solution {
public:
    long long numOfSubsequences(string s) {
        int n = s.size();
        vector<long long> suffix(n+1, 0);
        vector<long long> prefix(n+1, 0);
        
        for(int i=0; i<n; i++){
            if(s[i]=='L'){
                prefix[i+1]=1;
            }
            prefix[i+1]+=prefix[i];
        }
        for(int i=n-1; i>=0; i--){
            if(s[i]=='T'){
                suffix[i]=1;
            }
            suffix[i]+=suffix[i+1];
        }

        long long ans1 = 0, ans2 = 0,ans3=0,temp=0;

        for (int i = 0; i < n; i++) {
            if (s[i] == 'C') {
                ans1 += (prefix[i] + 1) * suffix[i];
                ans2 += prefix[i] * (suffix[i] + 1);
                ans3+=prefix[i]*suffix[i];
                
            }
            else{
                temp=max(temp,prefix[i]*suffix[i]);
            }
        }


        return max({ans1, ans2,ans3+temp});
    }
};
