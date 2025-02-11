class Solution {
public:
bool check(stack<char>&st, string &s,int n){
    stack<char>temp=st;
    for(int i=n-1;i>=0;i--){
        if(temp.top()!=s[i]){
            return false;
        }
        temp.pop();
    }
    return true;
}
    string removeOccurrences(string s, string part) {
        stack<char>st;
        for(int i=0;i<s.size();i++){
            st.push(s[i]);
            if(st.size()>=part.size() && check(st,part,part.size())){
                for(int j=0;j<part.size();j++){
                    st.pop();
                }
            }
        }
        string result="";
        while(!st.empty()){
            result.push_back(st.top());
            st.pop();
        }
        reverse(result.begin(),result.end());
        return result;
    }
};