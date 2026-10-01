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

int N,Q;
int X[202020];

vector<int> E[200005];
int P[21][200005],D[200005];
int L[202020],R[202020],re[202020];
vector<int> V;
int id;
int S[202020],T[202020],A[202020],B[202020],TL[202020],TR[202020];


int C[202020];
int num[202020];
int sum[202020];
const int DI=650;
vector<pair<int,int>> ev[DI];
int ret[202020];

void dfs(int cur) {
	L[cur]=id++;
	V.push_back(cur);
	re[L[cur]]=cur;
	FORR(e,E[cur]) if(e!=P[0][cur]) D[e]=D[cur]+1, P[0][e]=cur, dfs(e);
	R[cur]=id++;
	V.push_back(cur);
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
	
	cin>>N>>Q;
	FOR(i,N) {
		cin>>X[i];
		X[i]--;
	}
	sum[0]=N;
	FOR(i,N-1) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
	}
	dfs(0);
	FOR(i,19) FOR(x,N) P[i+1][x]=P[i][P[i][x]];
	
	FOR(i,Q) {
		cin>>S[i]>>T[i]>>A[i]>>B[i];
		S[i]--;
		T[i]--;
		TL[i]=L[S[i]]+1;
		TR[i]=L[T[i]]+1;
		if(TL[i]>TR[i]) swap(TL[i],TR[i]);
		ev[TL[i]/DI].push_back({TR[i],i});
	}
	FOR(i,DI) if(ev[i].size()) {
		sort(ALL(ev[i]));
		int CL=DI*i,CR=DI*i;
		FORR2(r,c,ev[i]) {
			while(CR<r) {
				x=V[CR++];
				if(num[x]) sum[C[X[x]]--]--;
				else sum[++C[X[x]]]++;
				num[x]^=1;
			}
			while(TL[c]<CL) {
				x=V[--CL];
				if(num[x]) sum[C[X[x]]--]--;
				else sum[++C[X[x]]]++;
				num[x]^=1;
			}
			while(CL<TL[c]) {
				x=V[CL++];
				if(num[x]) sum[C[X[x]]--]--;
				else sum[++C[X[x]]]++;
				num[x]^=1;
			}
			x=lca(S[c],T[c]);
			sum[++C[X[x]]]++;

			ret[c]=sum[A[c]]-sum[B[c]+1];
			sum[C[X[x]]--]--;
		}
		while(CL<CR) {
			x=V[CL++];
			if(num[x]) sum[C[X[x]]--]--;
			else sum[++C[X[x]]]++;
			num[x]^=1;
		}
	}
	FOR(i,Q) cout<<ret[i]<<endl;
	
	
		
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
