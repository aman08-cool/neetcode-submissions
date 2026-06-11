class Solution {
public:
    bool isPalindrome(string str) {
        string st = "";
        for(auto it : str){
            if(isalnum(it)){
                st += tolower(it);
            }
        }
        int s = 0, e = st.size()-1;
        while( s <= e){
            if(st[s] != st[e]){
                return false;
            }
            s++;
            e--;
        }
        return true;
    }
};
