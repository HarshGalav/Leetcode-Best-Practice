class Solution {
public:
    bool isv(char i){
        if(i=='a'|| i=='e' || i=='o'|| i=='i'||i=='u'){
            return true;
        }
        return false;
    }
    bool doesAliceWin(string s) {
        int vo=0;
        for(auto i:s){
            if(isv(i)){
                vo++;
            }
        }
        if(vo==0){
            return false;
        }
        return true;
    }
};