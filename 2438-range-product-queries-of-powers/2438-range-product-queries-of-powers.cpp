class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        const int MOD = 1e9 + 7;

        vector<int> temp;
        int i = 1, x = n;
        while (i <= x) {
            temp.push_back(i);
            i *= 2;
        }
        sort(temp.rbegin(), temp.rend());

        vector<int> temp2;
        while (n != 0) {
            for (int j = 0; j < temp.size(); j++) {
                if (temp[j] <= n) {
                    n = n % temp[j];
                    temp2.push_back(temp[j]);
                    break; 
                }
            }
        }

        sort(temp2.begin(), temp2.end());

        vector<long long> l(temp2.size(), 1);
        l[0] = temp2[0] % MOD;
        for (int k = 1; k < temp2.size(); k++) {
            l[k] = (l[k - 1] * temp2[k]) % MOD;
        }

        vector<int> ans;
        for (auto &q : queries) {
            int f = q[0];
            int s = q[1];
            if (f == 0) {
                ans.push_back(l[s]);
            } else {
                long long inv = modPow(l[f - 1], MOD - 2, MOD); 
                ans.push_back((l[s] * inv) % MOD);
            }
        }
        return ans;
    }

    long long modPow(long long a, long long b, long long m) {
        long long res = 1;
        while (b > 0) {
            if (b & 1) res = (res * a) % m;
            a = (a * a) % m;
            b >>= 1;
        }
        return res;
    }
};
