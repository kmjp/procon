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

int N,M;
ll dp[4040][4040];
ll dp2[4040][4040];
const ll mo=1000000007;

ll comb(int P_,int Q_) {
	static const int N_=4020;
	static ll C_[N_][N_];
	
	if(C_[0][0]==0) {
		int i,j;
		FOR(i,N_) C_[i][0]=C_[i][i]=1;
		for(i=1;i<N_;i++) for(j=1;j<i;j++) C_[i][j]=(C_[i-1][j-1]+C_[i-1][j])%mo;
	}
	if(P_<0 || P_>N_ || Q_<0 || Q_>P_) return 0;
	return C_[P_][Q_];
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	dp[0][0]=1;
	cin>>N>>M;
	FOR(i,N) {
		FOR(j,4020) dp[i+1][j+1]=(dp[i][j]+dp[i+1][j])%mo;
	}
	
	ll ret=0;
	for(int mi=0;mi<=N;mi++) {
		for(int ze=0;mi+ze<=N;ze++) {
			int pl=N-mi-ze;
			if(mi>=(N+1)/2) continue;
			if(mi+ze<(N+1)/2) continue;
			
			ll pat=comb(mi+ze,mi)*comb(N,pl)%mo;
			if((mi+pl)%2==M%2) {
				dp2[mi+pl][mi+pl]+=pat;
				if(N%2) {
					int d=mi+pl+1;
					int ma=M-(ze-abs(pl-mi));
					if(d%2!=ma%2) ma--;
					if(d<=ma) {
						dp2[mi+pl][d]+=pat;
						dp2[mi+pl][ma+2]+=mo-pat;
					}
				}
			}
			else {
				dp2[mi+pl][mi+pl+1]+=pat;
				if(N%2) {
					int d=mi+pl;
					int ma=M-(ze-abs(pl-mi));
					if(d%2!=ma%2) ma--;
					if(d<=ma) {
						dp2[mi+pl][d]+=pat;
						dp2[mi+pl][ma+2]+=mo-pat;
					}
				}
				
			}
		}
	}
	FOR(i,N+1) {
		FOR(j,M+1) {
			if(j>=2) (dp2[i][j]+=dp2[i][j-2])%=mo;
			(ret+=dp2[i][j]*dp[i][j])%=mo;
		}
	}
	cout<<ret%mo<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
