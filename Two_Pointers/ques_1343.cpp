class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int target = k*threshold,sum=0,count=0,left=0;
        for(int right=0;right<arr.size();right++){
            sum+=arr[right];
            if(right-left +1==k){
                if(sum>=target)count++;
                sum-=arr[left++];
            }
        }
        return count;
    }
};