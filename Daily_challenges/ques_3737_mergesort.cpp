class Solution {
public:
long long mergeCount(vector<int>&prefix,int left,int right){
    if(right-left<=1)return 0;
    int mid = (left+right)/2;
    long long cnt = 0;
    cnt+=mergeCount(prefix,left,mid);
    cnt+=mergeCount(prefix,mid,right);

    int j=mid;
    for(int i =left;i<mid;i++){
        while(j<right&&prefix[j]<=prefix[i]) j++;
        cnt += (right-j);
    }
    inplace_merge(prefix.begin()+left,prefix.begin()+mid,prefix.begin()+right);
    return cnt;
}
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> prefix(n+1);
        prefix[0]=0;
        for(int i=0;i<n;i++){
            prefix[i+1]=prefix[i]+(nums[i]==target ? 1 : -1);
        }
        return mergeCount(prefix,0,n+1);
    }
};