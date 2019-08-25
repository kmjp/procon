
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

vector<int> ST[120202];
set<int> C;
set<int> F;

int cap;
class DinnerPlates {
public:

    DinnerPlates(int capacity) {
		cap=capacity;
        C.clear();
        F.clear();
        int i;
        FOR(i,100000) {
			ST[i].clear();
			C.insert(i);
		}
    }
    
    void push(int val) {
		int x=*C.begin();
		ST[x].push_back(val);
		F.insert(x);
		if(ST[x].size()==cap) C.erase(x);
    }
    
    int pop() {
        if(F.empty()) return -1;
        return popAtStack(*F.rbegin());
    }
    
    int popAtStack(int index) {
		if(ST[index].empty()) {
			return -1;
		}
		else {
			int x=ST[index].back();
			ST[index].pop_back();
			C.insert(index);
			
			if(ST[index].empty()) F.erase(index);
			return x;
		}
        
    }
};


