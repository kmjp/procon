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

vector<ll> V[11];
class Solution {
public:
    vector<int> countSteppingNumbers(int low, int high) {
			int i;
		
		if(V[0].empty()) {
			V[0].push_back(0);
			for(i=1;i<=9;i++) V[1].push_back(i);
			for(i=2;i<=10;i++) {
				FORR(v,V[i-1]) {
					int d=v%10;
					if(d>0) V[i].push_back(v*10+(d-1));
					if(d<9) V[i].push_back(v*10+(d+1));
				}
			}
		}
		
		vector<int> R;
		FOR(i,11) FORR(v,V[i]) if(v>=low && v<=high) R.push_back(v);
		sort(ALL(R));
		return R;
		
        
    }
};
