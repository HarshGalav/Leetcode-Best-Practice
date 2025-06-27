class Solution {
public:
    vector<int> beautifulArray(int n) {
        vector<int> ans;
        
        for (int i = 1; i <= n; i++) {
            ans.push_back(i);
        }

        do {
            bool flag = true;
            
            for (int i = 0; i < n; i++) {
                for (int j = i + 1; j < n; j++) {
                    for (int k = i + 1; k < j; k++) {
                        if (2 * ans[k] == ans[i] + ans[j]) {
                            flag = false;
                            break;
                        }
                    }
                    if (!flag) break;
                }
                if (!flag) break;
            }

            if (flag) {
                return ans;
            }

        } while (next_permutation(ans.begin(), ans.end()));

        return {};
    }
};
