//contains the 1D solution
//Here i store the value of i-1 and i-1 gets discarded the time complexity is O(m*n) and space complexity is O(n)
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> dp(n,0);
        dp[0]=grid[0][0];

        for(int j=1;j<n;j++){
            dp[j]=dp[j-1]+grid[0][j];
        }
        for(int i =1;i<m;i++){
            dp[0]+=grid[i][0];//it updates the first element of a row 
            for(int j=1;j<n;j++){
                dp[j] = grid[i][j]+min(dp[j],dp[j-1]);
            }
        }
        return dp[n-1];
    }
};