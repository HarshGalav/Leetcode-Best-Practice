class Solution {
public:
    int f2(int mid,vector<int>& weights){
        int cnt=0;
        int total=0;
        for(auto i:weights){
            if(i+total <= mid){
                total=total+i;
            }
            else{
                cnt++;
                total=i;
            }
        }
        return cnt+1;
    }
    int f(int l,int r, vector<int>& weights, int days){
        int ans=-1;
        while(l<=r){
        int mid=(l+r)/2;
        int cal=f2(mid,weights);
        
        
        if(cal <=days){
            ans=mid;
            r=mid-1;
        }
        else{
            l=mid+1;
        }
        }
        return ans;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int maxi=*max_element(weights.begin(),weights.end());
        int sum=0;
        for(auto i:weights){
            sum+=i;
        }
        return f(maxi,sum,weights,days);
    }
};