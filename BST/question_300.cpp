class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>tails;
        for(int num:nums){
            auto numb = lower_bound(tails.begin(),tails.end(),num);
            if(numb==tails.end()) tails.push_back(num);
            else *numb=num;
        }
        return tails.size();
    }
}; 