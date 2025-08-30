class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n=board.size();
        unordered_map<int,unordered_set<int>>mp;
        for(int i=0;i<n;i++){
            unordered_set<char>s;
            unordered_set<char>s1;
            for(int j=0;j<n;j++){
                if(board[i][j] != '.'){
                    if(s.find(board[i][j])!=s.end()){
                        return false;
                    }
                    else{
                        s.insert(board[i][j]);
                    }
                }

                if(board[j][i] != '.'){
                    if(s1.find(board[j][i])!=s1.end()){
                        return false;
                    }
                    else{
                        s1.insert(board[j][i]);
                    }
                }

                if(board[i][j] != '.'){
                    int boxid=(i/3) * 3 + j/3;
                    if(mp[boxid].find(board[i][j])!= mp[boxid].end()){
                        return false;
                    }
                    else{
                        mp[boxid].insert(board[i][j]);
                    }
                }
                
            }
        }
        return true;
        
    }
};