class Solution {
public:
    string clearDigits(string s) {
        stack<char>st;
        int n=s.size();
        for(auto i:s){
            if(st.empty()){
                st.push(i);
            }
            else if(isalpha(st.top()) && isdigit(i)){
                st.pop();
            }
            else{
                st.push(i);
            }


        }
        string ans="";
        while(!st.empty()){
            char a=st.top();
            ans=ans+a;
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;

    }
};