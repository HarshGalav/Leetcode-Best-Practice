class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        unordered_map<int, deque<int>> mp;
        int a = mat.size();
        int b = mat[0].size();
        
        for(int i = 0; i < a; i++) {
            for(int j = 0; j < b; j++) {
                mp[j - i].push_back(mat[i][j]);
            }
        }
        
        for(auto& i : mp) {
            sort(i.second.begin(), i.second.end());
        }
        
        for(int i = 0; i < a; i++) {
            for(int j = 0; j < b; j++) {
                mat[i][j] = mp[j - i].front();
                mp[j - i].pop_front();
            }
        }
        
        return mat;
    }
};
