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

ll A[2];
ll B[2];
ll C,D;

void solve() {
	string s;
	
	cin>>A[0]>>A[1];
	cin>>B[0]>>B[1];
	cin>>C>>D;
	
	ll x=min(C,A[1]);
	ll y=C-x;
	A[0]-=y;
	A[1]-=x;
	B[0]+=y;
	B[1]+=x;
	x=min(D,B[0]);
	y=D-x;
	cout<<A[0]+x<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
