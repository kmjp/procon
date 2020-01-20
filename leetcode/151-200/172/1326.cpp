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

template<class V,int NV> class SegTree_1 {
public:
	vector<V> val;
	V comp(V l,V r){ return min(l,r);};
	
	SegTree_1(){val=vector<V>(NV*2,1<<30);};
	V getval(int x,int y,int l=0,int r=NV,int k=1) { 
		if(r<=x || y<=l) return 1<<30;
		if(x<=l && r<=y) return val[k];
		return comp(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1));
	}
	void update(int entry, V v) {
		entry += NV;
		val[entry]=comp(v,val[entry]);
		while(entry>1) entry>>=1, val[entry]=comp(val[entry*2],val[entry*2+1]);
	}
};

class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
		SegTree_1<ll,1<<16> st;
		st.update(n+1,0);
		int i;
		FOR(i,n+1) {
			int pos=i+(n+1);
			ll v=st.getval(pos-ranges[i],pos+ranges[i]+1);
			st.update(pos+ranges[i],v+1);
		}
		ll ret=st.getval(n+1+n,1<<15);
		if(ret>n) ret=-1;
        return ret;
    }
};

