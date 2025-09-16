class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<long long> st; 
        for (int v : nums) {
            long long cur = v;
            
            while (!st.empty()) {
                long long top = st.back();
                long long g = std::gcd(top, cur);
                if (g == 1) break; 
                st.pop_back();
                
                cur = (top / g) * cur;
            }
            st.push_back(cur);
        }
        
        vector<int> ans;
        ans.reserve(st.size());
        for (long long x : st) ans.push_back((int)x);
        return ans;
    }
};