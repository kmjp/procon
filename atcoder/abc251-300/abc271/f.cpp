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
ll A[20][20];
unordered_map<ll,ll> M[21][21];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(y,N) FOR(x,N) cin>>A[y][x];
	
	M[0][0][A[0][0]]=1;
	for(i=0;i<N-1;i++) {
		for(y=0;y<=i;y++) {
			x=i-y;
			FORR2(a,b,M[y][x]) {
				M[y+1][x][a^A[y+1][x]]+=b;
				M[y][x+1][a^A[y][x+1]]+=b;
			}
		}
	}
	M[N-1][N-1][A[N-1][N-1]]=1;
	for(i=2*N-2;i>=N+1;i--) {
		FOR(y,N) {
			x=i-y;
			if(x<0||x>=N) continue;
			assert(y>0&&x>0);
			FORR2(a,b,M[y][x]) {
				M[y-1][x][a^A[y-1][x]]+=b;
				M[y][x-1][a^A[y][x-1]]+=b;
			}
		}
	}
	
	ll ret=0;
	FOR(y,N) {
		x=N-1-y;
		FORR2(a,b,M[y][x]) {
			ret+=M[y+1][x][a]*b;
			ret+=M[y][x+1][a]*b;
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
