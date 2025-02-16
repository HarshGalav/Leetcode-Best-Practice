class Solution {
public:
    bool f(int ind, int n, vector<int>& result, vector<bool>& vis) {
        if (ind >= result.size()) {
            return true;
        }
        if (result[ind] != -1) {
            return f(ind + 1, n, result, vis);
        }
        for (int i = n; i >= 1; i--) {
            if (vis[i]) continue;

            vis[i] = true;
            result[ind] = i;

            if (i == 1) {
                if (f(ind + 1, n, result, vis)) {
                    return true;
                }
            } else {
                int j = ind + i;
                if (j < result.size() && result[j] == -1) {
                    result[j] = i;
                    if (f(ind + 1, n, result, vis)) {
                        return true;
                    }
                    result[j] = -1;  
                }
            }

            vis[i] = false;      
            result[ind] = -1;   
        }
        return false;
    }

    vector<int> constructDistancedSequence(int n) {
        vector<int> result(2 * n - 1, -1);
        vector<bool> vis(n + 1, false);
        f(0, n, result, vis);
        return result;
    }
};
