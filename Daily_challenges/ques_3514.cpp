class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> pair;
        for(int i=0;i<n;i++){
            for(int j = 0;j<n;j++)
            pair.insert(nums[i]^nums[j]);
        }
        unordered_set<int> triple;
        for(int v:pair)
        for(int k =0;k<n;k++)
        triple.insert(v^nums[k]);

        return triple.size();
    }
};