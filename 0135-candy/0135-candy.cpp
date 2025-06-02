class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> second(n);
        vector<int> first(n);
        
        first[0] = 1;
        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i - 1]) {
                first[i] = first[i - 1] + 1;
            } else {
                first[i] = 1;
            }
        }

        second[n - 1] = 1;
        for (int i = n - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                second[i] = second[i + 1] + 1;
            } else {
                second[i] = 1;
            }
        }

        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += max(first[i], second[i]);
        }
        return sum;
    }
};
