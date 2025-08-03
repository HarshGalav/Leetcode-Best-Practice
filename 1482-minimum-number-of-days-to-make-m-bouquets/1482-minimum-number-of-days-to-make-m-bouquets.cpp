class Solution {
public:
    int f2(int mid, vector<int>& v, int k) {
        int cnt = 0, bundles = 0;
        for (int i : v) {
            if (i <= mid) {
                cnt++;
                if (cnt == k) {
                    bundles++;
                    cnt = 0;
                }
            } else {
                cnt = 0;
            }
        }
        return bundles;
    }

    int f(int l, int r, vector<int>& v, int m, int k) {
        int ans = -1;
        while (l <= r) {
            int mid = (l + r) / 2;
            int val = f2(mid, v, k);
            if (val >= m) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        // long long total = 1LL * m * k;
        // if (total > bloomDay.size()) return -1;
        int mini = *min_element(bloomDay.begin(), bloomDay.end());
        int maxi = *max_element(bloomDay.begin(), bloomDay.end());
        return f(mini, maxi, bloomDay, m, k);
    }
};
