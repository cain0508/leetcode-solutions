class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int n = arr.size();
    if (n < k || n == 0) return -1;

    int left = 0, right = k;
    int window_sum = 0, count = 0;

    for (int i = 0; i < k; i++) window_sum += arr[i];
    if (double(window_sum) / k >= threshold) count++;

    while (right < n) {
        window_sum += arr[right] - arr[left];
        if (double(window_sum) / k >= threshold) count++;
        left++;
        right++;
        }
        return count;
    }
};