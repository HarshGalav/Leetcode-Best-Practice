class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        vector<int>good(3,0);
        for(auto i:triplets){
            if(i[0]<=target[0] && i[1]<=target[1] &&i[2]<=target[2]){
                if(i[0]==target[0]) good[0]=1;
                if(i[1]==target[1]) good[1]=1;
                if(i[2]==target[2]) good[2]=1;
            }
        }
        return good[0] && good[1] && good[2];
    }
};