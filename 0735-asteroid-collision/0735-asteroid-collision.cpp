class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for (int i = 0; i < asteroids.size(); i++) {
            if (!st.empty()) {
                if (st.top() > 0 && asteroids[i] < 0) {
                    while (!st.empty() && st.top() > 0 && asteroids[i] < 0) {
                        if (abs(st.top()) > abs(asteroids[i])) {
                            asteroids[i] = 0;
                            break;
                        } else if (abs(st.top()) == abs(asteroids[i])) {
                            st.pop();
                            asteroids[i] = 0;
                            break;
                        } else {
                            st.pop();
                        }
                    }
                    if (asteroids[i] != 0) st.push(asteroids[i]);
                } else {
                    st.push(asteroids[i]);
                }
            } else {
                st.push(asteroids[i]);
            }
        }
        vector<int> ans;
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
