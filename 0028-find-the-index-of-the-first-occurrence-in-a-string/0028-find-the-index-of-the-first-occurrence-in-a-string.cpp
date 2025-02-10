class Solution {
public:
    int strStr(string haystack, string needle) {
        int n1=haystack.size();
        int n2=needle.size();
        int ans=-1;
        for(int i=0;i<=(n1-n2);i++){
            int j;
            for(j=0;j<n2;j++){
                if(haystack[i+j]!=needle[j]){
                    break;
                }
                
            }
            if(j==n2){
                return i;
            }
        }
        return ans;
    }
};