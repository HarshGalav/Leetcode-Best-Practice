class Solution {
public:
    int maxDistance(string s, int k) {
        int ans=0;
        for(char hor:{'W','E'}){
            for(char ver:{'N','S'}){
                int remk=k,netx=0,nety=0;
                for(char ch:s){
                    if(ch == hor && remk){
                        if(ch=='W'){
                            ch='E';
                        }
                        else{
                            ch='W';
                        }
                        remk--;
                    }
                    else if(ch == ver && remk){
                        if(ch=='N'){
                            ch='S';
                        }
                        else{
                            ch='N';
                        }
                        remk--;
                    }
                    netx+=(ch=='E');
                    netx-=(ch=='W');
                    nety+=(ch=='N');
                    nety-=(ch=='S');
                    ans=max(ans,abs(netx)+abs(nety));
                }
            }
        }
        return ans;
    }
};