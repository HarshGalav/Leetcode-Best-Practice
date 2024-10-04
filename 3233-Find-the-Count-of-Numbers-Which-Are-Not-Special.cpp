class Solution {
public:
    vector<int>f(int lim){
            vector<bool>check(lim+1,true);
            check[0]=check[1]=false;
            for(int p=2;p*p<=lim;++p){
                if(check[p]){
                    for(int i=p*p;i<=lim;i+=p){
                        check[i]=false;
                    }
                }
            }
            vector<int>ret;
            for(int i=2;i<lim;i++){
                if(check[i]){
                    ret.push_back(i);
                }
            }
            return ret;
        }

    int nonSpecialCount(int l, int r) {
        int mx=(int)sqrt(r)+1;
        vector<int>prime=f(mx);
        vector<int>special;
        for(long long iter:prime){
            long long sq=iter*iter;
            if(sq>=l*1LL && sq<=r*1LL){
                special.push_back(sq);
            }
        }
        return (r-l+1)-special.size();
        
    }
};