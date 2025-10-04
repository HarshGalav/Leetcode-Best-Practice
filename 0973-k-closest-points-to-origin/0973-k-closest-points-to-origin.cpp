class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,pair<int,int>>>pq;
        for(auto i:points){
            int dist=((i[0]* i[0]) +(i[1]*i[1]));
            pq.push({dist,{i[0],i[1]}});
            if(pq.size()>k){
                pq.pop();
            }
        }
        vector<vector<int>> result;
        while (!pq.empty()) {
            auto p = pq.top().second;
            result.push_back({p.first, p.second});
            pq.pop();
        }
        
        return result;
    }
};