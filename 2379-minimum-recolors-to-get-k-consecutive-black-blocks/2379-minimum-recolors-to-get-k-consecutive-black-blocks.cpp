class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n=blocks.size();
        int i=0,j=k-1;
        int mini=INT_MAX;
        while(j<n){
            int temp=0;
            for(int x=i;x<=j;x++){
                if(blocks[x]=='W'){
                    temp++;
                }
            }
            mini=min(temp,mini);
            i++;
            j++;
        }
        return mini;
    }
};