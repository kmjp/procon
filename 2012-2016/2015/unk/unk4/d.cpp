#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N,K;
vector<int> A,R,rev;
int used[51];

template<int um> class UF {
	public:
	vector<int> par,rank,cnt;
	UF() {rank=vector<int>(um,0); cnt=vector<int>(um,1); for(int i=0;i<um;i++) par.push_back(i);}
	int operator[](int x) {return (par[x]==x)?(x):(par[x] = operator[](par[x]));}
	int count(int x) { return cnt[operator[](x)];}
	int operator()(int x,int y) {
		if((x=operator[](x))==(y=operator[](y))) return x;
		cnt[y]=cnt[x]=cnt[x]+cnt[y];
		if(rank[x]>rank[y]) return par[x]=y;
		rank[x]+=rank[x]==rank[y]; return par[y]=x;
	}
};

bool enableset(UF<50>& uf) {
	int dp[51]={};
	int i,x;
	dp[0]=1;
	FOR(i,N) if(uf[i]==i) {
		int c=uf.count(i);
		for(x=50;x>=c;x--) dp[x] |= dp[x-c];
	}
	return dp[K]==1;
}

vector<int> dodo(UF<50> uf) {
	int i,x;
	vector<int> d=A;
	int B[51];
	FOR(i,N) {
		vector<int> e,f;
		FOR(x,N) if(uf[x]==i) e.push_back(A[x]),f.push_back(x);
		sort(ALL(e));
		FOR(x,e.size()) d[f[x]]=e[x];
	}
	return d;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	rev.resize(N);
	FOR(i,N) cin>>x, A.push_back(x-1), rev[x-1]=i;
	R=A;
	
	UF<50> uf;
	FOR(i,N) {
		FOR(j,N) if(used[j]==false) {
			UF<50> uf2=uf;
			uf2(i,rev[j]);
			if(enableset(uf2)==false) continue;
			
			used[j]=true;
			uf=uf2;
			A=dodo(uf);
			FOR(x,A.size()) rev[A[x]]=x;
			break;
		}
	}
	
	FOR(i,N) _P("%d%c",A[i]+1,(i==N-1)?'\n':' ');
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
