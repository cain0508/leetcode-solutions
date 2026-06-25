class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        //brute force
        int n=nums.size();
        long long ans=0;
        for(int i=0;i<n;i++){
            int cnt = 0,tot=0;
            for(int j=i;j<n;j++){
                if(nums[j]==target) cnt++;
                tot++;
                if(cnt*2>tot) ans++;
            }
        }
        return ans;
    }
};