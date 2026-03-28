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

template<int um> class UF {
	public:
	vector<int> par,rank,cnt,G[um];
	UF() {par=rank=vector<int>(um,0); cnt=vector<int>(um,1); for(int i=0;i<um;i++) par[i]=i;}
	void reinit(int num=um) {int i; FOR(i,num) rank[i]=0,cnt[i]=1,par[i]=i;}
	int operator[](int x) {return (par[x]==x)?(x):(par[x] = operator[](par[x]));}
	int count(int x) { return cnt[operator[](x)];}
	int operator()(int x,int y) {
		if((x=operator[](x))==(y=operator[](y))) return x;
		cnt[y]=cnt[x]=cnt[x]+cnt[y];
		if(rank[x]>rank[y]) return par[x]=y;
		rank[x]+=rank[x]==rank[y]; return par[y]=x;
	}
};
UF<202020> uf;
vector<int> E[202020];

int T,N,M;
int A[202020],B[202020],C[202020];
int dp[2][202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>M;
		uf.reinit(N);
		FOR(i,N) {
			E[i].clear();
			dp[0][i]=dp[1][i]=1<<20;
		}
		FOR(i,M) {
			cin>>A[i]>>B[i]>>C[i];
			A[i]--,B[i]--;
			if(C[i]==1) {
				uf(A[i],B[i]);
				E[A[i]].push_back(B[i]);
				E[B[i]].push_back(A[i]);
			}
		}
		dp[0][0]=dp[1][N-1]=0;
		queue<int> Q;
		Q.push(0);
		Q.push((N-1)*2+1);
		while(Q.size()) {
			int cur=Q.front()/2;
			int id=Q.front()%2;
			Q.pop();
			FORR(e,E[cur]) if(chmin(dp[id][e],dp[id][cur]+1)) Q.push(e*2+id);
		}
		if(dp[0][N-1]<1<<20) {
			cout<<"Same"<<endl;
			cout<<dp[0][N-1]<<endl;
			continue;
		}
		int mi=1<<20;
		FOR(i,M) {
			mi=min(mi,dp[0][A[i]]+1+dp[1][B[i]]);
			mi=min(mi,dp[1][A[i]]+1+dp[0][B[i]]);
		}
		if(mi<1<<20) {
			cout<<"Different"<<endl;
			cout<<mi<<endl;
		}
		else {
			cout<<"Unknown"<<endl;
		}
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
