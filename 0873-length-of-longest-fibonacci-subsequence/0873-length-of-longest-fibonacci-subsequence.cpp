class Solution {
public:
    int f(int j,int k, vector<int>& arr,unordered_map<int,int>&mp){
        int target=arr[k]-arr[j];
        if(mp.count(target) && mp[target]<j){
            int i=mp[target];
            return f(i,j,arr,mp)+1;
        }
        return 2;
    }
    int lenLongestFibSubseq(vector<int>& arr) {
        int n=arr.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[arr[i]]=i;
        }
        int maxi=0;
        for(int j=1;j<n;j++){
            for(int k=j+1;k<n;k++){
                int len=f(j,k,arr,mp);
                if(len>=3){
                    maxi=max(maxi,len);
                }
            }
        }
        return maxi;
    }
};