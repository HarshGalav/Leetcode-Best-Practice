class Solution {
public:
    long long maximumTotalSum(vector<int>& maximumHeight) {
       set<long long>s;
       int n=maximumHeight.size();
       sort(maximumHeight.begin(),maximumHeight.end(),greater<int>());
    long long ans=0;
       for(auto i:maximumHeight){
        if(s.find(i)!=s.end()){
            
            i=*s.begin()-1;
            if(i==0){
                return -1;
                
            }
        
        }
        ans=ans+i;
        s.insert(i);
        
       }
       return ans;

    }
};