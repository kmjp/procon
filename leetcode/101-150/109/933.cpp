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

class RecentCounter {
public:
	set<int> S;
    RecentCounter() {
    }
    
    int ping(int t) {
		while(S.size() && *S.begin()<t-3000) S.erase(S.begin());
		S.insert(t);
		return S.size();
    }
};
