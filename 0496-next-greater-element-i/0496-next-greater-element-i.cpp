class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int>v(nums2.size(),-1);
        stack<int>st;
        int n2=nums2.size();
        for(int i=n2-1;i>=0;i--){
            
                while(!st.empty() &&st.top()<=nums2[i] ){
                    st.pop();
                }
            
            if(!st.empty()){
                v[i]=st.top();
            }
            st.push(nums2[i]);
        }
        vector<int>ans(nums1.size());
        for(int i=0;i<nums1.size();i++){
            for(int j=0;j<nums2.size();j++){
                if(nums1[i]==nums2[j]){
                    ans[i]=(v[j]);
                    break;
                }
            }
        }
        return ans;
    }
};