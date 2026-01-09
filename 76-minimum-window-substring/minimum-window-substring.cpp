class Solution {
public:
    string minWindow(string s, string t) 
    {
        if (s.size() == 0) return "";

        if (s.size() < t.size()) return "";

        int count = t.size();
        int start = 0;
        int minStart = -1;
        int minLen = s.size() +1;
        
        unordered_map<int,int>mp;
        for (int i = 0; i < t.size(); i++) mp[t[i]]++;

        for (int i = 0; i < s.size(); i++)
        {
            if(mp[s[i]] -- > 0) count--;

            // cout<<count;
            while (count == 0)
            {
                int len = i - start + 1;
                // cout << len;
                if (minLen > len)
                {
                    minLen = len;
                    minStart = start;
                }

                if (++mp[s[start++]] > 0) count ++;
            }
        }

        return minStart == -1 ? "" : s.substr(minStart, minLen);
    }
};