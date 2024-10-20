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

int L[202020],R[202020];
vector<int> C[202020];
int N;
int id;

using VT = string;

static const ll mo0=1000000021,mo1=1000000009;
static ll mul0,mul1;
static const ll add0=1000010007, add1=1003333331;
static vector<ll> pmo[2];
struct RollingHash {
	VT s; int l; vector<ll> hash_[2];
	void init(VT s) {
		this->s=s; l=s.size(); int i,j;
		hash_[0]=hash_[1]=vector<ll>(1,0);
		if(!mul0) mul0=10009+(((ll)&mul0+time(NULL))>>5)%1259,mul1=10007+(time(NULL)+((ll)&mul1)>>5)%2257;
		if(pmo[0].empty()) pmo[0].push_back(1),pmo[1].push_back(1);
		FOR(i,l) hash_[0].push_back((hash_[0].back()*mul0+add0+s[i])%mo0);
		FOR(i,l) hash_[1].push_back((hash_[1].back()*mul1+add1+s[i])%mo1);
	}
	pair<ll,ll> hash(int l,int r) { // s[l..r]
		if(l>r) return make_pair(0,0);
		while(pmo[0].size()<r+2)
			pmo[0].push_back(pmo[0].back()*mul0%mo0), pmo[1].push_back(pmo[1].back()*mul1%mo1);
		return make_pair((hash_[0][r+1]+(mo0-hash_[0][l]*pmo[0][r+1-l]%mo0))%mo0,
			             (hash_[1][r+1]+(mo1-hash_[1][l]*pmo[1][r+1-l]%mo1))%mo1);
	}
};

class Solution {
public:
	void dfs(int cur) {
		L[cur]=id;
		FORR(c,C[cur]) dfs(c);
		R[cur]=id++;
	}
    vector<bool> findAnswer(vector<int>& parent, string s) {
		N=parent.size();
		int i;
		FOR(i,N) {
			C[i].clear();
		}
		FOR(i,N) {
			if(i) C[parent[i]].push_back(i);
		}
		id=0;
		dfs(0);
		string V=s;
		FOR(i,N) V[R[i]]=s[i];
		string W=V;
		reverse(ALL(W));
		RollingHash rh1,rh2;
		rh1.init(V);
		rh2.init(W);
		vector<bool> ret;
		FOR(i,N) {
			ret.push_back(rh1.hash(L[i],R[i])==rh2.hash(N-1-R[i],N-1-L[i]));
		}
		return ret;
		
        
    }
};
