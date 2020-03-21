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

template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};
BIT<int,20> up,down;


int N,M;
vector<int> E[200005];
int P[21][200005],D[200005],Pid[202020];;
int A[101010],B[101010],CU[101010],CD[101010];

int id;
int L[202020],R[202020];

void dfs(int cur) {
	L[cur]=id++;
	ITR(it,E[cur]) if(*it!=P[0][cur]) D[*it]=D[cur]+1, P[0][*it]=cur, dfs(*it);
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
	cin>>N>>M;
	FOR(i,N-1) {
		cin>>A[i]>>B[i];
		A[i]--;
		B[i]--;
		CU[i]=CD[i]=1;
		E[A[i]].push_back(B[i]);
		E[B[i]].push_back(A[i]);
	}
	dfs(0);
	FOR(i,19) FOR(x,N) P[i+1][x]=P[i][P[i][x]];
	FOR(i,N-1) {
		if(D[A[i]]>D[B[i]]) swap(A[i],B[i]);
		up.add(L[B[i]],1);
		up.add(R[B[i]],-1);
		down.add(L[B[i]],1);
		down.add(R[B[i]],-1);
	}
	while(M--) {
		cin>>s;
		if(s=="I") {
			cin>>i>>x>>y;
			i--;
			up.add(L[B[i]],-CU[i]);
			up.add(R[B[i]],+CU[i]);
			down.add(L[B[i]],-CD[i]);
			down.add(R[B[i]],+CD[i]);
			if(A[i]>B[i]) {
				CU[i]=x;
				CD[i]=y;
			}
			else {
				CU[i]=y;
				CD[i]=x;
			}
			up.add(L[B[i]],+CU[i]);
			up.add(R[B[i]],-CU[i]);
			down.add(L[B[i]],+CD[i]);
			down.add(R[B[i]],-CD[i]);
			
		}
		else {
			cin>>x>>y;
			x--,y--;
			int lc=lca(x,y);
			cout<<up(L[x])-up(L[lc])+down(L[y])-down(L[lc])<<endl;
		}
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
