class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>>mh;
        for(auto i:nums){
            mh.push(i);
        }
        int n=0;
        while(mh.top()<k){
            int n1=mh.top();
            mh.pop();
            int n2=mh.top();
            mh.pop();
            mh.push((min(n1,n2)*2)+max(n1,n2));
            n++;
        }
        return n;
    }
};