class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> m;
        int maxFreq = 0;
        int left = 0;
        int maxLen = 0;

        for (int right = 0; right < s.size(); right++) {
            m[s[right]]++;
            maxFreq = max(maxFreq, m[s[right]]);

            while ((right - left + 1) - maxFreq > k) {
                m[s[left]]--;
                left++;
            }

            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};
