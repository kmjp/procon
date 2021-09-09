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

template<int um> class UF {
	public:
	vector<int> par,rank,cnt;
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
UF<3030> uf;
int P[3030],Q[3030];
ll dp[3030][3030][4];

ll from[3030];
ll to[3030];
ll cand[3030];
ll fact[3030];

const ll mo=1000000007;

void hoge(int N) {
	int x,y,i,j;
	ZERO(cand);
	
	if(N==1) {
		cand[0]=1;
		cand[1]=1;
		return;
	}
	
	
	FOR(i,4) {
		FOR(x,N+1) FOR(y,N+1) FOR(j,4) dp[x][y][j]=0;
		// 0-prev edge declined
		// 2-prev edge selected
		// 0-prev vertex declined
		// 1-prev vertex selected
		dp[0][0][i]=1;
		FOR(x,N) {
			FOR(y,N) {
				// not take edge
				(dp[x+1][y][0]+=dp[x][y][1]+dp[x][y][3])%=mo;
				(dp[x+1][y][1]+=dp[x][y][1]+dp[x][y][3])%=mo;
				
				(dp[x+1][y+1][2]+=dp[x][y][0]+dp[x][y][2])%=mo;
				(dp[x+1][y+1][3]+=dp[x][y][0]+dp[x][y][1]+dp[x][y][2]+dp[x][y][3])%=mo;
			}
		}
		FOR(x,N) {
			(cand[x]+=dp[N][x][i])%=mo;
		}
	}
	cand[N]=2;
	
	
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>P[i];
	FOR(i,N) cin>>Q[i];
	FOR(i,N) uf(P[i]-1,Q[i]-1);
	
	from[0]=1;
	FOR(i,N) if(uf[i]==i) {
		k=uf.count(i);
		hoge(k);
		ZERO(to);
		FOR(x,N+1) FOR(y,k+1) if(x+y<=N) (to[x+y]+=from[x]*cand[y])%=mo;
		swap(from,to);
	}
	
	fact[0]=1;
	FOR(i,N) fact[i+1]=fact[i]*(i+1)%mo;
	
	ll ret=0;
	FOR(i,N+1) {
		(from[i]*=fact[N-i])%=mo;
		if(i%2==0) ret+=from[i];
		else ret+=mo-from[i];
	}
	
	cout<<ret%mo<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
