class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int>curr,prev,result;
        for(int i=0;i<arr.size();i++){
            for(int x: prev){
                result.insert(arr[i] | x);
                curr.insert(arr[i] | x);
            }
            result.insert(arr[i]);
            curr.insert(arr[i]);
            prev=curr;
            curr.clear();
        }
        return result.size();
    }
};