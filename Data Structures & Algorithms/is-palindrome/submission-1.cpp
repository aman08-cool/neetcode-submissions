class Solution {
public:
    bool isPalindrome(string s) {
        string str = "";
        for(auto& it : s){
            if(isalnum(it)){
                str += tolower(it);
            }
        }
        string rev = str;
        reverse(str.begin(), str.end());
        return str == rev;
    }
};
