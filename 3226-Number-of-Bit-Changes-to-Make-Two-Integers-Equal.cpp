class Solution {
public:
    int minChanges(int n, int k) {
         if ((n & k) != k) {
            return -1;
        }
        int r=n^k;
        return __builtin_popcount(r);
    }
};