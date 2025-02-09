class Solution {
public:
    bool isp(int i,int j,string &s){
        if(i >= j){
            return true;
        }
        if(s[i]==s[j]){
           return isp(i+1,j-1,s);
        }
        return false;
    }
    string longestPalindrome(string s) {
        int n=s.size();
        int l=INT_MIN;
        int st=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isp(i,j,s)){
                    if(l<j-i+1){
                        st=i;
                        l=j-i+1;
                    }
                }
            }
        }
        return s.substr(st,l);

    }
};