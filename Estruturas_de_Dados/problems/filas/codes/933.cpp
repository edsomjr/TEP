class RecentCounter {
public:
    queue<int> q;

    RecentCounter() {
        
    }
    
    int ping(int t) {

        q.push(t);

        while (not q.empty() and t - q.front() > 3000)
            q.pop();

        return q.size();
    }
};
