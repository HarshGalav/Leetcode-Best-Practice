class Solution {
public:
    bool issym(int a){
        int n=0;
        int b=a;
        while(a!=0){
            a=a/10;
            n++;
        }
        if(n%2 !=0){
            return false;
        }
        int x=n/2;
        int sum1=0;
        while(x>0){
            sum1=sum1+ b%10;
            b=b/10;
            x--;
        }
        while(b>0){
            sum1=sum1-b%10;
            b=b/10;
        }
        if(sum1==0){
            return true;
        }
        return false;

    }
    int countSymmetricIntegers(int low, int high) {
        int cnt=0;
        for(int i=low;i<=high;i++){
            if(issym(i)){
                cnt++;
            }
        }
        return cnt;
    }
};