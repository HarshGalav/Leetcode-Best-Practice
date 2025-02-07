class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(auto i:s){
            // st.push(i);
            if((i==')'|| i=='}' || i==']')&& st.empty()){
                return false;
            }
            else if((i==')' && st.top()=='(')||(i=='}' && st.top()=='{')||(i==']' && st.top()=='[')){
                
                st.pop();
            }
            else{
                st.push(i);
            }
        }
        if(st.size()==0){
            return true;
        }
        return false;
    }
};