class Solution {
   public:
    bool isPalindrome(string s) {
        string str = "";
        for (char it : s) {
            if (isalnum(it)) {
                str += tolower(it);
            }
        }
        int l = 0, r = str.length() - 1;
        while (l <= r) {
            if (str[l] != str[r]) {
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
};
