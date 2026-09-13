class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> mt, ms;
    for(char c : t){
        mt[c]++;
    }

    int required = mt.size();
    int formed = 0;
    int left = 0, right = 0;
    int bestLen = INT_MAX, bestLeft = 0;

    for(int i = 0; i < s.size(); i++){
        right = i;
        if(mt.count(s[i]) != 0){
            ms[s[i]]++;
            if(ms[s[i]] == mt[s[i]]){
                formed++;
            }
        }

        while(formed == required){
            if(right - left + 1 < bestLen){
                bestLen = right - left + 1;
                bestLeft = left;
            }

            if(mt.count(s[left]) != 0){
                ms[s[left]]--;
                if(ms[s[left]] < mt[s[left]]){
                    formed--;
                }
            }
            left++;
        }
    }

    if(bestLen == INT_MAX) return "";
    return s.substr(bestLeft, bestLen);
    }
};
