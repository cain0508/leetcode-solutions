class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int l=0,r=0,ans=0;
        int cnt[3]={0,0,0};
        while(r<n){
            cnt[s[r]-'a']++;//return the difference in index 'a'-'a'=0, 'b'-'a'=1, 'c'-'a'=2.
            while(cnt[0]>0 && cnt[1]>0 && cnt[2]>0){
                cnt[s[l]-'a']--;
                l++;
            }
            ans+=l;
            r++;
        }
        return ans;
    }
};