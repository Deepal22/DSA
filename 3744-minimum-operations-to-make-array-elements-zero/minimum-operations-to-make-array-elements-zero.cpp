class Solution {
private:
    int flog4(int n){
        return (31-__builtin_clz(n)) >> 1;
    }
    long long pfx(int n){
        int p = flog4(n);
        long long pow4p = 1 << p*2;
        long long N = (3*p-1) * pow4p + 1;
        N /= 3;
        N += (p+1) * (n-pow4p+1);
        return N;
    }
public:
    long long minOperations(vector<vector<int>>& queries) {
        long long res = 0;
        for(auto &q: queries){
            long long N = pfx(q[1]);
            if(q[0]>1) N -= pfx(q[0]-1);
            res += (N>>1) + (N&1);
        }
        return res;
    }
};