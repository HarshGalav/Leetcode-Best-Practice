class Solution {
public:
    int maxDiff(int num) {
        string str = to_string(num);
        int n = str.size();
        unordered_map<char, vector<int>> mp;

        for (int i = 0; i < n; i++) {
            mp[str[i]].push_back(i);
        }

        string maxi = str;
        char maxi_c = '\0';

        for (int i = 0; i < n; i++) {
            if (str[i] != '9') {
                maxi_c = str[i];
                break;
            }
        }

        if (maxi_c != '\0') {
            for (auto i : mp[maxi_c]) {
                maxi[i] = '9';
            }
        }

        string mini = str;
        char mini_c = '\0';
        bool flag = false;

        for (int i = 0; i < n; i++) {
            if (i == 0 && str[i] != '1') {
                mini_c = str[i];
                flag = true;
                break;
            } else if (i > 0 && str[i] != '0' && str[i] != '1') {
                mini_c = str[i];
                break;
            }
        }

        if (mini_c != '\0') {
            if (flag) {
                for (auto i : mp[mini_c]) {
                    mini[i] = '1';
                }
            } else {
                for (auto i : mp[mini_c]) {
                    mini[i] = '0';
                }
            }
        }

        return stoi(maxi) - stoi(mini);
    }
};
