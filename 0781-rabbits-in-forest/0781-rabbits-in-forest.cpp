class Solution {
public:
    int numRabbits(vector<int>& answers) {
        if(answers.size()==0){
            return 0;
        }
        unordered_map<int,int>mp;
        int ans=0;
        for(int a:answers){
            if(a==0){
                ans++;
            }
            else{
                if(mp[a]==0){
                    ans+=a+1;
                }
                mp[a]++;
                if(mp[a]==a+1){
                    mp[a]=0;
                }
            }
           
        }
         return ans;
    }
};