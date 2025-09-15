class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        // max heap -> keep farthest element on top so we can pop it out
        priority_queue<pair<int,int>> pq;

        for (auto i : arr) {
            int diff = abs(i - x);

            // push with custom ordering: (distance, value)
            // to respect tie-breaking rule, we store value negatively
            // because in max-heap, larger 'second' stays -> we want larger preferred
            pq.push({diff, i});

            if (pq.size() > k) {
                pq.pop();  // remove farthest element
            }
        }

        vector<int> ans;
        while (!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        // optional: reverse or sort according to problem’s output format
        // since they don’t require sorted order, this is fine
        sort(ans.begin(),ans.end());
        return ans;
    }
};
