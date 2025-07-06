class Solution {
public:
    int maxJump(vector<int>& stones) {
        int maxi=INT_MIN;
        for(int i=0;i<stones.size();i++){
            if(i+1<stones.size()){
                maxi=max(maxi,stones[i+1]-stones[i]);
            }
            if(i+2<stones.size()){
                maxi=max(maxi,stones[i+2]-stones[i]);
            }
        }
        return maxi;

    }
};