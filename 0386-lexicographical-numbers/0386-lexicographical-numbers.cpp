class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int>ans;
        int x=min(9,n);
        for(int i=1;i<=x;i++){
            ans.push_back(i);
            if((i+9*i)<=n){
                for(int j=i+9*i;j<=min(9+i+(9*i),n);j++){
                    ans.push_back(j);
                }
            }
            
        }
        return ans;
    }
};