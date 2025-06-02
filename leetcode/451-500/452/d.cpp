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

static ll const def=-1<<20;
template<class V,int NV> class SegTree_3 {
public:
	vector<V> val, ma;
	SegTree_3(){
		int i;
		val.resize(NV*2,0); ma.resize(NV*2,0);
	};
	
	V getval(int x,int y,int l=0,int r=NV,int k=1) {
		if(r<=x || y<=l || y<=x) return def;
		if(x<=l && r<=y) return ma[k];
		return val[k]+max(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1));
	}
	
	void update(int x,int y, V v,int l=0,int r=NV,int k=1) {
		if(l>=r||y<=x) return;
		if(x<=l && r<=y) {
			val[k]+=v;
			ma[k]+=v;
		}
		else if(l < y && x < r) {
			update(x,y,v,l,(l+r)/2,k*2);
			update(x,y,v,(l+r)/2,r,k*2+1);
			ma[k]=val[k]+max(ma[k*2],ma[k*2+1]);
		}
	}
};
SegTree_3<int,1<<20> st;

const int prime_max = 1010101;
vector<int> prime;
int NP,divp[prime_max];

void cprime() {
	if(NP) return;
	divp[1]=1;
	for(int i=2;i<prime_max;i++) if(divp[i]==0) {
		//M[i]=NP;
		prime.push_back(i); NP++;
		for(ll j=1LL*i*i;j>=i&&j<prime_max;j+=i) if(divp[j]==0) divp[j]=i;
	}
}

set<int> S[101010];

class Solution {
public:
	int N;
	void add(int a,int b) {
		if(divp[a]) return;
		if(S[a].empty()) {
			S[a].insert(b);
			st.update(0,N-1,1);
		}
		else if(S[a].size()==1) {
			S[a].insert(b);
			st.update(*S[a].begin(),*S[a].rbegin(),1);
		}
		else {
			st.update(*S[a].begin(),*S[a].rbegin(),-1);
			S[a].insert(b);
			st.update(*S[a].begin(),*S[a].rbegin(),1);
		}
	}
	void del(int a,int b) {
		if(divp[a]) return;
		if(S[a].size()==1) {
			S[a].erase(b);
			st.update(0,N-1,-1);
		}
		else {
			st.update(*S[a].begin(),*S[a].rbegin(),-1);
			S[a].erase(b);
			if(S[a].size()>1) st.update(*S[a].begin(),*S[a].rbegin(),1);
		}
	}
	
    vector<int> maximumCount(vector<int>& nums, vector<vector<int>>& queries) {
		N=nums.size();
		cprime();
        
        vector<int> ret;
        int i;
        FOR(i,N) add(nums[i],i);
        FORR(q,queries) {
			del(nums[q[0]],q[0]);
			nums[q[0]]=q[1];
			add(nums[q[0]],q[0]);
			ret.push_back(st.getval(0,N-1));
		}
        
        FOR(i,N) del(nums[i],i);
        return ret;
    }
};
