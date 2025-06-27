class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        vector<pair<double, pair<int, int>>> pr;
        int n = arr.size();
        
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                pr.push_back({(double)arr[i] / arr[j], {arr[i], arr[j]}});
            }
        }
        
        sort(pr.begin(), pr.end());
        
        return {pr[k - 1].second.first, pr[k - 1].second.second};
    }
};
