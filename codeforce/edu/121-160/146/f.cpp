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

int N,M;
int L[202020],R[202020];

vector<pair<int,int>> E[1<<20];
vector<pair<int*,int>> hist;
int P[202020],Rank[202020],VS[202020];
int CV;
pair<int,int> C[5<<20];
int ret[5<<20];

const int NV=1<<19;
void update(int x,int y, pair<int,int> v,int l=0,int r=NV,int k=1) {
	if(l>=r) return;
	if(x<=l && r<=y) {
		E[k].push_back(v);
	}
	else if(l < y && x < r) {
		update(x,y,v,l,(l+r)/2,k*2);
		update(x,y,v,(l+r)/2,r,k*2+1);
	}
}

int par(int v) {
	if(P[v]==v) return v;
	return par(P[v]);
}
void rec(int &k,int v) {
	hist.push_back({&k,k});
	k=v;
}

void dfs(int k,int L,int R) {
	int cur=hist.size();
	FORR2(a,b,E[k]) {
		a=par(a);
		b=par(b);
		if(a==b) continue;
		if(Rank[a]<Rank[b]) swap(a,b);
		rec(P[b],a);
		C[CV]={VS[a],VS[b]};
		rec(VS[a],CV);
		CV++;
		if(Rank[a]==Rank[b]) {
			rec(Rank[a],Rank[a]+1);
		}
	}
	if(L+1==R) {
		ret[VS[par(0)]]=1;
	}
	else {
		int M=(L+R)/2;
		dfs(k*2,L,M);
		dfs(k*2+1,M,R);
	}
	
	
	while(hist.size()>cur) {
		*hist.back().first=hist.back().second;
		hist.pop_back();
	}
}



void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,N) {
		cin>>L[i]>>R[i];
	}
	FOR(i,M) {
		cin>>x>>y;
		x--,y--;
		int l=max(L[x],L[y]);
		int r=min(R[x],R[y]);
		if(l<=r) update(l,r+1,make_pair(x,y));
	}
	CV=N;
	FOR(i,N) {
		P[i]=i;
		VS[i]=i;
		C[i]={-1,-1};
	}
	dfs(1,0,1<<19);
	queue<int> Q;
	FOR(i,CV) if(ret[i]) Q.push(i);
	while(Q.size()) {
		int cur=Q.front();
		Q.pop();
		vector<int> T={C[cur].first,C[cur].second};
		FORR(e,T) {
			if(e!=-1&&ret[e]==0) {
				ret[e]=1;
				Q.push(e);
			}
		}
	}
	FOR(i,N) if(ret[i]) cout<<(i+1)<<" ";
	cout<<endl;
		
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
