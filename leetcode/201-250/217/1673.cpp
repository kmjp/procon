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
template<class V,int NV> class SegTree_Pair {
public:
	vector<pair<V,int> > val;
	pair<V,int> comp(pair<V,int> l,pair<V,int> r){ return min(l,r);}
	SegTree_Pair(){
		val.resize(NV*2);
		int i;
		FOR(i,NV) val[i+NV]=make_pair(def,i);
		for(i=NV-1;i>=1;i--) val[i]=comp(val[2*i],val[2*i+1]);
	};
	pair<V,int> getval(int x,int y,int l=0,int r=NV,int k=1) {
		if(r<=x || y<=l) return make_pair(def,NV);
		if(x<=l && r<=y) return val[k];
		return comp(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1));
	}
	void update(int entry, V v) {
		entry += NV;
		val[entry]=make_pair(v,entry-NV);
		while(entry>1) entry>>=1, val[entry]=comp(val[entry*2],val[entry*2+1]);
	}
};

class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
		SegTree_Pair<int,1<<17> st;
		int i,N=nums.size();
		FOR(i,N) st.update(i,nums[i]);
		int cur=-1;
		vector<int> ret;
		while(k) {
			auto p=st.getval(cur+1,N+1-k);
			ret.push_back(p.first);
			cur=p.second;
			
			
			k--;
		}
        return ret;
    }
};
