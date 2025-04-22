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

const ll mo=998244353;
ll from[3][2][2]; // ˜A‘±‚µ‚Ä‚¢‚é”, ’·‚³1‚ÌŒÂ”, ÅŒã‚Ì’l
ll to[3][2][2];
int N;
string S;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>S;
	if(S[0]!='x') from[2][0][0]++;
	if(S[0]!='o') from[2][0][1]++;
	for(i=1;i<N;i++) {
		ZERO(to);
		
		if(S[i]!='x') {
			to[1][0][0]+=from[0][0][0];
			to[1][1][0]+=from[0][1][0];
			to[2][0][0]+=from[1][0][0];
			to[2][0][0]+=from[1][1][0];
			to[2][0][0]+=from[2][0][0];
			to[0][1][0]+=from[0][0][1];
			to[0][0][0]+=from[1][0][1];
			to[0][1][0]+=from[1][1][1];
			to[0][0][0]+=from[2][0][1];
		}
		if(S[i]!='o') {
			to[1][0][1]+=from[0][0][1];
			to[1][1][1]+=from[0][1][1];
			to[2][0][1]+=from[1][0][1];
			to[2][0][1]+=from[1][1][1];
			to[2][0][1]+=from[2][0][1];
			to[0][1][1]+=from[0][0][0];
			to[0][0][1]+=from[1][0][0];
			to[0][1][1]+=from[1][1][0];
			to[0][0][1]+=from[2][0][0];
		}
		
		FOR(x,3) FOR(y,2) FOR(k,2) from[x][y][k]=to[x][y][k]%mo;
	}
	
	ll ret=0;
	FOR(i,3) FOR(j,2) FOR(x,2) ret+=from[i][j][x];
	cout<<ret%mo<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
