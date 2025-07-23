class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int ans = 0;

        if (x > y) {
            stack<char> st;
            string rem1 = "";
            for (int i = 0; i < s.length(); i++) {
                if (!st.empty() && st.top() == 'a' && s[i] == 'b') {
                    ans += x;
                    st.pop();
                } else {
                    st.push(s[i]);
                }
            }

            while (!st.empty()) {
                rem1 += st.top();
                st.pop();
            }
            reverse(rem1.begin(), rem1.end());

            for (int i = 0; i < rem1.length(); i++) {
                if (!st.empty() && st.top() == 'b' && rem1[i] == 'a') {
                    ans += y;
                    st.pop();
                } else {
                    st.push(rem1[i]);
                }
            }
        } else {
            stack<char> st;
            string rem1 = "";
            for (int i = 0; i < s.length(); i++) {
                if (!st.empty() && st.top() == 'b' && s[i] == 'a') {
                    ans += y;
                    st.pop();
                } else {
                    st.push(s[i]);
                }
            }

            while (!st.empty()) {
                rem1 += st.top();
                st.pop();
            }
            reverse(rem1.begin(), rem1.end());

            for (int i = 0; i < rem1.length(); i++) {
                if (!st.empty() && st.top() == 'a' && rem1[i] == 'b') {
                    ans += x;
                    st.pop();
                } else {
                    st.push(rem1[i]);
                }
            }
        }

        return ans;
    }
};
