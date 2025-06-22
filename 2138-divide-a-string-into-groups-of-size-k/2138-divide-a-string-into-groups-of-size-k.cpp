class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string>ans;
         int tg = ceil((float)s.length() / k);
        for(int i=0;i< tg;i++){
            if(s.length()<k){
                while(s.length()<k){
                    s+=fill;
                }
            }
            string str=s.substr(0,k);
            ans.push_back(str);
           s=s.substr(k);
            
        }
        return ans;
    }
};