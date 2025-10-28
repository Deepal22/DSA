class Solution {
public:
    void reverseString(vector<char>& s) {
        int cnt = 0;
        int e = s.size() - 1;

        while(cnt < e){
            swap(s[cnt++], s[e--]);
        }
    }
};