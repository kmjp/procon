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

vector<int> V;
class Solution {
public:

	int hoge(int d,int cur,int L,int R,int M) {
		if(L+1==R||d<0) return V[L]^M;
		
		int a=1<<d;
		int T=cur+a;
		int S=lower_bound(V.begin()+L,V.begin()+R,T)-V.begin();
		
		if(S==L) return hoge(d-1,T,L,R,M);
		if(S==R) return hoge(d-1,cur,L,R,M);
		
		if(M&a) {
			if(L<S) return hoge(d-1,cur,L,S,M);
			return hoge(d-1,T,S,R,M);
		}
		else {
			if(S<R) return hoge(d-1,T,S,R,M);
			return hoge(d-1,cur,L,S,M);
		}
		
		
		
		
	}
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        sort(ALL(nums));
        nums.erase(unique(ALL(nums)),nums.end());
        V=nums;
        vector<int> R;
        FORR(q,queries) {
			int x=lower_bound(ALL(nums),q[1]+1)-nums.begin();
			if(x==0) {
				R.push_back(-1);
			}
			else {
				R.push_back(hoge(29,0,0,x,q[0]));
			}
			
		}
		return R;
    }
};
