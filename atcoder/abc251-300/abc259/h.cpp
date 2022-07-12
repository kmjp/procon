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
int A[404][404];
const ll mo=998244353;
vector<pair<int,int>> cand[404*404];
ll dp[404][404];

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

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(y,N) FOR(x,N) {
		cin>>A[y][x];
		cand[A[y][x]].push_back({y,x});
	}
	
	ll ret=0;
	FOR(i,404*402) {
		if(cand[i].size()>=400) {
			ZERO(dp);
			FOR(y,N) FOR(x,N) {
				if(x) dp[y][x]+=dp[y][x-1];
				if(y) dp[y][x]+=dp[y-1][x];
				if(A[y][x]==i) dp[y][x]++;
				dp[y][x]%=mo;
				if(A[y][x]==i) ret+=dp[y][x];
			}
		}
		else {
			FORR2(x1,y1,cand[i]) FORR2(x2,y2,cand[i]) {
				if(x1<=x2&&y1<=y2) ret+=comb(x2+y2-x1-y1,x2-x1);
			}
			
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
