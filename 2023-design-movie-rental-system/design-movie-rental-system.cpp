

class MovieRentingSystem {
    
    unordered_map<int, set<pair<int,int>>> unrented;
    
    set<tuple<int,int,int>> rented;
    unordered_map<long long,int> priceMap;

    long long key(int shop, int movie) {
        return ( (long long)shop << 32 ) | (unsigned)movie;
    }

public:
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for (auto &e : entries) {
            int shop = e[0], movie = e[1], price = e[2];
            unrented[movie].insert({price, shop});
            priceMap[key(shop,movie)] = price;
        }
    }

    vector<int> search(int movie) {
        vector<int> ans;
        if (!unrented.count(movie)) return ans;
        auto &s = unrented[movie];
        int cnt = 0;
        for (auto it = s.begin(); it != s.end() && cnt < 5; ++it, ++cnt) {
            ans.push_back(it->second); 
        }
        return ans;
    }

    void rent(int shop, int movie) {
        long long k = key(shop, movie);
        int price = priceMap[k];
        
        auto &s = unrented[movie];
        auto it = s.find({price, shop});
        if (it != s.end()) s.erase(it);
    
        rented.emplace(price, shop, movie);
    }

    void drop(int shop, int movie) {
        long long k = key(shop, movie);
        int price = priceMap[k];
     
        auto it = rented.find({price, shop, movie});
        if (it != rented.end()) rented.erase(it);
    
        unrented[movie].insert({price, shop});
    }

    vector<vector<int>> report() {
        vector<vector<int>> ans;
        int cnt = 0;
        for (auto it = rented.begin(); it != rented.end() && cnt < 5; ++it, ++cnt) {
            int price, shop, movie;
            tie(price, shop, movie) = *it;
            ans.push_back({shop, movie});
        }
        return ans;
    }
};