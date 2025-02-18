class Solution {
public:
    string smallestNumber(string pattern) {
        string ans="";
        int count=1;
        int n=pattern.length();
        stack<char>st;
        for(int i=0;i<=n;i++){
            st.push(count+'0');
            count++;
            if(i==n || pattern[i]=='I'){
                while(!st.empty()){
                    ans+=st.top();
                    st.pop();
                }
            }
        }
        return ans;
    }
};