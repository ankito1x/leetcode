
struct Packet {
    int source;
    int destination;
    int timestamp;
   
    bool operator==(Packet const &o) const {
        return source==o.source && destination==o.destination && timestamp==o.timestamp;
    }
};
struct PacketHash {
    size_t operator()(Packet const &p) const {
        size_t h1 = std::hash<int>()(p.source);
        size_t h2 = std::hash<int>()(p.destination);
        size_t h3 = std::hash<int>()(p.timestamp);
        return h1 ^ (h2 << 1) ^ (h3 << 2);
    }
};

class Router {
public:
    Router(int memoryLimit) : memoryLimit_(memoryLimit), currentSize_(0) {}

    bool addPacket(int source, int destination, int timestamp) {
        Packet p{source, destination, timestamp};
        if (packetSet_.find(p) != packetSet_.end()) {
            return false;
        }
        if (currentSize_ == memoryLimit_) {
           
            forwardPacket(); 
        }
      
        packetsQueue_.emplace_back(p);
        packetSet_.insert(p);
        destTimestamps_[destination].push_back(timestamp);
     
        ++currentSize_;
        return true;
    }

    vector<int> forwardPacket() {
        if (packetsQueue_.empty()) {
            return {};
        }
        Packet oldest = packetsQueue_.front();
        packetsQueue_.pop_front();
        packetSet_.erase(oldest);
        
        destRemovedCount_[oldest.destination]++;
        --currentSize_;
        return {oldest.source, oldest.destination, oldest.timestamp};
    }

    int getCount(int destination, int startTime, int endTime) {
        auto it = destTimestamps_.find(destination);
        if (it == destTimestamps_.end()) return 0;
        vector<int> &ts = it->second;
        int removed = destRemovedCount_[destination];
       
        auto lb = std::lower_bound(ts.begin() + removed, ts.end(), startTime);
        auto ub = std::upper_bound(ts.begin() + removed, ts.end(), endTime);
        return int(ub - lb);
    }

private:
    int memoryLimit_;
    int currentSize_;
    deque<Packet> packetsQueue_;
    unordered_set<Packet, PacketHash> packetSet_;
    unordered_map<int, vector<int>> destTimestamps_;
    unordered_map<int, int> destRemovedCount_;  
};
