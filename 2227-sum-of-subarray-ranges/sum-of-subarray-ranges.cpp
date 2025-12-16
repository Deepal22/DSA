class Solution {
public:
    long long sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        // Arrays to store distances to the previous/next smaller element
        vector<int> lefts(n), rights(n);
        stack<int> s;

        //next smaller element
        for(int i=n-1;i>=0;i--){
            while(!s.empty() && arr[s.top()]>=arr[i]){
                s.pop();
            }
            if (s.empty()) rights[i] =n;
            else rights[i] =s.top();
            s.push(i);
        }
        while(!s.empty()) s.pop();
        //previous smaller and equal element
        for(int i=0;i<n;i++){
            while(!s.empty() && arr[s.top()]>arr[i]){
                s.pop();
            }
            lefts[i]= s.empty() ? -1:s.top();
            s.push(i);
        }
        long long total = 0;
        for(int i=0;i<n;i++){
            int l= i-lefts[i];
            int r=rights[i]-i;
            long long count=(long long) l*r;
            long long contribution=count*arr[i];
            total =total+contribution;
        }
        return total;
    }
    long long sumSubarrayMaxs(vector<int>& arr) {
        int n = arr.size();
        // Arrays to store distances to the previous/next smaller element
        vector<int> leftl(n), rightl(n);
        stack<int> s;

        //next larger element
        for(int i=n-1;i>=0;i--){
            while(!s.empty() && arr[s.top()]<=arr[i]){
                s.pop();
            }
            if (s.empty()) rightl[i] =n;
            else rightl[i] =s.top();
            s.push(i);
        }
        while(!s.empty()) s.pop();
        //previous larger and equal element
        for(int i=0;i<n;i++){
            while(!s.empty() && arr[s.top()]<arr[i]){
                s.pop();
            }
            leftl[i]= s.empty() ? -1:s.top();
            s.push(i);
        }
        long long total = 0;
        for(int i=0;i<n;i++){
            int l= i-leftl[i];
            int r=rightl[i]-i;
            long long count=(long long) l*r;
            long long contribution=count*arr[i];
            total =total+contribution;
        }
        return total;
    }
    long long subArrayRanges(vector<int>& arr) {
        int n=arr.size();
        long long largest_total=sumSubarrayMaxs(arr);
        long long smallest_total=sumSubarrayMins(arr);
        return largest_total-smallest_total;
    }
};