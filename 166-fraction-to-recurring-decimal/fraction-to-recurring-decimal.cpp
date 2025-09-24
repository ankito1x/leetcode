
class Solution {
public:
    string fractionToDecimal(long long numerator, long long denominator) {
        if (numerator == 0) return "0";
        string result;
        if ((numerator < 0) ^ (denominator < 0)) result += "-";
        long long n = llabs(numerator);
        long long d = llabs(denominator);
        result += to_string(n / d);
        long long remainder = n % d;
        if (remainder == 0) return result;
        result += ".";
        unordered_map<long long, int> remPos;
        while (remainder != 0) {
            if (remPos.find(remainder) != remPos.end()) {
                int idx = remPos[remainder];
                result.insert(idx, "(");
                result += ")";
                return result;
            }
            remPos[remainder] = result.size();
            remainder *= 10;
            result += to_string(remainder / d);
            remainder %= d;
        }
        return result;
    }
};
