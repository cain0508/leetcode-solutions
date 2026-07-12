class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        if(n == 0){
            return {};
        }
        vector<pair<int,int>> temp(n);
        for(int i = 0 ; i < n ; i++){
            temp[i].first = arr[i];
            temp[i].second = i;
        }
        sort(temp.begin() , temp.end());
        vector<int> ranks(n);
        int currRank = 1;
        ranks[temp[0].second] = 1;
        for(int i = 1 ; i < n ; i++){
            if(temp[i].first != temp[i-1].first){
                currRank++;
            }
            ranks[temp[i].second] = currRank;
        }
        return ranks;
    }
};