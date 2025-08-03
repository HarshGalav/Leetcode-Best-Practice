class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        unordered_map<int,int>mp;
        vector<int>finalv;
        int mini=INT_MAX;
        for(auto i:basket1){
            mp[i]++;
            mini=min(mini,i);
        }
        for(auto i:basket2){
            mp[i]--;
            mini=min(mini,i);
        }
        for(auto i:mp){
            int cnt=i.second;
            int cost=i.first;
            if(cnt==0){
                continue;
            }
            if(cnt%2!=0){
                return -1;
            }
            for(int j=1;j<=abs(cnt/2);j++){
                finalv.push_back(cost);
            }
        }
        sort(finalv.begin(),finalv.end());
        long long ans=0;
        for(int i=0;i<finalv.size()/2;i++){
            ans+=min(mini*2,finalv[i]);
        }
        return ans;
    }
};