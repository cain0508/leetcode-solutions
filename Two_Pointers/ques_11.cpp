class Solution {
public:
    int maxArea(vector<int>& height) {
        int left=0,right=height.size() - 1;
        int area=0;
        while(left<right){
            int min_height=min(height[left],height[right]);
            area = max(area,min_height*(right-left));
            if(height[left]<height[right])
                left++;
            else
                right--;
        }
        return area;
    }
};