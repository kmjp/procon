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

int N,Y;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Y;
	Y/=1000;
	FOR(i,N+1) {
		x=Y-10*i;
		y=N-i;
		if((x-y)%4) continue;
		int a=(x-y)/4;
		int b=y-a;
		if(a<0 || a>y) continue;
		if(b<0 || b>y) continue;
		_P("%d %d %d\n",i,a,b);
		return;
		
	}
	_P("-1 -1 -1\n");
	
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
