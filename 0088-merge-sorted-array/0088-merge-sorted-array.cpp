class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int>ar;

        for(int i=0;i<max(m,n);i++){
            if(m>n && i>=n){
                ar.push_back(nums1[i]);
            }
            else if(n>m && i>=m){
                ar.push_back(nums2[i]);
            }
            else{
                ar.push_back(nums1[i]);
                ar.push_back(nums2[i]);
            }
            
        }
        sort(ar.begin(),ar.end());
        nums1=ar;
        
    }
};