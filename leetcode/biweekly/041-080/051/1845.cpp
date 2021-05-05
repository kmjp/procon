typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))

//-------------------------------------------------------


class SeatManager {
public:
	set<int> OK;
    SeatManager(int n) {
        OK.clear();
        int i;
        FOR(i,n) OK.insert(i+1);
    }
    
    int reserve() {
		int x=*OK.lower_bound(0);
		OK.erase(x);
		return x;
        
    }
    
    void unreserve(int seatNumber) {
        OK.insert(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */
 