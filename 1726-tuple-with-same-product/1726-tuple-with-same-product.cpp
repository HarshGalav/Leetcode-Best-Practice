class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
   int cnt=0;
   int n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=n-1;j>i;j--){
                int p=nums[i]*nums[j];
                unordered_set<int>s;
                
                for(int k=i+1;k<j;k++){
                    if(p%nums[k]==0){
                        int l=p/nums[k];
                    
                    if(s.count(l)){
                        cnt++;
                    }
                    s.insert(nums[k]);
                    }
                    
                }
            }
        }
        return (cnt)*8;
    }
};