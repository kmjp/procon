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

ll mo;
int N;

ll comb(int P_,int Q_) {
	static const int N_=1020;
	static ll C_[N_][N_];
	
	if(C_[0][0]==0) {
		int i,j;
		FOR(i,N_) C_[i][0]=C_[i][i]=1;
		for(i=1;i<N_;i++) for(j=1;j<i;j++) C_[i][j]=(C_[i-1][j-1]+C_[i-1][j])%mo;
	}
	if(P_<0 || P_>N_ || Q_<0 || Q_>P_) return 0;
	return C_[P_][Q_];
}

ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

ll dp[32][32][32][900];
// 点の数・直前の点・偶奇の差・辺

ll dp2[32][32][900];
// a点とb点の間にe辺がある

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>mo;
	
	for(x=1;x<=N;x++) {
		dp2[x][0][0]=1;
		for(y=0;x+y<N;y++) {
			for(int e=0;e<=800;e++) if(dp2[x][y][e]) {
				for(i=1;i<=x;i++) for(j=0;j<=y;j++) {
					(dp2[x][y+1][e+i+j]+=dp2[x][y][e]*comb(x,i)%mo*comb(y,j))%=mo;
				}
			}
		}
	}
	
	dp[1][1][16][0]=1;
	
	for(int sum=1;sum<N;sum++) {
		for(int pre=1;pre<=sum;pre++) {
			for(int dif=0;dif<=30;dif++) {
				for(int e=0;e<=N*N;e++) if(dp[sum][pre][dif][e]) {
					for(int addv=1;sum+addv<=N;addv++) {
						for(int adde=addv;adde<=pre*addv*adde&&adde+e<=N*(N-1)/2;adde++) if(dif-addv>=0&&dif-addv<=30&&dp2[pre][addv][adde]) {
							(dp[sum+addv][addv][30-(dif-addv)][e+adde]+=dp[sum][pre][dif][e]*dp2[pre][addv][adde]%mo*comb(N-sum,addv))%=mo;
						}
					}
				}
			}
		}
	}
	
	for(i=N-1;i<=N*(N-1)/2;i++) {
		ll sum=0;
		FOR(j,N+1) sum+=dp[N][j][15][i];
		cout<<sum%mo<<" ";
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
