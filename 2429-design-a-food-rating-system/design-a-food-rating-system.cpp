class FoodRatings {
    
    unordered_map<string, pair<string,int>> info;
    
    unordered_map<string, set<pair<int,string>>> byCuisine;

public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n = foods.size();
        for (int i = 0; i < n; ++i) {
            info[foods[i]] = {cuisines[i], ratings[i]};
            byCuisine[cuisines[i]].insert({-ratings[i], foods[i]});
        }
    }

    void changeRating(string food, int newRating) {
        auto &p = info[food];
        string cuisine = p.first;
        int oldRating = p.second;
        
        byCuisine[cuisine].erase({-oldRating, food});
        byCuisine[cuisine].insert({-newRating, food});
        p.second = newRating;
    }

    string highestRated(string cuisine) {

        auto &s = byCuisine[cuisine];
        return s.begin()->second;
    }
};