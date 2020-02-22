#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N,K;
string S;
ll mo=1000000007;
ll M[2][302][302];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	
	cin>>N>>K>>S;
	M[0][0][0]=1;
	FOR(i,N) {
		int cur=i&1,tar=cur^1;
		ZERO(M[tar]);
		
		FOR(x,K+1) FOR(y,K+1) if(M[cur][x][y]) {
			ll& c=M[cur][x][y];
			if(S[i]=='0' || S[i]=='?') {
				if(y>0) (M[tar][x][y-1] += c)%=mo;
				if(y==0 && x<K) (M[tar][x+1][0] += c)%=mo;
			}
			if(S[i]=='1' || S[i]=='?') {
				if(y<x) (M[tar][x][y+1] += c)%=mo;
				if(y==x && y<K) (M[tar][x+1][x+1] += c)%=mo;
			}
		}
	}
	
	ll ret=0;
	FOR(x,K+1) FOR(y,K+1) ret += M[N%2][x][y];
	cout<<ret%mo<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
