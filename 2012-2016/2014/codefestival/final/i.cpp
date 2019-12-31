#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N,M;
ll L[100100],R[100100],T[100100],B[100100];
ll X[2][100100],Y[2][100100];

int pa[20][100100];
int D[100100];
vector<int> C[100100];

int pos[2][100100];
map<int,int> MX,MY;

set<pair<ll,int> > ev;
set<pair<ll,int> > range;

void dfs(int cur,int depth) {
	D[cur]=depth;
	ITR(it,C[cur]) dfs(*it,depth+1);
}

int lca(int a,int b) {
	int ret=0,i,aa=a,bb=b;
	if(D[aa]>D[bb]) swap(aa,bb);
	for(i=19;i>=0;i--) if(D[bb]-D[aa]>=1<<i) bb=pa[i][bb];
	for(i=19;i>=0;i--) if(pa[i][aa]!=pa[i][bb]) aa=pa[i][aa], bb=pa[i][bb];
	return D[a]+D[b]-2*D[(aa==bb)?aa:pa[0][aa]];  // dist
}

void solve() {
	int i,j,k,l,r,x,y,x1,x2,y1,y2; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>x>>y>>r;
		L[i]=x+y-r;
		R[i]=x+y+r;
		T[i]=x-y-r;
		B[i]=x-y+r;
		ev.insert(make_pair(L[i],i));
		ev.insert(make_pair(R[i],i+600000));
	}
	L[N]=T[N]=-1<<28;
	R[N]=B[N]=1<<28;
	range.insert(make_pair(T[N],N));
	range.insert(make_pair(B[N],N));
	pa[0][N]=N++;
	
	cin>>M;
	FOR(i,M) {
		cin>>x1>>y1>>x2>>y2;
		X[0][i]=x1+y1;
		Y[0][i]=x1-y1;
		X[1][i]=x2+y2;
		Y[1][i]=x2-y2;
		ev.insert(make_pair(X[0][i],i+200000));
		ev.insert(make_pair(X[1][i],i+400000));
	}
	ITR(it,ev) {
		x=it->second;
		set<pair<ll,int> >::iterator sit;
		if(x<200000) {
			sit=range.lower_bound(make_pair(T[x],0));
			sit--;
			pa[0][x]=sit->second;
			C[sit->second].push_back(x);
			range.insert(make_pair(T[x],x));
			range.insert(make_pair(B[x],pa[0][x]));
		}
		else if(x<400000) {
			sit=range.lower_bound(make_pair(Y[0][x-200000],0));
			sit--;
			pos[0][x-200000] = sit->second;
		}
		else if(x<600000) {
			sit=range.lower_bound(make_pair(Y[1][x-400000],0));
			sit--;
			pos[1][x-400000] = sit->second;
		}
		else {
			x-=600000;
			range.erase(make_pair(T[x],x));
			range.erase(make_pair(B[x],pa[0][x]));
		}
	}
	
	dfs(N-1,0);
	FOR(i,19) FOR(j,N) pa[i+1][j]=pa[i][pa[i][j]];
	FOR(i,M) _P("%d\n",lca(pos[0][i],pos[1][i]));
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
