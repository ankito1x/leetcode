class Solution {
public:
    int countPermutations(vector<int>& complexity) {
        const int MOD = 1000000007;
        int n = complexity.size();
        for (int i = 1; i < n; ++i) {
            if (complexity[i] <= complexity[0]) {
                return 0;
            }
        }
        long long fact = 1;
        for (int i = 1; i < n; ++i) {
            fact = (fact * i) % MOD;
        }      
        return fact;
    }
};
