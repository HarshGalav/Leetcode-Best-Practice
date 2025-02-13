class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long,vector<long long>,greater<long long>>mh(nums.begin(),nums.end());
        
        int n=0;
        while(mh.top()<k){
            long long n1=mh.top();
            mh.pop();
            long long n2=mh.top();
            mh.pop();
            mh.push((min(n1,n2)*2)+max(n1,n2));
            n++;
        }
        return n;
    }
};