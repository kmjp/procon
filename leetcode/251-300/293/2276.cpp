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


set<pair<int,int>> S;
ll sum=0;
class CountIntervals {
public:
	
    CountIntervals() {
        S.clear();
        S.insert({-1,-1});
        S.insert({1<<30,1<<30});
        sum=0;
    }
    
    void add(int L, int R) {
		R++;
		auto it=S.lower_bound({L,0});
		it--;
		if(it->second>=R) {
			return;
		}
		if(it->second>=L) {
			sum-=it->second-it->first;
			L=it->first;
			S.erase(it);
		}
		while(1) {
			auto it=S.lower_bound({L,0});
			if(it->first>=R) break;
			if(it->second>=R) {
				pair<int,int> a=*it;
				sum-=R-a.first;
				a.first=R;
				S.erase(it);
				S.insert(a);
				break;
			}
			sum-=it->second-it->first;
			S.erase(it);
		}
		S.insert({L,R});
		sum+=R-L;
        
    }
    
    int count() {
        return sum;
    }
};

/**
 * Your CountIntervals object will be instantiated and called as such:
 * CountIntervals* obj = new CountIntervals();
 * obj->add(left,right);
 * int param_2 = obj->count();
 */
 