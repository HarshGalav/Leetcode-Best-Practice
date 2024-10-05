class Solution {
public:
        long long minimumOperations(vector<int>& A, vector<int>& target) {
        long res = 0;
        int pre = 0, n = A.size();
        for (int i = 0; i < n; ++i) {
            res += max(target[i] - A[i] - pre, 0);
            pre = target[i] - A[i];
        }
        return res + max(-pre, 0);
    }
};