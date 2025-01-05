#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

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

template<class V,int NV> class SegTree_1 {
public:
	vector<V> val;
	V comp(V l,V r){
		V ret;
		ret[0]=l[0]+r[0];
		ret[1]=max(l[1],l[0]+r[1]);
		ret[2]=max(r[2],r[0]+l[2]);
		ret[3]=max({l[3],r[3],l[2]+r[1]});
		return ret;
	}
	
	SegTree_1(){val=vector<V>(NV*2);};
	void update(int entry, ll v) {
		entry += NV;
		val[entry]={v,max(v,0LL),max(v,0LL),v};
		while(entry>1) entry>>=1, val[entry]=comp(val[entry*2],val[entry*2+1]);
	}
};
// sum, left, right, max
SegTree_1<array<ll,4>,1<<20> st;



class Solution {
public:
    long long maxSubarraySum(vector<int>& nums) {
        int i;
        int N=nums.size();
        map<int,vector<int>> M;
        ll ret=-1LL<<60;
        FOR(i,N) {
			st.update(i,nums[i]);
			M[nums[i]].push_back(i);
			ret=max(ret,(ll)nums[i]);
		}
		if(ret<=0) return ret;
		ret=st.val[1][3];
		FORR(a,M) if(a.second.size()!=N) {
			FORR(v,a.second) st.update(v,0);
			ret=max(ret,st.val[1][3]);
			FORR(v,a.second) st.update(v,a.first);
		}
		
        FOR(i,N) {
			st.update(i,0);
		}
		return ret;
    }
};


 