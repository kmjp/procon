#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	
	if(N<=8) {
		_P("%d\n",N*(N-1)*(N-2)/6);
		FOR(i,N) FOR(x,i) FOR(y,x) _P("%d %d %d\n",y+1,x+1,i+1);
	}
	else if(N%2==1) {
		_P("%d\n",N*(N-1)/2);
		FOR(i,N) {
			for(j=1;j<=(N-1)/2;j++) _P("%d %d %d\n",i+1,(i+N-j)%N+1,(i+j)%N+1);
		}
	}
	else {
		_P("%d\n",(N-1)*((N-2)/2*2-1) + (N-1)*3);
		FOR(i,N-1) {
			for(j=1;j<=(N-2)/2;j++) _P("%d %d %d\n",i+1,(i+(N-1)-j)%(N-1)+1,(i+j)%(N-1)+1);
			for(j=2;j<=(N-2)/2;j++) _P("%d %d %d\n",i+1,(i+(N-1)-j)%(N-1)+1,(i+j)%(N-1)+1);
		}
		FOR(i,N-1) _P("%d %d %d\n",N,i+1,(i+1)%(N-1)+1);
		FOR(i,N-1) _P("%d %d %d\n",N,i+1,(i+1)%(N-1)+1);
		FOR(i,N-1) _P("%d %d %d\n",N,i+1,(i+2)%(N-1)+1);
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
