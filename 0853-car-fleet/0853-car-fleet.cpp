class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,double>>cars;
        for(int i=0;i<position.size();i++){
            cars.push_back({position[i],double(target-position[i])/speed[i]});
        }
        sort(cars.rbegin(),cars.rend());
        double before=0.0;
        int fleet=0;
        for(auto i:cars){
            if(i.second>before){
                fleet++;
                before=i.second;
            }
        }
        return fleet;
    }
};