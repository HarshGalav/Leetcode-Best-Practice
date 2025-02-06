#include <vector>
#include <algorithm>

class Solution {
public:
    int kadane(vector<int>& arr) {  
        int sum = 0;
        int maxSum = 0;
        for (int it : arr) {
            sum = max(sum, 0) + it;
            maxSum = max(sum, maxSum);
        }
        return maxSum;
    }

    int kConcatenationMaxSum(vector<int>& arr, int k) {
        const int mod = 1e9 + 7;
        int n = arr.size();

        if (k == 1) {
            return kadane(arr);
        }

        long long totalSum = 0;
        for (int it : arr) {
            totalSum = (totalSum + it) % mod;
        }

        int maxSum = 0;
        int currentSum = 0;

        for (int i = 0; i < 2 * n; ++i) {
            currentSum = max(0, currentSum + arr[i % n]); 
            maxSum = max(maxSum, currentSum);
        }

        if (totalSum <= 0) {
            return maxSum;
        }

        long long ans = (maxSum + (long long)(k - 2) * totalSum) % mod; 
        return ans;
    }
};