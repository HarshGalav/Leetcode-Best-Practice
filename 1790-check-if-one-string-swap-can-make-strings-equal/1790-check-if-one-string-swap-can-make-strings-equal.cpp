class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int n=s1.size();
        int n2=s2.size();
        
        if(n!=n2){
            return false;
        }
        vector<int>g;
        for(int i=0;i<n;i++){
            if(s1[i]!=s2[i] ){
                g.push_back(i);
                if(g.size()>2){
                    return false;
                }
                
            }
           
        }
        if(g.size()==0) return true;
        if (g.size() != 2) return false;

        if(s1[g[0]]==s2[g[1]] &&s1[g[1]]==s2[g[0]] ){
            return true;
        }
        return false;

    }
};