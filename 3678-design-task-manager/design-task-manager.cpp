class TaskManager {
private:
   
    unordered_map<int, pair<int,int>> taskMap;
    
    set<pair<long long, long long>> taskSet;

public:
    TaskManager(vector<vector<int>>& tasks) {
        for (auto &t : tasks) {
            int userId = t[0];
            int taskId = t[1];
            int priority = t[2];
            add(userId, taskId, priority);
        }
    }

    void add(int userId, int taskId, int priority) {
        taskMap[taskId] = {userId, priority};
       
        taskSet.insert({- (long long)priority, - (long long)taskId});
    }

    void edit(int taskId, int newPriority) {
        auto it = taskMap.find(taskId);
        if (it == taskMap.end()) return;  
        
        int oldPriority = it->second.second;
        int userId = it->second.first;
        
        taskSet.erase({- (long long)oldPriority, - (long long)taskId});
        
        taskSet.insert({- (long long)newPriority, - (long long)taskId});
        it->second.second = newPriority;
    }

    void rmv(int taskId) {
        auto it = taskMap.find(taskId);
        if (it == taskMap.end()) return;
        int priority = it->second.second;
        taskSet.erase({- (long long)priority, - (long long)taskId});
        taskMap.erase(it);
    }

    int execTop() {
        if (taskSet.empty()) return -1;
        auto top = *taskSet.begin();
        taskSet.erase(taskSet.begin());
        long long negTaskId = top.second;
        int taskId = (int)(-negTaskId);
        int userId = taskMap[taskId].first;
        taskMap.erase(taskId);
        return userId;
    }
};