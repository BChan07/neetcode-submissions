class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max = 0, profit = 0;
        vector<pair<int,int>> m;

        for(int i = 0; i < prices.size()-1; i++){
            for(int j = i+1; j < prices.size(); j++){
                if(prices[j] > max){
                    max = prices[j];
                }
            }
            m.push_back({prices[i], max});
            max = 0;
        }
        m.push_back({prices[prices.size()-1], 0});

        for(auto& pair : m){
            profit = pair.second - pair.first;
            if(profit > max){
                max = profit;
            }
        }
        return max;
    }
};
