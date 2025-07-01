class Solution {
public:
    vector<int> closestDivisors(int num) {
        int sq=sqrt(num+2);
        for(int a=sq;a>0;a--){
            if((num+1)%a ==0){
                return {a,(num+1)/a};
            }
            if((num+2)%a==0){
                return {a,(num+2)/a};
            }
        }
        return{-1,-1};
    }
};