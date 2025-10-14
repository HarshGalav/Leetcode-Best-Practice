class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.size(), n2 = s2.size();
        if(n1 > n2) return false;

        string sorted_s1 = s1;
        sort(sorted_s1.begin(), sorted_s1.end());

        for(int i = 0; i <= n2 - n1; i++) {
            string sub = s2.substr(i, n1);
            sort(sub.begin(), sub.end());
            if(sub == sorted_s1) return true;
        }

        return false;
    }
};