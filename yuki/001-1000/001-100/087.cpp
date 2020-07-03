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

ll N;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	
	ll dif=max(N-2800*2-2014,0LL)/2800;
	ll ret=dif*399;
	N -= dif*2800;
	
	y=1;
	for(x=2015;x<=N;x++) {
		if(x%400==0 || (x%100!=0 && x%4==0)) y++;
		if(y%7==0) ret++;
		y++;
	}
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
