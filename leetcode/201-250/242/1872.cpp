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

const ll def=-(1LL<<60);
template<class V,int NV> class SegTree_1 {
public:
	vector<V> val;
	
	V comp(V l,V r){ return max(l,r);};
	
	SegTree_1(){val=vector<V>(NV*2,def);};
	V getval(int x,int y,int l=0,int r=NV,int k=1) { // x<=i<y
		if(r<=x || y<=l) return def;
		if(x<=l && r<=y) return val[k];
		return comp(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1));
	}
	void update(int entry, V v) {
		entry += NV;
		val[entry]=comp(v,val[entry]); //上書きかチェック
		while(entry>1) entry>>=1, val[entry]=comp(val[entry*2],val[entry*2+1]);
	}
};
SegTree_1<ll,1<<18> st;

ll dp[101010];
ll sum[101010];
vector<int> S;
int N;
class Solution {
public:
    int stoneGameVIII(vector<int>& S) {
		N=S.size();
		FORR(v,st.val) v=-(1LL<<60);
		
        int i;
		FOR(i,N) sum[i+1]=sum[i]+S[i];
		dp[N]=0;
		st.update(N,sum[N]);
        for(i=N-1;i>=2;i--) {
			dp[i]=st.getval(i+1,N+1);
			st.update(i,sum[i]-dp[i]);
			
		}
        
        ll ma=st.getval(2,N+1);
        return ma;
        
    }
};
