class Solution {
public:
    int maximumSum(vector<int>& nums) {
        unordered_map<int,vector<int>>mp;
        for(auto i:nums){
            int temp=i;
            int sum=0;
            while(i!=0){
                sum=sum+i%10;
                i=i/10;
            }  
            mp[sum].push_back(temp);
        }
        int sum=0;
        int flag=0;
        for(auto i:mp){
            
            
            if(i.second.size()>1){
                sort(i.second.begin(),i.second.end());
            reverse(i.second.begin(),i.second.end());
                flag=1;
           
            sum=max(sum,i.second[0]+i.second[1]);
            }
            
        }
        if(flag==1){
            return sum;
        }
        return -1;

    }
};