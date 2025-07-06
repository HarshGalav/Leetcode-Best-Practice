class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char>rows[9];
        unordered_set<char>cols[9];
        unordered_set<char>boxes[9];
        for(int r=0;r<9;r++){
            for(int c=0;c<9;c++){
                if(board[r][c] == '.'){
                    continue;
                }
                char val= board[r][c];
                int boxind= (r/3) *3 + (c/3);
                if(rows[r].count(val) || cols[c].count(val) || boxes[boxind].count(val)){
                    return false;
                }
                rows[r].insert(val);
                cols[c].insert(val);
                boxes[boxind].insert(val);
            }
        }
        return true;
    }
};