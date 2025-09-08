class Solution {
public:
    bool nonZero(int a){
        while(a!=0){
            if(a%10 ==0){
                return false;
            }
            a=a/10;
        }
        return true;
    }
    vector<int> getNoZeroIntegers(int n) {
        for(int i=1;i<n;i++){
            int temp=n-i;
            if(nonZero(temp) && nonZero(i)){
                return {temp,i};
            }
        }
        return {-1,-1};
    }
};