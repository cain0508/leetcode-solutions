class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        // solved uding two pointer
        int left = 0, right = k;
        int sum = 0, maxSum;
        for (int i = 0; i < k; i++) {
            sum += nums[i];
        }

        maxSum = sum;
        while (right < nums.size()) {
            sum += nums[right] - nums[left];
            maxSum = max(maxSum, sum);
            left++;
            right++;
        }
        return (double)maxSum / k;
    }
};