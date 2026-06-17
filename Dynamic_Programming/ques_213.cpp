class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        if(n==2) return max(nums[0],nums[1]);

        int prev =0,curr=0;
        for(int i=0;i<n-1;i++){
            int next = max(curr,prev+nums[i]);
            prev = curr;
            curr = next;
        }
        int result1 = curr;

        prev = 0;curr = 0;
        for(int i=1;i<n;i++){
            int next = max(curr,prev+nums[i]);
            prev = curr;
            curr = next;
        }
        int result2 = curr;

        return max(result1,result2);
    }
};