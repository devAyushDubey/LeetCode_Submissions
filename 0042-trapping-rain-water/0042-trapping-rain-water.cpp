class Solution {
public:
    int trap(vector<int>& height) {
        
        vector<int> maxRHS(height.size()), maxLHS(height.size());
        int total_water = 0;
        
        maxLHS[0] = height[0];
        maxRHS[height.size()-1] = height[height.size()-1];
        
        for(int i=1;i<height.size();i++) maxLHS[i] = max(maxLHS[i-1],height[i]);
        for(int i=height.size()-2;i>=0;i--) maxRHS[i] = max(maxRHS[i+1],height[i]);
        
        for(int i=0;i<height.size();i++) total_water += (min(maxLHS[i],maxRHS[i])-height[i]);
        
        return total_water;
    }
};