class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n=arr.size();
        vector<long long>f(n);
        vector<long long>g(n);
        f[0]=arr[0];
        g[0]=0;
        long long ans=arr[0];
        for(int i=1;i<n;i++){
            f[i]=max(f[i-1]+arr[i],(long long)arr[i]);
            g[i]=max(f[i-1],g[i-1]+arr[i]);
            ans=max(ans,max(f[i],g[i]));
        }
        return ans;
    }
};
