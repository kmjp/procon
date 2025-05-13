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

int T;
int H,W,K;
vector<int> A[202020];
ll F[202020];
ll C[606060];
ll dp[606060];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>H>>W>>K;
		K+=2;
		FOR(i,K) {
			C[i]=dp[i]=0;
		}
		
		ll ret=0;
		FOR(y,H) {
			A[y].resize(W);
			F[y]=0;
			if(y) {
				FOR(x,W) C[A[y-1][x]]++;
			}
			FOR(x,W) {
				cin>>A[y][x];
				if(A[y][x]==-1) {
					A[y][x]=0;
					F[y]++;
				}
				else {
					ret+=C[A[y][x]];
				}
			}
			if(y) {
				FOR(x,W) C[A[y-1][x]]--;
			}
		}
		ll common=0;
		ll ma=0;
		FOR(y,H) {
			if(y) FOR(x,W) if(A[y-1][x]) C[A[y-1][x]]++;
			if(y+1<H) FOR(x,W) if(A[y+1][x]) C[A[y+1][x]]++;
			vector<int> cand={0};
			if(y) FOR(x,W) if(A[y-1][x]) cand.push_back(A[y-1][x]);
			if(y+1<H) FOR(x,W) if(A[y+1][x]) cand.push_back(A[y+1][x]);
			ll ncommon=0;
			if(y) ncommon=1LL*F[y-1]*F[y];
			ll nma=ma;
			FORR(a,cand) if(a==0||C[a]) {
				ll nv=C[a]*F[y];
				dp[a]=max({dp[a],dp[0],ma-ncommon})+nv;
				nma=max(nma,dp[a]);
				C[a]=0;
			}
			common+=ncommon;
			ma=nma;
			if(y) FOR(x,W) if(A[y-1][x]) C[A[y-1][x]]=0;
			if(y+1<H) FOR(x,W) if(A[y+1][x]) C[A[y+1][x]]=0;
		}
		ma=0;
		FOR(i,K) ma=max(ma,dp[i]);
		cout<<ret+ma+common<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
