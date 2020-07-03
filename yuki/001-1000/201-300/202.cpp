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
int X[101000],Y[101000];

set<int> S[20200];
int ret;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>X[i]>>Y[i];
		int ok=1;
		for(x=max(0,X[i]-19);x<=min(20000,X[i]+19) && ok;x++) {
			int dy=sqrt(399-(x-X[i])*(x-X[i])+0.0001);
			for(y=max(0,Y[i]-dy);y<=min(20000,Y[i]+dy);y++) if(S[x].count(y)) ok=0;
		}
		if(ok) ret++, S[X[i]].insert(Y[i]);
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
