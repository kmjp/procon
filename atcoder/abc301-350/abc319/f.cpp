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
vector<int> E[505];
int T[505],S[505],G[505];
vector<int> cand;
int ID[505];

ll dp[1024];

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
UF<512> uf[1024];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	for(i=1;i<N;i++) {
		cin>>x>>T[i]>>S[i]>>G[i];
		E[x-1].push_back(i);
		if(T[i]==2) {
			ID[i]=cand.size();
			cand.push_back(i);
		}
	}
	dp[0]=1;
	int mask;
	FOR(mask,1<<cand.size()) if(dp[mask]) {
		int up=1;
		while(up) {
			up=0;
			FOR(i,N) if(uf[mask][i]==uf[mask][0]) {
				FORR(c,E[i]) if(T[c]==1&&uf[mask][i]!=uf[mask][c]&&dp[mask]>=S[c]) {
					dp[mask]+=G[c];
					uf[mask](i,c);
					up=1;
				}
			}
		}
		dp[mask]=min(1LL<<30,dp[mask]);
		FOR(i,N) if(uf[mask][i]==uf[mask][0]) {
			FORR(c,E[i]) if(T[c]==2&&uf[mask][i]!=uf[mask][c]) {
				x=ID[c];
				if(dp[mask]*G[c]>dp[mask|(1<<x)]) {
					dp[mask|(1<<x)]=min(1LL<<30,dp[mask]*G[c]);
					uf[mask|(1<<x)]=uf[mask];
					uf[mask|(1<<x)](i,c);
				}
			}
		}
	}
	
	FOR(i,N) if(dp[(1<<cand.size())-1]<S[i]) {
		cout<<"No"<<endl;
		return;
	}
	cout<<"Yes"<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
