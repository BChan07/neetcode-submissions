class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<string> strc = strs;
        unordered_map<string, vector<string>> ret;
        vector<vector<string>> retf;

        //Sorting each string in the copy of the string array
        for(int i=0; i < strc.size(); i++){
            sort(strc[i].begin(), strc[i].end());
        }

        for(int i = 0; i < strc.size(); i++){
            if(!ret.count(strc[i])){
                vector<string> dem;
                dem.push_back(strs[i]);
                ret[strc[i]] = dem;
            }
            else{
                ret[strc[i]].push_back(strs[i]);
            }
        }

        for(auto& pair : ret){
            retf.push_back(pair.second);
        }
        return retf;
    }
};
