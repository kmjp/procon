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


string S;
int N,K;
const ll mo=1000000007;

ll from[2][2];
ll to[2][2];
ll fr[2][2];
ll ft[2][2];

ll A[32][2][2];
ll B[32][2][2];

ll RA[2][2];
ll RB[2][2];

void go(ll SA[2][2],ll SB[2][2],ll TA_[2][2],ll TB_[2][2],ll UA_[2][2],ll UB_[2][2]) {
	ll TA[2][2], TB[2][2], UA[2][2], UB[2][2];
	int x,y,a,b,c,d;
	FOR(x,2) FOR(y,2) {
		TA[x][y]=TA_[x][y];
		TB[x][y]=TB_[x][y];
		UA[x][y]=UA_[x][y];
		UB[x][y]=UB_[x][y];
		SA[x][y]=SB[x][y]=0;
	}
	
	FOR(a,2) FOR(b,2) FOR(c,2) FOR(d,2) {
		(SA[a][d]+=TA[a][b]*UA[c][d])%=mo;
		(SB[a][d]+=TB[a][b]*UA[c][d])%=mo;
		(SB[a][d]+=UB[a][b]*TA[c][d])%=mo;
		if(a==b&&b!=c&&c==d) (SB[a][d]+=TA[a][b]*UA[c][d])%=mo;
		if(a==d&&a!=b&&c!=d) (SB[a][d]+=mo-TA[a][b]*UA[c][d]%mo)%=mo;
	}
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>S>>K;
	N=S.size();
	
	if(S[0]=='0'||S[0]=='?') from[0][0]=1;
	if(S[0]=='1'||S[0]=='?') from[1][1]=1;
	for(i=1;i<N;i++) {
		ZERO(to);
		ZERO(ft);
		FOR(x,2) {
			if(S[i]=='0'||S[i]=='?') {
				(to[x][0]+=from[x][0])%=mo;
				(to[x][0]+=from[x][1])%=mo;
				(ft[x][0]+=fr[x][0])%=mo;
				(ft[x][0]+=fr[x][1])%=mo;
				if(x==1) (ft[1][0]+=from[1][1])%=mo;
			}
			if(S[i]=='1'||S[i]=='?') {
				(to[x][1]+=from[x][0])%=mo;
				(to[x][1]+=from[x][1])%=mo;
				(ft[x][1]+=fr[x][0])%=mo;
				(ft[x][1]+=fr[x][1])%=mo;
				if(x==0) (ft[0][1]+=from[0][0])%=mo;
			}
		}
		
		
		swap(from,to);
		swap(fr,ft);
	}
	
	FOR(x,2) FOR(y,2) A[0][x][y]=from[x][y], B[0][x][y]=fr[x][y];
	
	int first=1;
	FOR(i,30) {
		go(A[i+1],B[i+1],A[i],B[i],A[i],B[i]);
		if(K&(1<<i)) {
			if(first) {
				first=0;
				FOR(x,2) FOR(y,2) RA[x][y]=A[i][x][y],RB[x][y]=B[i][x][y];
			}
			else {
				go(RA,RB,RA,RB,A[i],B[i]);
			}
		}
	}
	
	ll ret=0;
	FOR(x,2) FOR(y,2) ret+=RB[x][y];
	cout<<ret%mo<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
