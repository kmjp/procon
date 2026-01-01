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

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N-1) {
		cin>>x>>y;
		E[x].push_back(y);
		E[y].push_back(x);
	}
	dfs(0);
	FOR(i,19) FOR(x,N) P[i+1][x]=P[i][P[i][x]];
	
	ll ret=1;
	int cur=1;
	FORR(e,E[0]) {
		ret+=1LL*cur*(R[e]-L[e]);
		cur+=R[e]-L[e];
	}
	cur=R[1]-L[1];
	int oth=1;
	FORR(e,E[0]) if(L[1]<L[e]||R[e]<=L[1]) oth+=R[e]-L[e];
	ret+=1LL*cur*oth;
	int U=1,V=-1;
	for(i=2;i<N;i++) {
		if(L[U]<=L[i]&&L[i]<R[U]) {
			U=i;
			cur=R[i]-L[i];
			ret+=1LL*cur*oth;
		}
		else if(L[i]<L[U]&&L[U]<R[i]) {
			ret+=1LL*cur*oth;
		}
		else if(V==-1) {
			if(lca(U,i)!=0) break;
			V=i;
			oth=R[i]-L[i];
			ret+=1LL*cur*oth;
		}
		else if(L[V]<=L[i]&&L[i]<R[V]) {
			V=i;
			oth=R[i]-L[i];
			ret+=1LL*cur*oth;
		}
		else if(L[i]<L[V]&&L[V]<R[i]) {
			ret+=1LL*cur*oth;
		}
		else {
			break;
		}
	}
	
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
