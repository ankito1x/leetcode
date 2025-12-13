class Solution {
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        vector<int> validIndices;
        unordered_set<string> validLines = {"electronics", "grocery", "pharmacy", "restaurant"};
        
        for (int i = 0; i < code.size(); ++i) {
            if (isActive[i] && validLines.count(businessLine[i]) && isValidCode(code[i])) {
                validIndices.push_back(i);
            }
        }
        sort(validIndices.begin(), validIndices.end(), [&](int a, int b) {
            if (businessLine[a] != businessLine[b]) {
                return businessLine[a] < businessLine[b]; 
            }
            return code[a] < code[b];
        });
        
        vector<string> result;
        for (int idx : validIndices) {
            result.push_back(code[idx]);
        }
        return result;
    }
    
private:
    bool isValidCode(const string& s) {
        if (s.empty()) return false;
        for (char c : s) {
            if (!isalnum(c) && c != '_') return false;
        }
        return true;
    }
};
