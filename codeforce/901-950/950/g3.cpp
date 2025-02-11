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

int T;
int N,M;
vector<pair<int,int>> E[202020];
int D[202020];
int X[202020];

struct BinarySumTrie {
	BinarySumTrie *nex[2];
	ll v;
	BinarySumTrie() {
		nex[0]=nex[1]=NULL;v=0;
	}
	
	void add(ll s,ll val,int pos=29) {
		v += val;
		if(pos>=0) {
			int c=(s>>pos)&1;
			if(!nex[c]) nex[c]=new BinarySumTrie();
			nex[c]->add(s,val,pos-1);
		}
	}
	int pick(ll val,int pos=29) { // sum [0,s-1]
		if(pos<0) return 0;
		
		int tar=0;
		if(val&(1LL<<pos)) {
			if(nex[0]&&nex[0]->v) tar=0;
			else tar=1;
		}
		else {
			if(nex[1]&&nex[1]->v) tar=1;
			else tar=0;
		}
		return (tar<<pos)+nex[tar]->pick(val,pos-1);
	}
};

void dfs(int cur,int pre,int d,int x) {
	D[cur]=d;
	X[cur]=x;
	FORR2(e,c,E[cur]) if(e!=pre) dfs(e,cur,d^1,x^c);
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		BinarySumTrie root[2];
		cin>>N>>M;
		FOR(i,N) E[i].clear();
		FOR(i,N-1) {
			cin>>x>>y>>k;
			E[x-1].push_back({y-1,k});
			E[y-1].push_back({x-1,k});
		}
		dfs(0,0,0,0);
		FOR(i,N) root[D[i]].add(X[i],1);

		int par=0;
		while(M--) {
			cin>>s;
			if(s=="^") {
				cin>>x;
				par^=x;
			}
			else {
				cin>>x>>y;
				x--;
				root[D[x]].add(X[x],-1);
				int ret=-1;
				if(root[0].v) {
					if(D[x]==0) ret=max(ret,root[0].pick(X[x]^y)^(X[x]^y));
					if(D[x]==1) ret=max(ret,root[0].pick(X[x]^y^par)^(X[x]^y^par));
				}
				if(root[1].v) {
					if(D[x]==0) ret=max(ret,root[1].pick(X[x]^y^par)^(X[x]^y^par));
					if(D[x]==1) ret=max(ret,root[1].pick(X[x]^y)^(X[x]^y));
				}
				root[D[x]].add(X[x],1);
				
				cout<<ret<<" ";
			}
		}
		cout<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
