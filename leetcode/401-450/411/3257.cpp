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


template<class V, int ME> class BIT_r {
public:
	V bit[2][1<<ME];
	BIT_r(){clear();};
	void clear() {ZERO(bit);};
	
	void update(int entry, V val0, V val1) {
		entry++;
		while(entry <= 1<<ME) bit[0][entry-1]+=val0, bit[1][entry-1] += val1, entry += entry & -entry;
	}
	V total(int entry) {
		if(entry<0) return 0;
		int e=entry++;
		V v0=0,v1=0;
		while(entry>0) v0+=bit[0][entry-1], v1+=bit[1][entry-1], entry -= entry & -entry;
		return e*v0+v1;
	}
	void add(int L, int R, V val) { // add val to L<=x<=R
		update(L,val,-val*(L-1));
		update(R+1,-val,val*R);
	}
};
BIT_r<ll,18> bt;

vector<int> ev[101010];

class Solution {
public:
    vector<long long> countKConstraintSubstrings(string s, int k, vector<vector<int>>& queries) {
		int n=s.size();
		vector<int> nex[2];
		bt.clear();
		nex[0]={n,n};
		nex[1]={n,n};
		int i;
		FOR(i,n+1) nex[0].push_back(n);
		FOR(i,n+1) nex[1].push_back(n);
		FOR(i,n) ev[i].clear();
		vector<ll> R(queries.size());
		FOR(i,queries.size()) ev[queries[i][0]].push_back(i);
		
		for(i=n-1;i>=0;i--) {
			nex[s[i]-'0'].push_back(i);
			int a=nex[0][nex[0].size()-k-1];
			int b=nex[1][nex[1].size()-k-1];
			a=max(a,b);
			bt.add(i,a-1,1);
			
			FORR(e,ev[i]) {
				R[e]=bt.total(queries[e][1]);
			}
		}
		return R;
		
        
    }
};

