class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int n=bits.size();
        if(n==1){
            return true;
        }
        if(bits[n-2]==0){
            return true;
        }
        int ones=0;
        for(int i=n-2;i>=0;i--){
            if(bits[i]==1){
                ones++;
            }
            else{
                break;
            }
        }
        if(ones%2==0){
            return true;
        }
        return false;
    }
};