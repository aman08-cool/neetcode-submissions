class Solution {
public:
    unordered_map<string,vector<string>> mp;
    int index = 0;
    string encode(vector<string>& strs) {
        index++;
        string id = to_string(index);
        mp[id] = strs;
        return id;  
    }
    vector<string> decode(string id) {
        return mp[id];
    }
};
