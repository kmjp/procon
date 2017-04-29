#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N;
ll T;
ll W[101],V[101];
ll from[101][303];
ll to[101][303];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>T;
	
	FOR(i,N) {
		cin>>W[i]>>V[i];
		FOR(x,100) FOR(y,300) {
			to[x+1][y+W[i]-W[0]]=max(to[x+1][y+W[i]-W[0]],from[x][y]+V[i]);
		}
		memmove(from,to,sizeof(from));
	}
	
	ll ret=0;
	FOR(x,101) FOR(y,301) if(W[0]*x+y<=T) ret=max(ret,from[x][y]);
	
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
