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

map<int,int> M;
multiset<int> S;

class StockPrice {
public:
    StockPrice() {
        M.clear();
        S.clear();
    }
    
    void update(int timestamp, int price) {
        if(M.count(timestamp)) {
			S.erase(S.find(M[timestamp]));
		}
		M[timestamp]=price;
		S.insert(price);
    }
    
    int current() {
        return M.rbegin()->second;
    }
    
    int maximum() {
        return *S.rbegin();
    }
    
    int minimum() {
        return *S.begin();
        
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */