class Solution {
public:
    long long flowerGame(int n, int m) {
        int oddn=0,evenn=0,oddm=0,evenm=0;
        if(n%2==0){
            oddn=n/2;
            evenn=n/2;
        }
        else{
            oddn=n/2 +1;
            evenn=n/2;
        }

        if(m%2==0){
            oddm=m/2;
            evenm=m/2;
        }
        else{
            oddm=(m/2)+1;
            evenm=(m/2);
        }
        return (oddn* evenm) + (oddm * evenn);

    }
};