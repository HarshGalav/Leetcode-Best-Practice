class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        vector<long long>v;
        int n=differences.size();
        v.push_back(differences[0]);
        for(long long i=1;i<n;i++){
            v.push_back(differences[i]+v.back());
        }
        int mini=*min_element(v.begin(),v.end());
        int maxi=*max_element(v.begin(),v.end());
        int cnt=0;
        for(int a=lower;a<=upper;a++){
            if(a+mini<=upper && a+mini >=lower && a+maxi<=upper && a+maxi>=lower){
                cnt++;
            }
        }
        return cnt;
    }
};