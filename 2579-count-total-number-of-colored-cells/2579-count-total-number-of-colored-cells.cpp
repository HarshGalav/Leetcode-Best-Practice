class Solution {
public:
    long long coloredCells(int n) {
        int a=1;
        while(n>1){
            a=a+4*(n-1);
            n--;
        }
        return a;
    }
};