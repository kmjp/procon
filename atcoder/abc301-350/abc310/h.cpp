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
ll H;
int C[303],D[303];
ll dp[608][608];
ll ma[606];
ll cand[606*606];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>H;
	FOR(i,N) {
		cin>>C[i]>>D[i];
		C[i]=-C[i];
	}
	
	FOR(x,606) FOR(y,603) dp[x][y]=ma[x]=-1LL<<61;
	dp[0][0]=0;
	FOR(x,601) {
		FOR(y,603) if(dp[x][y]>=0) {
			FOR(i,N) if(y+C[i]>=0&&y+C[i]<=600) chmax(dp[x+1][y+C[i]],dp[x][y]+D[i]);
			chmax(ma[x],dp[x][y]);
		}
	}
	ll ret=1LL<<61;
	FOR(x,601*301) {
		if(cand[x]>=H) {
			ret=min(ret,(ll)x);
		}
		else {
			for(y=1;y<=600;y++) if(ma[y]>=0) {
				chmax(cand[x+y],cand[x]+ma[y]);
				ret=min(ret,x+(H-cand[x]+ma[y]-1)/ma[y]*y);
			}
		}
		
	}
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
