class Solution {
public:
    bool check(unordered_map<int,int>& mp){
        for(auto& i : mp){
            if(i.second > 1){
                return false;
            }
        }
        return true;
    }

    int minimumOperations(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int num : nums){
            mp[num]++;
        }

        if(check(mp)) return 0;

        int ans = 0;
        int cnt = 0;
        int n = nums.size();

        for(int i = 0; i < n; i++){
            mp[nums[i]]--;
            cnt++;

            if(cnt == 3){
                ans++;
                cnt = 0;
                if(check(mp)){
                    return ans;
                }
            }
        }

        if(cnt > 0) ans++;

        return ans;
    }
};
