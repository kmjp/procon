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


int A,B;
string S,T;

ll dp[1010][1010];
int nex[1010][26][2];
const ll mo=998244353;


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>S>>T;
	A=S.size(),B=T.size();
	
	FOR(i,26) {
		nex[A][i][0]=A;
		nex[A+1][i][0]=A;
		nex[B][i][1]=B;
		nex[B+1][i][1]=B;
	}
	for(i=A-1;i>=0;i--) {
		FOR(j,26) nex[i][j][0]=nex[i+1][j][0];
		nex[i][S[i]-'a'][0]=i;
	}
	for(i=B-1;i>=0;i--) {
		FOR(j,26) nex[i][j][1]=nex[i+1][j][1];
		nex[i][T[i]-'a'][1]=i;
	}
	ll ret=mo-1;
	dp[0][0]=1;
	FOR(x,A+2) FOR(y,B+2) {
		if(x<=A||y<=B) ret+=dp[x][y];
		FOR(i,26) {
			int x2=min(nex[x][i][0]+1,A+1);
			int y2=min(nex[y][i][1]+1,B+1);
			(dp[x2][y2]+=dp[x][y])%=mo;
		}
		
	}
	
	
	cout<<ret%mo<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
