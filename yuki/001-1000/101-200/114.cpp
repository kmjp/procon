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

class UF {
	public:
	static const int ufmax=50;
	int ufpar[ufmax],ufrank[ufmax],ufcnt[ufmax];
	UF() { int i; FOR(i,ufmax) { ufpar[i]=i; ufrank[i]=0; ufcnt[i]=1; } }
	int operator[](int x) {return (ufpar[x]==x)?(x):(ufpar[x] = operator[](ufpar[x]));}
	int count(int x) { return ufcnt[operator[](x)];}
	void unite(int x,int y) {
		x = operator[](x); y = operator[](y);
		if(x==y) return;
		if(ufrank[x]<ufrank[y]) ufpar[x]=y, ufcnt[y]+=ufcnt[x];
		else {ufpar[y]=x; ufcnt[x]+=ufcnt[y]; if(ufrank[x]==ufrank[y]) ufrank[x]++;}
	}
};

int N,M,T;
int A[2000],B[2000],C[2000];
vector<int> V;
int mat[40][40];

int ok[40];
int OPT[(1 << 17)][40];
int first;
vector<pair<int,int> > V3;

int minimum_steiner_tree() {
  const int n = N;
  const int numT = V.size();
  if (numT <= 1) return 0;

  for (int S = 0; S < (1 << numT); ++S)
    for (int x = 0; x < n; ++x)
      OPT[S][x] = 100000;

  for (int p = 0; p < numT; ++p) // trivial case
    for (int q = 0; q < n; ++q)
      OPT[1 << p][q] = mat[V[p]][q];

  for (int S = 1; S < (1 << numT); ++S) { // DP step
    if (!(S & (S-1))) continue;
    for (int p = 0; p < n; ++p)
      for (int E = 0; E < S; ++E)
        if ((E | S) == S)
          OPT[S][p] = min( OPT[S][p], OPT[E][p] + OPT[S-E][p] );
    for (int p = 0; p < n; ++p)
      for (int q = 0; q < n; ++q)
        OPT[S][p] = min( OPT[S][p], OPT[S][q] + mat[p][q] );
  }
  int ans = 100000;
  for (int S = 0; S < (1 << numT); ++S)
    for (int q = 0; q < n; ++q)
      ans = min(ans, OPT[S][q] + OPT[((1 << numT)-1)-S][q]);
  return ans;
}

int dodo(ll mask,int cur) {
	UF uf;
	int x,y;
	int cnt=__builtin_popcountll(mask);
	
	int tot=0,i;
	FOR(i,V3.size()) {
		x=V3[i].second/64, y=V3[i].second%64;
		if((mask&(1LL<<x))==0) continue;
		if((mask&(1LL<<y))==0) continue;
		
		if(uf[x]!=uf[y]) {
			tot+=V3[i].first;
			uf.unite(x,y);
			if(uf.count(first)==cnt) break;
		}
		if(tot>cur) return tot;
	}
	return tot;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	UF uf;
	
	FOR(x,40) FOR(y,40) mat[x][y]=100000000;
	FOR(x,40) mat[x][x]=0;
	cin>>N>>M>>T;
	FOR(i,M) {
		cin>>A[i]>>B[i]>>C[i];
		mat[A[i]-1][B[i]-1]=mat[B[i]-1][A[i]-1]=C[i];
	}
	FOR(i,N) FOR(x,N) FOR(y,N) mat[x][y]=min(mat[x][y],mat[x][i]+mat[i][y]);
	FOR(x,N) FOR(y,x) V3.push_back(make_pair(mat[x][y],x*64+y));
	sort(ALL(V3));
	
	ll mask=0;
	FOR(i,T) cin>>x, V.push_back(x-1), ok[x-1]=1, mask |= 1LL<<(x-1), first=x-1;
	
	if(T<=13) {
		cout<<minimum_steiner_tree()<<endl;
	}
	else {
		vector<int> V2;
		FOR(i,N) if(ok[i]==0) V2.push_back(i);
		int mi=10000000;
		
		FOR(i,1<<V2.size()) {
			ll mask2=mask;
			FOR(j,V2.size()) if(i&(1LL<<j)) mask2 |= 1LL<<V2[j];
			mi=min(mi,dodo(mask2,mi));
		}
		cout<<mi<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
