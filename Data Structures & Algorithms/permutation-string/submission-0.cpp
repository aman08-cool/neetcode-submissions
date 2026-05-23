class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()) return false;
        vector<int> f1(26,0), f2(26,0);
        //frequency of s1
        for(auto i : s1){
            f1[i-'a']++;
        }
        //frequency of s2 upto length of s1
        for(int i = 0 ; i < s1.size() ; i++){
            f2[s2[i]-'a']++;
        }
        //check if first window matches
        if(f1 == f2) return true;

        //check for others
        for(int i = s1.size() ; i < s2.size() ; i++){
            f2[s2[i]-'a']++;
            f2[s2[i-s1.size()]-'a']--;
            if(f1 == f2) return true;
        }
        return false;


    }
};
