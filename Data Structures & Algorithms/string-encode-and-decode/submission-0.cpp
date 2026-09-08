class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded;
        for (const string& s : strs) {
            encoded += to_string(s.size()) + "#" + s;
        }
        return encoded;
    }

    vector<string> decode(string s) {
        vector<string> decoded;
        int i = 0;
        while (i < (int)s.size()) {
            int j = i;
            while (s[j] != '#') j++;          // find the delimiter
            int len = stoi(s.substr(i, j - i)); // parse the length
            string str = s.substr(j + 1, len);  
            decoded.push_back(str);
            i = j + 1 + len;                    // move past this entry
        }
        return decoded;
    }
};
