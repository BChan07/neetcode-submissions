class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ret;
        unordered_map<int, int> store;

        if (nums.size() == 0 || k == 0) return ret;

        for (int i : nums) {
            store[i]++;
        }

        // Copy into a vector of pairs so we can sort by frequency
        vector<pair<int,int>> freq(store.begin(), store.end());

        sort(freq.begin(), freq.end(), [](const pair<int,int>& a, const pair<int,int>& b) {
            return a.second > b.second;  // descending by frequency
        });

        for (int i = 0; i < k && i < (int)freq.size(); i++) {
            ret.push_back(freq[i].first);
        }

        return ret;
    }
};
