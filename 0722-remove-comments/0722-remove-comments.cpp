class Solution {
public:
    vector<string> removeComments(vector<string>& source) {
        vector<string> ans;
        bool inBlock = false;
        string temp = "";

        for (auto i : source) {
            for (int j = 0; j < i.size(); j++) {
                if (!inBlock && j + 1 < i.size() && i[j] == '/' && i[j + 1] == '*') {
                    inBlock = true;
                    j++;
                } 
                else if (inBlock && j + 1 < i.size() && i[j] == '*' && i[j + 1] == '/') {
                    inBlock = false;
                    j++;
                } 
                else if (!inBlock && j + 1 < i.size() && i[j] == '/' && i[j + 1] == '/') {
                    break;
                } 
                else if (!inBlock) {
                    temp += i[j];
                }
            }

            if (!inBlock && temp.size() > 0) {
                ans.push_back(temp);
                temp = "";
            }
        }
        return ans;
    }
};
