class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> res(n,0);
        if (k==0) return res;
        int l,r;
        if(k>0){
            l=1;
            r=k;
        }else {
            l=n+k;
            r=n-1;
        }
        int windowsum = 0;
        for(int i=l;i<=r;i++){
            windowsum+=code[i%n];
        }
        for(int i=0;i<n;i++){
            res[i]=windowsum;
            windowsum+=code[(r+1)%n];
            windowsum-=code[l%n];
            l++;
            r++;
        }
        
        return res;
    }
};