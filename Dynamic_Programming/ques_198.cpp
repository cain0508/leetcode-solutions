class Solution {
public:
    int rob(vector<int>& nums) {
        int pred1=0,pred2=0;
        for(int i=0;i<nums.size();i++){
            int curr = max(pred1, pred2 + nums[i]);
            pred2=pred1;
            pred1=curr;
        }
        return pred1;
    }
};