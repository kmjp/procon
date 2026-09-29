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
ll A[2020],B[2020];
ll V[1500][1500];
ll Ladd[2020][2020];
ll Radd[2020][2020];
ll Lcur[2020][2020];
ll Rcur[2020][2020];
ll S[2020][2020];
ll ret[2020][2020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,N) cin>>A[i];
	FOR(i,N) cin>>B[i];
	FOR(y,N) FOR(x,N) {
		V[y][x]=A[y]*B[x]%M;
	}
	
	FOR(i,4) {
		ZERO(Ladd);
		ZERO(Radd);
		ZERO(Lcur);
		ZERO(Rcur);
		
		ZERO(S);
		FOR(y,N) {
			ll LS=0;
			FOR(x,N) {
				LS+=Lcur[y][x]+Rcur[y][x];
				ret[y][x]+=LS;
				Ladd[y][x]+=V[y][x];
				Radd[y][x]-=V[y][x];
				Ladd[y+1][max(x-1,0)]+=Ladd[y][x];
				Radd[y+1][x+1]+=Radd[y][x];
				Lcur[y+1][max(x-1,0)]+=Lcur[y][x]+Ladd[y][x];
				Rcur[y+1][x+1]+=Rcur[y][x]+Radd[y][x];
			}
		}
		
		FOR(y,N) FOR(x,N) S[y][x]=V[N-1-x][y];
		FOR(y,N) FOR(x,N) V[y][x]=S[y][x];
		FOR(y,N) FOR(x,N) S[y][x]=ret[N-1-x][y];
		FOR(y,N) FOR(x,N) ret[y][x]=S[y][x];
	}
	
	ll sum=0;
	FOR(y,N) {
		FOR(x,N) sum^=ret[y][x]+y*N+x;
	}
	cout<<sum<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
