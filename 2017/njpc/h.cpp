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
int C[101010];
int NG[101010];
int id;
int L[101010],R[101010],rev[101010];

template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	V add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};
BIT<int,20> bt;

int P[21][200005],D[200005];

void dfs(int cur,int depth) {
	L[cur]=id++;
	rev[L[cur]]=cur;
	D[cur]=depth;
	FORR(e,E[cur]) dfs(e,depth+1);
	R[cur]=id;
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
	for(i=1;i<N;i++) {
		cin>>P[0][i];
		P[0][i]--;
		E[P[0][i]].push_back(i);
	}
	
	dfs(0,0);

	FOR(i,N) cin>>C[i];
	for(i=1;i<N;i++) {
		NG[i]=(C[i]==C[P[0][i]]);
		if(NG[i]) {
			bt.add(L[i],1);
			bt.add(R[i],-1);
		}
	}
	FOR(i,19) FOR(x,N) P[i+1][x]=P[i][P[i][x]];
	
	
	cin>>Q;
	while(Q--) {
		cin>>i;
		if(i==1) {
			cin>>x;
			x--;
			if(NG[x]) {
				bt.add(L[x],-1),bt.add(R[x],1);
			}
			else {
				bt.add(L[x],1),bt.add(R[x],-1);
			}
			NG[x]^=1;
		}
		else if(i==2) {
			int u,v;
			cin>>u>>v;
			u--,v--;
			int r=lca(u,v);
			
			if(bt(L[r])==bt(L[u]) && bt(L[r])==bt(L[v])) cout<<"YES"<<endl;
			else cout<<"NO"<<endl;
		}
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
