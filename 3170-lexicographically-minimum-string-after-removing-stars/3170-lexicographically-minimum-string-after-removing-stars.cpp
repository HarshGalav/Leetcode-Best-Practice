class Solution {
public:
    string clearStars(string s) {
        stack<pair<char, int>> stk;
        vector<bool> removed(s.size(), false);
        
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '*') {
                if (!stk.empty()) {
                    removed[stk.top().second] = true;
                    stk.pop();
                }
                removed[i] = true; 
            } else {
                stk.push({s[i], i});
            }
        }

        string result = "";
        for (int i = 0; i < s.size(); ++i) {
            if (!removed[i]) {
                result += s[i];
            }
        }
        return result;
    }
};
