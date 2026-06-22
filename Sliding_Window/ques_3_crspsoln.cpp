class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> freq(256);

        int l=0, r=0, n=s.size(), maxLen=0;

        while(r<n){
            freq[s[r]]++;
            while(freq[s[r]]>1){
                freq[s[l]]--;
                l++;
            }
            maxLen = max(maxLen, r-l+1);
            r++;
        }
        return maxLen;
    }
};