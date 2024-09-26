class MyCalendar {
private:
    set<pair<int,int>> calendar;
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        pair<int,int> event{start,end};
        auto next = calendar.lower_bound(event);
        if(next != calendar.end() && next->first < end) return false;
        if(next!=calendar.begin()){
            auto pre = prev(next);
            if(pre->second > start) return false;
        }
        calendar.insert(event);
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */