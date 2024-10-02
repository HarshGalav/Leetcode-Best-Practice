#pragma GCC optimize ("Ofast")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#pragma GCC optimize ("-ffloat-store")
#pragma GCC optimize ("O3", "unroll-loops")
auto _=[]()noexcept{ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);return 0;}();

class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        set<int>all;
        for(int j=0;j<n;j++){
            all.insert(j);
           
        }
        vector<int>result;
        for(int q=0;q<queries.size();q++){
            int u=queries[q][0];
            int v=queries[q][1];
            vector<int>to_remove;
            auto it=all.upper_bound(u);
            while(it !=all.end() && *it<v){
                to_remove.push_back(*it);
                it++;
            }
            for(auto i:to_remove){
                all.erase(i);
            }
            result.push_back(all.size()-1);
        }
        return result;
    }
};