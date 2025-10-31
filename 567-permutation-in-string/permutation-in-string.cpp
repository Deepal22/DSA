class Solution {
private:
    bool CheckEqual(int a[26], int b[26]){
        for(int i = 0; i < 26; i++){
            if(a[i] != b[i]) return 0;
        }
        return 1;
    }

public:
    bool checkInclusion(string s1, string s2) {
        int cnt[26] = {0};

        for(int i = 0; i < s1.length(); i++){
            int index = s1[i] - 'a';
            cnt[index]++;
        }

        int i = 0;
        int window = s1.length();
        int count[26] = {0};
        while(i < window && i < s2.length()){
            int index = s2[i] - 'a';
            count[index]++;
            i++;
        }
        if(CheckEqual(cnt, count)) return 1;

        while(i < s2.length()){
            char ch = s2[i];
            int index = ch - 'a';
            count[index]++;

            char ch1 = s2[i - window];
            index = ch1 - 'a';
            count[index]--;
            i++;

            if(CheckEqual(cnt, count)) return 1;
        }
        return 0;
    }
};