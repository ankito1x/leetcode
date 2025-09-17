class MyCalendar {
    vector<pair<int,int>> books; 
public:
    MyCalendar() {}

    bool book(int start, int end) {
        for (auto &b : books) {
            int s = b.first, e = b.second;
            
            if (start < e && end > s) return false;
        }
        books.push_back({start, end});
        return true;
    }
};