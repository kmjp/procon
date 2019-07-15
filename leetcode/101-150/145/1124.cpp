
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

const int def=1<<30;
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
		val[entry]=comp(v,val[entry]);
		while(entry>1) entry>>=1, val[entry]=comp(val[entry*2],val[entry*2+1]);
	}
};

class Solution {
public:

    int longestWPI(vector<int>& hours) {
		SegTree_1<int,1<<14> st;
		int cur=10005;
		int ma=0;
		int i;
		st.update(cur,0);
		FOR(i,hours.size()) {
			if(hours[i]<=8) cur--;
			else cur++;
			
			int lef=st.getval(0,cur);
			ma=max(ma,i+1-lef);
			st.update(cur,i+1);
		}
		return ma;
		
        
    }
    
};

