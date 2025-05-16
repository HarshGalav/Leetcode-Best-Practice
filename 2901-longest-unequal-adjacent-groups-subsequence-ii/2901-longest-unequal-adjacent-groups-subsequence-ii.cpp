class Solution {
public:
    int f(string a,string b){
        int r=0;
        int n=min(a.size(),b.size());
        for(int i=0;i<n;i++){
            if(a[i]!=b[i]){
                r++;
            }
        }
        return r;
    }
    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n=words.size();
        vector<int>parent(n,-1);
        vector<int>dp(n,1);
        vector<string>ans;

        int longest=-1;
        int longestidx=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(groups[j]!=groups[i] && f(words[i],words[j])==1 && words[i].length()==words[j].length()){
                    if(dp[i]+1>dp[j]){
                        dp[i]=dp[j]+1;
                        parent[i]=j;
                       
                        
                    }
                }
            }
            if(dp[i]>longest){
                            longest=dp[i];
                            longestidx=i;
                        }
        }
        while(longestidx!=-1){
            ans.push_back(words[longestidx]);
            longestidx=parent[longestidx];
            
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};