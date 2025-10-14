class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int x=heights.size();
        vector<int>ll(heights.size());
        vector<int>rl(heights.size());
        vector<int>ans(heights.size());
        
        stack<int>str;
        stack<int>stl;
        for(int i=0;i<x;i++){
            while(!stl.empty() && (heights[stl.top()] >= heights[i])){
                stl.pop();
            }
            if(stl.empty()){
                ll[i]=0;
            }
            else{
                ll[i]=stl.top()+1;
               
            }
            
            stl.push(i);
            
        }
        for(int i=x-1;i>=0;i--){
            while(!str.empty() && (heights[str.top()] >= heights[i])){
                str.pop();
            }
            if(str.empty()){
                rl[i]=x-1;
            }
            else{
                rl[i]=str.top()-1;
                 
            }
           str.push(i);

            
        }
        for(int i=0;i<x;i++){
            ans[i]=(rl[i]-ll[i]+1)*heights[i];
        }
        return *max_element(ans.begin(),ans.end());


    }
};