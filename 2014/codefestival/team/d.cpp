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

int N;
string S[101];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	int nx=0,ny=0;
	FOR(y,N) cin>>S[y];
	FOR(x,N) {
		FOR(y,N) {
			if(S[y][x]=='X') nx+=y;
			if(S[y][x]=='Y') ny+=N-1-y;
		}
	}
	if(nx<ny) cout<<"Y"<<endl;
	if(nx>ny) cout<<"X"<<endl;
	if(nx==ny) cout<<"Impossible"<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
