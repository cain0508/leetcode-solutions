class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int slow=0;
        int n = nums.size();
        for(int fast = 0;fast<n;fast++){
            if(nums[fast]!=0){
                nums[slow]=nums[fast];
                slow++;
            }
        }
        for(int i=slow;i<n;i++){
            nums[i]=0;
        }
    }
};