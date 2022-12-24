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

int N,A,B,C;
int M[4][4];

ll from[4][4][4][4][4];
ll to[4][4][4][4][4];
const ll mo=998244353;
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>A>>B>>C;
	FOR(x,4) FOR(y,4) M[x][y]=(A*(x&y)+B*(x|y)+C*(x^y))%4;
	
	FOR(x,4) from[x][M[0][x]][M[1][x]][M[2][x]][M[3][x]]=1;
	int a,b0,b1,b2,b3;
	FOR(r,N-2) {
		ZERO(to);
		FOR(a,4) FOR(b0,4) FOR(b1,4) FOR(b2,4) FOR(b3,4) FOR(x,4) {
			int B[4]={b0,b1,b2,b3};
			(to[M[x][a]][B[M[0][x]]][B[M[1][x]]][B[M[2][x]]][B[M[3][x]]]+=from[a][b0][b1][b2][b3])%=mo;
		}
		swap(from,to);
	}
	ll ret=0;
	FOR(a,4) FOR(b0,4) FOR(b1,4) FOR(b2,4) FOR(b3,4) FOR(x,4) {
		int B[4]={b0,b1,b2,b3};
		if(M[a][x]==B[x]) ret+=from[a][b0][b1][b2][b3];
	}
	cout<<ret%mo<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
