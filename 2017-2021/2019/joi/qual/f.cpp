#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------


int N;
int A[102];
int dp[102][401][9][8][4];
int mo=10007;
int fact[10];

int comb(int P_,int Q_) {
	static const int N_=1020;
	static int C_[N_][N_];
	
	if(C_[0][0]==0) {
		int i,j;
		FOR(i,N_) C_[i][0]=C_[i][i]=1;
		for(i=1;i<N_;i++) for(j=1;j<i;j++) C_[i][j]=(C_[i-1][j-1]+C_[i-1][j])%mo;
	}
	if(P_<0 || P_>N_ || Q_<0 || Q_>P_) return 0;
	return C_[P_][Q_];
}
ll hcomb(int P_,int Q_) { return (P_==0&&Q_==0)?1:comb(P_+Q_-1,Q_);}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	
	fact[0]=1;
	for(i=1;i<=9;i++) fact[i]=fact[i-1]*i%mo;
	
	int slot=0;
	FOR(i,N) {
		cin>>A[i];
		if(i==0) {
			dp[1][0][2][0][A[i]-1]=1;
			slot=A[i]+1;
			continue;
		}
		
		for(int a=0;a<=min(slot,400);a++) for(int b=0;b<=min(8,slot-a);b++) for(int c=0;c<=min(7,slot-a-b);c++) for(int d=0;d<=min(3,slot-a-b-c);d++) if(dp[i][a][b][c][d]) {
			int emp=slot-a-b-c-d;
			for(int a2=0;a2<=min(a,A[i]);a2++) for(int b2=0;b2<=min(b,A[i]-a2);b2++) for(int c2=0;c2<=min(c,A[i]-a2-b2);c2++) for(int d2=0;d2<=min(d,A[i]-a2-b2-c2);d2++) for(int e2=0;e2<=min(emp,A[i]-a2-b2-c2-d2);e2++) {
				if(a2+b2+c2+d2+e2==0) continue;
				int pat=comb(a,a2)*comb(b,b2)%mo*comb(c,c2)%mo*comb(d,d2)%mo*comb(emp,e2)%mo*hcomb(a2+b2+c2+d2+e2,A[i]-(a2+b2+c2+d2+e2))%mo;
				(dp[i+1][(a-a2)+(c-c2)+(d-d2)][2*(a2+e2)+b2+c2][b2+c2+2*d2][A[i]-(a2+b2+c2+d2+e2)] += dp[i][a][b][c][d]*pat)%=mo;
			}
		}
		
		slot+=A[i];
	}
	
	ll ret=0;
	FOR(i,9) (ret+=dp[N][0][i][0][0])%=mo;
	FOR(i,N) ret=ret*fact[A[i]]%mo;
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
