class Solution {
public:
    int search(vector<int>& a, int target) {
        int low=0,high=a.size()-1;
        while(low<=high){
            int mid=(low+high)>>1;
            if(a[mid]==target){
                return mid;
            }
            if(a[low]<=a[mid]){
                if(a[low]<=target && a[mid]>=target){
                    high=mid-1;
                }
                else{
                    low=mid+1;
                }
            }
            else{
                if(target>= a[mid] && target <= a[high]){
                    low=mid+1;
                }
                else{
                    high=mid-1;
                }

            }
        }
        return -1;
    }
};