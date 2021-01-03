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



static int const def=1<<20;
template<class V,int NV> class SegTree_1 {
public:
	vector<V> val;
	V comp(V l,V r){ return min(l,r);};
	
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



map<int,int> M;
SegTree_1<int,1<<17> st;
int C[1<<20];

class Solution {
public:
    int minOperations(vector<int>& target, vector<int>& arr) {
		int N=target.size();
		int i;
		M.clear();
		FORR(v,st.val) v=1<<20;
		st.update(0,N);
		
		FOR(i,N) {
			M[target[i]]=i+1;
			C[i+1]=1<<20;
		}
		FORR(a,arr) if(M.count(a)) {
			int x=M[a];
			int c=st.getval(0,x)-(N-x)-1;
			if(c<C[x]) {
				C[x]=c;
				st.update(x,c+(N-x));
			}
		}
        return st.getval(0,N+1);
    }
};
