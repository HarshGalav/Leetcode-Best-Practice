class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        vector<int>freetime;
        freetime.push_back(startTime[0]);
        for(int i=1;i<startTime.size();i++){
            freetime.push_back(startTime[i]-endTime[i-1]);
        }
        freetime.push_back(eventTime-endTime.back());
        int n=freetime.size();
        vector<int>leftmax(n,0);
        vector<int>rightmax(n,0);
        for(int i=n-2;i>=0;i--){
            rightmax[i]=max(rightmax[i+1],freetime[i+1]);
        }
        for(int i=1;i<n;i++){
            leftmax[i]=max(leftmax[i-1],freetime[i-1]);
        }
        int result=0;
        for(int i=1;i<n;i++){
            int eventDuration=endTime[i-1]-startTime[i-1];
            if(eventDuration <= max(leftmax[i-1],rightmax[i])){
                result=max(result,freetime[i-1]+freetime[i]+eventDuration);
            }
            result=max(result,freetime[i-1]+freetime[i]);
        }
        return result;
    }
};