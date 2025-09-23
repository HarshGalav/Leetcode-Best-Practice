class Solution {
public:
    vector<int>f(string s){
        int i=0,j=0;
        vector<int>temp;
        while(j<s.size()){
            if(s[j]=='.'){
                string sub=s.substr(i,j-i);
                temp.push_back(stoi(sub));
                i=j+1;
            }
            j++;
        }

         if (i < s.size()) {
            string sub = s.substr(i);
            temp.push_back(stoi(sub));
        }
        return temp;
    }
    int compareVersion(string version1, string version2) {
        vector<int>sub1=f(version1);
        vector<int>sub2=f(version2);
        int n = max(sub1.size(), sub2.size());
        for (int i = 0; i < n; i++) {
            int v1 = (i < sub1.size() ? sub1[i] : 0);
            int v2 = (i < sub2.size() ? sub2[i] : 0);
            if (v1 > v2) return 1;
            if (v1 < v2) return -1;
        }
        return 0;
    }
};