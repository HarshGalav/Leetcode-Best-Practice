class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int>leftSmallest(n);
        vector<int>rightSmallest(n);
        stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(st.empty()){
                leftSmallest[i]=0;
            }
            else
            leftSmallest[i]=st.top()+1;
            st.push(i);
        }

         while (!st.empty()) st.pop();

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && heights[st.top()] >= heights[i])
                st.pop();
            rightSmallest[i] = st.empty() ? n - 1 : st.top() - 1;
            st.push(i);
        }

         int maxA = 0;
        for (int i = 0; i < n; i++) {
            maxA = max(maxA, heights[i] * (rightSmallest[i] - leftSmallest[i] + 1));
        }

        return maxA;

    }
};