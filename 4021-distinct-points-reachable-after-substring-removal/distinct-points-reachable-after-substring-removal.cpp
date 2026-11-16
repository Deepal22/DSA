class Solution {
public:
    int distinctPoints(string s, int k) {
        set<pair<int,int>> seen;
        seen.insert({0, 0});
        int x = 0, y = 0;
        for (int i = k; i < s.size(); i++) {
            // add new step
            if (s[i] == 'U') y++;
            if (s[i] == 'D') y--;
            if (s[i] == 'L') x++;
            if (s[i] == 'R') x--;
            // remove old step
            if (s[i - k] == 'U') y--;
            if (s[i - k] == 'D') y++;
            if (s[i - k] == 'L') x--;
            if (s[i - k] == 'R') x++;
            seen.insert({x, y});
        }
        return seen.size();
    }
};