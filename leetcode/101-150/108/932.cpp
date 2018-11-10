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

int A[1010];
class Solution {
public:
	vector<int> beautifulArray(int N) {
		vector<int> V;
		if(N<=2) {
			for(int i=1;i<=N;i++) V.push_back(i);
		}
		else {
			auto Vo=beautifulArray((N+1)/2);
			auto Ve=beautifulArray(N/2);
			FORR(v,Vo) V.push_back(v*2-1);
			FORR(v,Ve) V.push_back(v*2);
		}
		return V;
	}
};
