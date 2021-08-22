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


class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
		vector<int> V;
		int cand=0;
		FORR(a,matrix) FORR(v,a) {
			if(v<=0) cand++;
			V.push_back(abs(v));
		}
		sort(ALL(V));
		if(cand%2) V[0]*=-1;
		ll sum=0;
		FORR(v,V) sum+=v;
		return sum;
        
    }
};
