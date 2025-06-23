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

int N;
int P[505050];
vector<int> E[505050];
int V[505050];
int id;

struct BinarySumTrie {
	static BinarySumTrie bst[1<<22];
	int nex[2],v;
	
	void add(int s,int val,int pos=17) {
		v+=val;
		if(pos>=0) {
			int c=(s>>pos)&1;
			if(!nex[c]) {
				nex[c]=id++;
				bst[nex[c]].nex[0]=bst[nex[c]].nex[1]=bst[nex[c]].v=0;
			}
			bst[nex[c]].add(s,val,pos-1);
		}
		
	}
	void trav(vector<int>& V,int cur,int pos=17) {
		if(!v) return;
		if(pos<0) {
			V.push_back(cur);
			return;
		}
		if(nex[0]) bst[nex[0]].trav(V,cur,pos-1);
		if(nex[1]) bst[nex[1]].trav(V,(1<<pos)+cur,pos-1);
	}
	int is(int val,int pos=17) {
		if(v==0) return 0;
		if(pos<0) return v;
		if(val&(1LL<<pos)) {
			if(nex[1]) return bst[nex[1]].is(val,pos-1);
			return 0;
		}
		else {
			if(nex[0]) return bst[nex[0]].is(val,pos-1);
			return 0;
		}
	}
	int pick(int val,int pos=17) { // sum [0,s-1]
		if(val>v) return -1;
		if(pos<0) return 0;
		
		int tar=0;
		if(nex[0]) {
			if(bst[nex[0]].v>=val) {
				return bst[nex[0]].pick(val,pos-1);
			}
			val -= bst[nex[0]].v;
		}
		return (1LL<<pos)+bst[nex[1]].pick(val,pos-1);
		
	}
};
BinarySumTrie BinarySumTrie::bst[1<<22];
int cid[101010];

vector<int> ret;
vector<pair<int,int>> Q[505050];
class Solution {
public:
	void dfs(int cur) {
		cid[cur]=id++;
		BinarySumTrie::bst[cid[cur]].nex[0]=BinarySumTrie::bst[cid[cur]].nex[1]=BinarySumTrie::bst[cid[cur]].v=0;
		BinarySumTrie::bst[cid[cur]].add(V[cur],1);
		FORR(e,E[cur]) {
			V[e]^=V[cur];
			dfs(e);
			if(BinarySumTrie::bst[cid[cur]].v<BinarySumTrie::bst[cid[e]].v) swap(cid[cur],cid[e]);
			vector<int> T;
			BinarySumTrie::bst[cid[e]].trav(T,0);
			FORR(a,T) {
				if(BinarySumTrie::bst[cid[cur]].is(a)==0) BinarySumTrie::bst[cid[cur]].add(a,1);
			}
		}
		FORR(q,Q[cur]) ret[q.second]=BinarySumTrie::bst[cid[cur]].pick(q.first);
		
	}

    vector<int> kthSmallest(vector<int>& par, vector<int>& vals, vector<vector<int>>& queries) {
        N=par.size();
        int i;
        FOR(i,N) {
			V[i]=vals[i];
			E[i].clear();
			Q[i].clear();
		}
		for(i=1;i<N;i++) {
			P[i]=par[i];
			E[P[i]].push_back(i);
		}
		ret.resize(queries.size());
		FOR(i,queries.size()) Q[queries[i][0]].push_back({queries[i][1],i});
		id=1;
		dfs(0);
		
		return ret;
    }
};

