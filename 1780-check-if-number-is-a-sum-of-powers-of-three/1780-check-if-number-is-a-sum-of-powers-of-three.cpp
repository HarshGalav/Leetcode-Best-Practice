class Solution {
public:
    unordered_map<int,int>mp;
    bool checkPowersOfThree(int n) {
       while(n>0){
        int temp=1;
        while(temp*3<=n){
            temp=temp*3;

        }
        
        
       
        n=n-temp;
        mp[temp]++;       
        if(n<0) return false;
       }
       for(auto i:mp){
        if(i.second>1){
            return false;
        }
       }
      return true;
    }
};