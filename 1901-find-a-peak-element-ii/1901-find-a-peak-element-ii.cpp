class Solution {
    int findMaxRow(vector<vector<int>>& mat, int mid){
        int maxRow =0;
        for(int i=1; i<mat.size();i++){
            if(mat[i][mid] > mat[maxRow][mid]){
                maxRow=i;
            }
        }
        return maxRow;
    }
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int row=mat.size();
        int col= mat[0].size();
        int s=0;
        int e=col-1;
        while(s< mat.size() && e>=0){
            int leftVal =(e-1 >=0)? mat[s][e-1] : -1;
            int rightVal =(e+1 < col)? mat[s][e+1]:-1;
            int upVal=(s-1 >= 0)? mat[s-1][e] :-1;
            int downVal=(s+1<row)? mat[s+1][e]:-1;
            if(mat[s][e] > leftVal && mat[s][e] > rightVal && mat[s][e] > upVal && mat[s][e]> downVal){
                return {s,e};
            }
            else if(leftVal > mat[s][e]){
                e--;
            }
            else if(rightVal > mat[s][e]){
                e++;
            }
            else if(upVal>mat[s][e]){
                s--;
            }
            else{
                s++;
            }
        }
        return {-1,-1};
    }
};