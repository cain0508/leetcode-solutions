class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int lastSeen[128];
        fill(lastSeen, lastSeen + 128, -1);

        int left = 0, ans = 0;
        for (int right = 0; right < s.size(); right++) {
            char c = s[right];

            if (lastSeen[c] >= left) {
                left = lastSeen[c] + 1;
            }
            lastSeen[c] = right;
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};