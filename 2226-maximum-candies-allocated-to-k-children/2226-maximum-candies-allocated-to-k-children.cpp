class Solution {
public:
    bool f(long long mid,vector<int>& candies, long long k){
        long long temp=0;
        for(auto i:candies){
            temp=temp+i/mid;
        }
        if(temp>=k){
            return true;
        }
        return false;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        long long l=1,r=*max_element(candies.begin(),candies.end());
        long long result=0;
        sort(candies.begin(),candies.end());
        while(l<=r){
            long long mid=l-(l-r)/2;
            if(f(mid,candies,k)){
                result=mid;
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        return result;
    }
};