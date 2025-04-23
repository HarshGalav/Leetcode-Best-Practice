class Solution {
public:
    int countLargestGroup(int n) {
        unordered_map<int,int>mp;
        for(int i=1;i<=n;i++){
            int sum=0;
            int a=i;
            while(a!=0){
                sum=sum+a%10;
                a=a/10;
            }
            mp[sum]++;
        }
        int maxi=0;
        for(auto i:mp){
            maxi=max(maxi,i.second);
        }
        int ans=0;
        for(auto i:mp){
            if(i.second==maxi){
                ans++;
            }
        }
        return ans;
    }
};