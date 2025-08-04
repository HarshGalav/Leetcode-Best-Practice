class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        if (arr.empty()) return k;
        set<int> s(arr.begin(), arr.end());
        int maxi = arr.back();
        int i=1;
        while(true) {
            if (s.find(i) == s.end()) {
                k--;
            }
            if (k == 0) {
                return i;
            }
            i++;
        }
        return -1;
    }
};
