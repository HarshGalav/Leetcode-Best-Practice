class Solution {
public:
    int total(vector<int>& v, int mid) {
        int ans = 0;
        for (auto i : v) {
            ans += ceil((double)i / mid);
        }
        return ans;
    }

    int f(int l, int r, vector<int>& piles, int h) {
        int ans = r;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            int val = total(piles, mid);
            if (val > h) {
                l = mid + 1;
            } else {
                ans = mid;
                r = mid - 1;
            }
        }
        return ans;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int maxPile = *max_element(piles.begin(), piles.end());
        return f(1, maxPile, piles, h);
    }
};
