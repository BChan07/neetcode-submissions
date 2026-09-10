class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max = 0;
        int i, j=0;
        set<char> c;
        for(i = 0; i < s.size(); i++){
            if(!c.contains(s[i])){
                c.insert(s[i]);
            }
            else{
                if(s[j] == s[i]){
                    j++;
                }
                else{
                    if((i-j)>max) max = i-j;
                    
                    while(s[j] != s[i]){
                        c.erase(s[j]);
                        j++;
                    }
                    j++;
                    c.insert(s[i]);
                }
            }
        }
        if((i-j)>max) max = i-j;
        return max;
    }
};
