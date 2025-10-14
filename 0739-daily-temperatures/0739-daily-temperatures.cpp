class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
         int x=temperatures.size();
        vector<int>ans(x,0);
        stack<int>st;
        for(int i=x-1;i>=0;i--){
           if(st.empty()){
               st.push(i);
               ans[i]=0;
           }
           else{
                while(!st.empty() && temperatures[st.top()]<=temperatures[i]){
                st.pop();
            }
            if(st.empty()){
                ans[i]=0;
            }
           
            else{
                ans[i]=st.top()-i;
            }
           st.push(i);
           }
           

        }
        return ans;
    }
};