class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int>lmax(n);
        vector<int>rmax(n);
        lmax[0]=height[0];
        for(int i=1;i<n;i++){
            lmax[i]=max(lmax[i-1],height[i]);
        }
        rmax[n-1]=height[n-1];
        for(int i=n-2;i>=0;i--){
           rmax[i]=max(rmax[i+1],height[i]); 
        }
        vector<int>ans(n);
        int sol=0;
        for(int i=0;i<n;i++){
            ans[i]=min(rmax[i],lmax[i])-height[i];
            sol=sol+ans[i];
        }
    return sol;
    }
};