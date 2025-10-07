class Solution {
public:
    std::vector<int> avoidFlood(std::vector<int>& rains) {
        int n = rains.size();
        std::vector<int> ans(n, -1);
        std::unordered_map<int, int> lastRainDay; 
        std::set<int> sunnyDays; 
        for (int i = 0; i < n; i++) {
            int lake = rains[i];

            if (lake > 0) { 
                
                if (lastRainDay.count(lake)) {
                    int lastFullDay = lastRainDay[lake];
                    auto it = sunnyDays.upper_bound(lastFullDay);
                    
                    if (it == sunnyDays.end()) {
                        
                        return {}; 
                    }
                    
                    int dryDayIndex = *it;
                    ans[dryDayIndex] = lake;
                    
                   
                    sunnyDays.erase(it);
                }
                lastRainDay[lake] = i;
                ans[i] = -1; 
                
            } else { 
                
            
                sunnyDays.insert(i);
                ans[i] = 1; 
            }
        }
        return ans;
    }
};