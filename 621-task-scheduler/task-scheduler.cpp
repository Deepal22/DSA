#include<algorithm>
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int mx=0, mxCount=0;
        vector<int> freq(26, 0);
        for(auto c: tasks){
            freq[c-'A']++;
            if(mx<freq[c-'A']){
                mx=freq[c-'A'];
                mxCount=1;
            }
            else if(mx==freq[c-'A'])
                mxCount++;
        }
        int partCount = mx-1;
        int partLength = n-(mxCount-1);
        int emptySlots = partCount*partLength;
        int availableTasks = tasks.size() - mx*mxCount;
        int idles = max(0, emptySlots - availableTasks);
        return tasks.size()+idles;
    }
};