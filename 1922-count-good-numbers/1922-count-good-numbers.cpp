class Solution {
    private: 
    long mod=1000000007;
public:
    long power(long x,long y){
        if(y==0){
            return 1;
        }
        long temp=power(x,y/2);
        if(y%2==0){
            return (temp*temp)%mod;
        }
        else{
            return (temp*temp*x)%mod;
        }
    }
    int countGoodNumbers(long long n) {
        
         long pr=n/2;
         long ev=(n+1)/2;
         long first=power(4,pr)%mod;
         long second=power(5,ev)%mod;
        
        return int((first*second)%mod);
    }
};