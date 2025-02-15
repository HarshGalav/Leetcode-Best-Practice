class Solution {
public:
bool f(int sq,int i,int ind,int  sum){
    
    string st=to_string(sq);
    if(ind==st.length()){
        return sum==i;
    }
    int n=st.size();
    for(int j=ind;j<n;j++){
        string temp=st.substr(ind,j-ind+1);
        int num=stoi(temp);
        
        if(sum+num>i){
            return false;
        }
    //    if(sum+num==i){
    //         return true;
    //     }
        
           if( f(sq,i,j+1,sum+num)==true){
                return true;
           }
        
    }
    return false;

}
    int punishmentNumber(int n) {
        int ans=0;
        for(int i=1;i<=n;i++){
            int sq=i*i;
            if(f(sq,i,0,0)){
                ans=ans+sq;
            }
            
        }
        return ans;
    }
};