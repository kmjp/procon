#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N,Q;
vector<int> E[101010];
int id;
int L[101010],R[101010],V[101010],rev[101010];
int P[21][200005],D[200005];
int A,B,C;

int lca(int a,int b) {
	int ret=0,i,aa=a,bb=b;
	if(D[aa]>D[bb]) swap(aa,bb);
	for(i=19;i>=0;i--) if(D[bb]-D[aa]>=1<<i) bb=P[i][bb];
	for(i=19;i>=0;i--) if(P[i][aa]!=P[i][bb]) aa=P[i][aa], bb=P[i][bb];
	return (aa==bb)?aa:P[0][aa];               // vertex
}

void dfs(int cur) {
	L[cur]=id++;
	V[cur]=1;
	rev[L[cur]]=cur;
	ITR(it,E[cur]) if(*it!=P[0][cur]) D[*it]=D[cur]+1, P[0][*it]=cur, dfs(*it), V[cur]+=V[*it];
	R[cur]=id;
}

int getpar(int cur,int up) {
	int i;
	FOR(i,20) if(up&(1<<i)) cur=P[i][cur];
	return cur;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q;
	FOR(i,N-1) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
	}
	
	dfs(0);
	FOR(i,19) FOR(x,N) P[i+1][x]=P[i][P[i][x]];
	
	while(Q--) {
		cin>>A>>B>>C;
		A--,B--,C--;
		int lc=lca(A,B);
		if(C==lc) {
			int a2=getpar(A,D[A]-D[C]-1);
			int b2=getpar(B,D[B]-D[C]-1);
			cout<<N-V[a2]-V[b2]<<endl;
		}
		else if(D[C]>=D[lc] && L[C]<=L[A] && L[A]<R[C]) {
			cout<<V[C]-V[getpar(A,D[A]-D[C]-1)]<<endl;
		}
		else if(D[C]>=D[lc] && L[C]<=L[B] && L[B]<R[C]) {
			cout<<V[C]-V[getpar(B,D[B]-D[C]-1)]<<endl;
		}
		else {
			cout<<0<<endl;
		}
		
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
