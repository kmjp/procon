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

int C[26],K[26];
int N;
string S[202020];
ll A[202020],B[202020],E[202020];
ll dp[16][16][31];
ll ret[26][16];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	FOR(i,26) {
		cin>>C[i];
		C[i]--;
	}
	FOR(i,26) {
		cin>>K[i];
	}
	cin>>N;
	FOR(i,N) {
		cin>>S[i]>>A[i]>>B[i]>>E[i];
		FORR(c,S[i]) c-='A';
		A[i]--;
		B[i]--;
	}
	
	FOR(i,26) {
		FOR(x,16) FOR(y,16) dp[x][y][0]=-1LL<<55;
		FOR(j,N) {
			if(count(ALL(S[j]),i)) {
				chmax(dp[A[j]][B[j]][0],E[j]);
				chmax(dp[B[j]][A[j]][0],E[j]);
			}
		}
		FOR(j,29) {
			FOR(x,16) FOR(y,16) dp[x][y][j+1]=-1LL<<55;;
			FOR(x,16) FOR(y,16) FOR(r,16) dp[x][r][j+1]=max(dp[x][r][j+1],dp[x][y][j]+dp[y][r][j]);
		}
		FOR(x,16) ret[i][x]=-1LL<<55;
		for(k=max(0,K[i]-26);k<=K[i];k++) {
			ll cur[16][16];
			FOR(x,16) FOR(y,16) cur[x][y]=(x==y)?0:-1LL<<55;
			FOR(j,29) if(k&(1<<j)) {
				ll to[16][16];
				FOR(x,16) FOR(y,16) to[x][y]=-1LL<<55;
				FOR(x,16) FOR(y,16) FOR(r,16) to[x][r]=max(to[x][r],cur[x][y]+dp[y][r][j]);
				swap(cur,to);
			}
			
			FOR(x,16) ret[i][x]=max(ret[i][x],cur[C[i]][x]);
		}
		for(k=0;k<=min(26,K[i]);k++) {
			ll cur[16][16];
			FOR(x,16) FOR(y,16) cur[x][y]=(x==y)?0:-1LL<<55;
			FOR(j,29) if(k&(1<<j)) {
				ll to[16][16];
				FOR(x,16) FOR(y,16) to[x][y]=-1LL<<55;
				FOR(x,16) FOR(y,16) FOR(r,16) to[x][r]=max(to[x][r],cur[x][y]+dp[y][r][j]);
				swap(cur,to);
			}
			
			FOR(x,16) ret[i][x]=max(ret[i][x],cur[C[i]][x]);
		}
	}
	
	ll ma=-1LL<<55;
	FOR(x,16) {
		ll sum=0;
		FOR(i,26) sum+=ret[i][x];
		ma=max(ma,sum);
	}
	if(ma<-1LL<<54) {
		cout<<"Impossible"<<endl;
	}
	else {
		cout<<ma<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
