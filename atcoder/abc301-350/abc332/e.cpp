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

int N,D;
ll W[15];
double V[1<<15];
double dp[16][1<<15];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>D;
	double A=0;
	FOR(i,N) {
		cin>>W[i];
		A+=W[i];
	}
	A/=D;
	
	int mask;
	FOR(mask,1<<N) {
		FOR(i,N) if(mask&(1<<i)) V[mask]+=W[i];
		V[mask]=(V[mask]-A)*(V[mask]-A)/D;
	}
	FOR(i,D+1) FOR(mask,1<<N) dp[i][mask]=1e18;
	dp[0][0]=0;
	FOR(i,D) {
		FOR(mask,1<<N) {
			int sm=((1<<N)-1)-mask;
			for(int smask=sm;smask>=0;smask--) {
				smask&=sm;
				chmin(dp[i+1][mask|smask],dp[i][mask]+V[smask]);
				if(smask==0) break;
			}
		}
	}
	
	_P("%.12lf\n",dp[D][(1<<N)-1]);
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
