class Solution {
public:
    int f(int n){
        int ans=0;
        while(n>0){
            int digit=n%10;
            ans+= (digit * digit);
            n=n/10;
        }
        return ans;
    }
    bool isHappy(int n) {
        unordered_set<int>s;
        while(n!=1 && !s.count(n)){
            s.insert(n);
            n= f(n);
        }
        return n==1;
    }
};