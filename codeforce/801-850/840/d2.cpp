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
int N,A,B,X,Y;
const ll mo=1000000007;
ll dp[101][101][101];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>A>>B>>X>>Y;
		A--,B--,X--,Y--;
		if(X>Y) {
			swap(X,Y);
			swap(A,B);
			A=N-1-A;
			B=N-1-B;
		}
		ll ret=0;
		int L=A,R=N-1-B,C=B-A-1;
		if(Y==N-1) {
			ZERO(dp);
			dp[L][C][R]=1;
			FOR(x,N) {
				if(x==X||x==Y) continue;
				for(int tl=0;tl<=L;tl++) for(int tc=0;tc<=C;tc++) {
					int tr=N-2-tl-tc-x;
					if(x>X) tr++;
					if(x>Y) tr++;
					if(tr<0||tr>R) continue;
					
					if(x<X) {
						if(tl) (dp[tl-1][tc][tr]+=dp[tl][tc][tr])%=mo;
						if(tr) (dp[tl][tc][tr-1]+=dp[tl][tc][tr])%=mo;
					}
					else {
						if(tc) (dp[tl][tc-1][tr]+=dp[tl][tc][tr])%=mo;
						if(tr) (dp[tl][tc][tr-1]+=dp[tl][tc][tr])%=mo;
					}
				}
			}
			ret+=dp[0][0][0];
			
		}
		else {
			//N‚ª^‚ñ’†
			ZERO(dp);
			dp[L][C][R]=1;
			FOR(x,N) {
				if(x==X||x==Y) continue;
				for(int tl=0;tl<=L;tl++) for(int tc=0;tc<=C;tc++) {
					int tr=N-2-tl-tc-x;
					if(x>X) tr++;
					if(x>Y) tr++;
					if(tr<0||tr>R) continue;
					
					if(x<X) {
						if(tl) (dp[tl-1][tc][tr]+=dp[tl][tc][tr])%=mo;
						if(tr) (dp[tl][tc][tr-1]+=dp[tl][tc][tr])%=mo;
					}
					else if(x<Y) {
						if(tc) (dp[tl][tc-1][tr]+=dp[tl][tc][tr])%=mo;
						if(tr) (dp[tl][tc][tr-1]+=dp[tl][tc][tr])%=mo;
					}
					else if(x<N-1) {
						if(tc) (dp[tl][tc-1][tr]+=2*dp[tl][tc][tr])%=mo;
					}
					else {
						if(tc) (dp[tl][tc-1][tr]+=dp[tl][tc][tr])%=mo;
					}
				}
			}
			ret+=dp[0][0][0];
			//N‚ª‰E
			ZERO(dp);
			dp[L][C][R]=1;
			FOR(x,N) {
				if(x==X||x==Y) continue;
				for(int tl=0;tl<=L;tl++) for(int tc=0;tc<=C;tc++) {
					int tr=N-2-tl-tc-x;
					if(x>X) tr++;
					if(x>Y) tr++;
					if(tr<0||tr>R) continue;
					
					if(x<X) {
						if(tl) (dp[tl-1][tc][tr]+=dp[tl][tc][tr])%=mo;
						if(tr) (dp[tl][tc][tr-1]+=dp[tl][tc][tr])%=mo;
					}
					else if(x<Y) {
						if(tc) (dp[tl][tc-1][tr]+=dp[tl][tc][tr])%=mo;
						if(tr) (dp[tl][tc][tr-1]+=dp[tl][tc][tr])%=mo;
					}
					else if(x<N-1) {
						if(tr) (dp[tl][tc][tr-1]+=2*dp[tl][tc][tr])%=mo;
					}
					else {
						if(tr) (dp[tl][tc][tr-1]+=dp[tl][tc][tr])%=mo;
					}
				}
			}
			ret+=dp[0][0][0];
		}
		
		//1`N‚Ìperm‚ðˆø‚­
		if(A==X&&B==Y) ret+=mo-1;
		cout<<ret%mo<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
