class Solution {
public:
    int minMaxDifference(int num) {
        int i=0;
        string str= to_string(num);
        int n=str.size();
        unordered_map<char,vector<int>>mp;
        for(int i=0;i<n;i++){
            mp[str[i]].push_back(i);
        }
        int idx=-1;
        for(int i=0;i<n;i++){
            if(str[i]-'0'!=9){
                idx =i;
                break;
            }
        }
        if(idx==-1){
            return num;
        }
        string maxi=str;
        for(auto i:mp[str[idx]]){
            maxi[i]='9';
        }
        string mini=str;
        for(auto i:mp[str[0]]){
            mini[i]='0';
        }
        return stoi(maxi)-stoi(mini);

        
    }
};