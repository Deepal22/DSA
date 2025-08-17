class Solution {
public:
    double new21Game(int n, int k, int maxPts) {        
    vector<double> P(n + 1, 0.0);

    P[0] = 1;

    double currProbSum = (k == 0) ? 0 : 1;

    for (int i = 1; i <= n; i++) {
        P[i] = currProbSum / maxPts;

        if (i < k)
            currProbSum += P[i];

        if (i - maxPts >= 0 && i - maxPts < k)
            currProbSum -= P[i - maxPts];
    }

    return accumulate(begin(P) + k, end(P), 0.0);
}
};