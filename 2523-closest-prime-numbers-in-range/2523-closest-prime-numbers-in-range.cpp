class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
       vector<bool> isprime(right + 1, true);
    isprime[0] = isprime[1] = false;
        vector<int>pr;
        for(int i=2;i<=right;i++){
            if(isprime[i]==true){
                for(int j=2;i*j<=right;j++){
                    isprime[i*j]=false;
                }
            }
        }
        
        for(int i=left;i<=right;i++){
            if(isprime[i]==true){
                pr.push_back(i);
            }
        }
        if(pr.size()<2){
            return {-1,-1};
        }
        int a=-1,b=-1;
        int mini=INT_MAX;
        int n=pr.size();
        for(int i=0;i<n-1;i++){
            int temp=pr[i+1]-pr[i];
            if(temp<mini){
                mini=temp;
                a=pr[i];
            b=pr[i+1];
            }
            
            
        }
        return {a,b};
    }
};