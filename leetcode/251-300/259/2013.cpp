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




class DetectSquares {
public:
	map<pair<int,int>,int> S;
	
    DetectSquares() {
		S.clear();
        
    }
    
    void add(vector<int> point) {
        S[{point[0],point[1]}]++;
    }
    
    int count(vector<int> point) {
        ll ret=0;
        int x=point[0],y=point[1];
        FORR(t,S) {
			auto a=t.first;
			auto b=t.second;
			if(x==a.first||y==a.second) continue;
			if(abs(x-a.first)!=abs(y-a.second)) continue;
			ll pat=b;
			if(S.count({x,a.second})==0) continue;
			pat*=S[{x,a.second}];
			if(S.count({a.first,y})==0) continue;
			pat*=S[{a.first,y}];
			ret+=pat;
			
		}
        return ret;
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */
 