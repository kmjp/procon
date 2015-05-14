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

int N,M,K;

string S[50];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>K;
	k=K;
	FOR(y,N) FOR(x,M) S[y]+="#";
	if(K==N+M-(N==M)) return _P("Impossible\n");
	
	if(K==1) {
		S[0][0]=S[0][1]=S[1][0]=S[1][1]=S[2][0]='.';
	}
	else if(K<=min(N,M)*2-(N!=M) && K) {
		FOR(y,K/2) S[y][y]='.';
		if(K!=N+M) {
			if(N>=M) S[K/2][K/2-1]='.';
			else S[K/2-1][K/2]='.';
			if(K%2) {
				if(N>=M) S[K/2+1][K/2-1]='.';
				else S[K/2-1][K/2+1]='.';
			}
		}
	}
	else if(K) {
		FOR(i,max(N,M)) {
			if(K<=0) continue;
			if(i<min(N,M)-1) S[i][i]='.', K-=2;
			else S[min(i,N-1)][min(i,M-1)]='.', K-=1;
		}
	}
	
	FOR(y,N) cout<<S[y]<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
