class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        double l=INT_MAX;
        double h=INT_MIN;
        for(auto s:squares){
            l=min(l,(double)s[1]);
            h=max(h,(double)s[1]+s[2]);
        }
        int iteration=0;
        while(h-l>=1e-5){
            iteration++;
            double mid=(h+l)/2;
            double lower=0;
            double higher=0;
            for(auto& s:squares){
                int x=s[0], y=s[1],z=s[2];
                double top=y+z;
                double bottom=y;
                if(top<=mid){
                    lower +=(double)z*z;
                }
                else if(bottom >= mid){
                    higher +=(double)z*z;
                }
                else{
                    double ap=top-mid;
                    double bp=mid-bottom;
                    higher += ap*z;
                    lower += bp*z;
                }
            }
            if(higher > lower){
                l=mid;
            }
            else{
                h=mid;
            }

            // if(abs(higher - lower)<1e-5){
            //     return mid;
            // }
        }
        return l;
    }
};