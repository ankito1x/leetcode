class Solution {
public:
    int maxGap(vector<int>& bars) {
        sort(bars.begin(), bars.end());
        int longest = 1, curr = 1;

        for (int i = 1; i < bars.size(); i++) {
            if (bars[i] == bars[i - 1] + 1) {
                curr++;
                longest = max(longest, curr);
            } else {
                curr = 1;
            }
        }
        return longest + 1;
    }

    int maximizeSquareHoleArea(int n, int m,
                               vector<int>& hBars,
                               vector<int>& vBars) {
        int h = maxGap(hBars);
        int v = maxGap(vBars);
        int side = min(h, v);
        return side * side;
    }
};

