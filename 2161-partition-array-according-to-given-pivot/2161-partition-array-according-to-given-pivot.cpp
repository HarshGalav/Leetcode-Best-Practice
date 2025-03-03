class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n=nums.size();
        vector<int>f,s,t,ans;

       for(auto i:nums){
        if(i<pivot){
            f.push_back(i);
        }
        else if(i==pivot){
            s.push_back(i);
        }
        else{
            t.push_back(i);
        }
       }
       for(auto i:f){
        ans.push_back(i);
       }
       for(auto i:s){
        ans.push_back(i);
       }
       for(auto i:t){
        ans.push_back(i);
       }
       return ans;
    }
};