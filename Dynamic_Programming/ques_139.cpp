class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<bool> dp(n+1,false);
        dp[0]=true;
        for(int i=1;i<=n;i++){
            for(string& w : wordDict){
                int len = w.size();
                if(i>=len && dp[i-len]){
                    if(s.substr(i-len,len)==w){
                        dp[i]=true;
                        break;
                    }
                }
            }
        }
        return dp[n];
    }
};