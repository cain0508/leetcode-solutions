class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> node(n);
        int cmp = 0;
        node[0]=0;
        for(int i =1;i<n;i++){
            if(nums[i]-nums[i-1]>maxDiff)
            cmp++;
            node[i]=cmp;
        }
        vector<bool> ans;
        for(auto &q : queries){
            ans.push_back(node[q[0]]==node[q[1]]);
        }
        return ans;
    }
};