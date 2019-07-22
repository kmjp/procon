
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

pair<ll,ll> memo[41][41];

class Solution {
public:
	vector<int> V;
	pair<ll,ll> hoge(int L,int R) {
		if(L+1==R) return {V[L],0};
		if(memo[L][R].first>=0) return memo[L][R];
		
		pair<ll,ll> p={1LL<<33,1LL<<33};
		int i;
		for(i=L;i<R-1;i++) {
			auto a=hoge(L,i+1);
			auto b=hoge(i+1,R);
			pair<ll,ll> c={max(a.first,b.first),a.second+b.second+a.first*b.first};
			p=min(p,c);
			
		}
		
		
		return memo[L][R]=p;
		
	}
    int mctFromLeafValues(vector<int>& arr) {
		MINUS(memo);
		V=arr;
		return hoge(0,arr.size()).second;
    }
};

