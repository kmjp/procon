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

string S;

int N;
vector<int> E[200005];
int P[21][200005],D[200005];
int L[202020],R[202020],re[202020];
int id;

void dfs(int cur) {
	L[cur]=id++;
	re[L[cur]]=cur;
	FORR(e,E[cur]) if(e!=P[0][cur]) D[e]=D[cur]+1, P[0][e]=cur, dfs(e);
	R[cur]=id;
}
int getpar(int cur,int up) {
	int i;
	FOR(i,20) if(up&(1<<i)) cur=P[i][cur];
	return cur;
}

int lca(int a,int b) {
	int ret=0,i,aa=a,bb=b;
	if(D[aa]>D[bb]) swap(aa,bb);
	for(i=19;i>=0;i--) if(D[bb]-D[aa]>=1<<i) bb=P[i][bb];
	for(i=19;i>=0;i--) if(P[i][aa]!=P[i][bb]) aa=P[i][aa], bb=P[i][bb];
	return (aa==bb)?aa:P[0][aa];               // vertex
}

template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s^=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]^=v,e+=e&-e;}
};
BIT<int,20> bt;

vector<string> split(const string &str, char delim=' '){
	vector<string> res;
	size_t current = 0, found;
	while((found = str.find_first_of(delim, current)) != string::npos){
		res.push_back(string(str, current, found - current));
		current = found + 1;
	}
	res.push_back(string(str, current, str.size() - current));
	return res;
}

class Solution {
public:
    vector<bool> palindromePath(int N, vector<vector<int>>& edges, string s, vector<string>& queries) {
        int i,x;
        FOR(i,N) {
			E[i].clear();
			bt.add(i,bt(i));
		}
        S=s;
        FORR(e,edges) {
			E[e[0]].push_back(e[1]);
			E[e[1]].push_back(e[0]);
		}
		id=0;
		dfs(0);
		FOR(i,19) FOR(x,N) P[i+1][x]=P[i][P[i][x]];
		FOR(i,N) {
			int v=1LL<<(S[i]-'a');
			bt.add(L[i],v);
			bt.add(R[i],v);
		}
		vector<bool> ret;
		FORR(q,queries) {
			auto V=split(q);
			if(V[0]=="update") {
				int i=atoi(V[1].c_str());
				int v=1LL<<(S[i]-'a');
				bt.add(L[i],v);
				bt.add(R[i],v);
				S[i]=V[2][0];
				v=1LL<<(S[i]-'a');
				bt.add(L[i],v);
				bt.add(R[i],v);
			}
			else {
				int u=atoi(V[1].c_str());
				int v=atoi(V[2].c_str());
				int lc=lca(u,v);
				int mask=bt(L[u])^bt(L[v])^(1<<(S[lc]-'a'));
				ret.push_back(__builtin_popcount(mask)<=1);
				
			}
		}
		return ret;
		
		
    }
};

