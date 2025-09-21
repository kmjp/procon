#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------

template<class V,int NV> class SegTree_ma {
public:
	vector<V> val;
	static V const def=-1<<30;
	V comp(V l,V r){ return max(l,r);};
	
	SegTree_ma(){val=vector<V>(NV*2,def);};
	V getval(int x,int y,int l=0,int r=NV,int k=1) { // x<=i<y
		if(r<=x || y<=l) return def;
		if(x<=l && r<=y) return val[k];
		return comp(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1));
	}
	void update(int entry, V v) {
		entry += NV;
		val[entry]=v;
		while(entry>1) entry>>=1, val[entry]=comp(val[entry*2],val[entry*2+1]);
	}
};
SegTree_ma<int,1<<20> stma,stmi;

int R[101010];
ll V[101010];
class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
		int N=nums.size();
		int i,j;
		ll ret=0;
		FOR(i,N) {
			R[i]=N-1;
			stma.update(i,nums[i]);
			stmi.update(i,-nums[i]);
		}
		priority_queue<pair<ll,int>> Q;
		FOR(i,N) {
			V[i]=stma.getval(i,N)+stmi.getval(i,N);
			Q.push({V[i],i});
		}
		while(k--) {
			auto p=Q.top();
			Q.pop();
			ret+=p.first;
			i=p.second;
			R[i]--;
			if(R[i]>=i) {
				V[i]=stma.getval(i,R[i]+1)+stmi.getval(i,R[i]+1);
				Q.push({V[i],i});
			}
		}
		return ret;
        
    }
};
