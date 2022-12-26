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

int N,M;
int rr[21][21];
int yes[21];

void solve() {
	int i,j,k,l,r,x,y,z; string s;
	
	cin>>N>>M;
	
	FOR(i,M) cin>>x>>y>>r, rr[x][y]=r;
	
	double ret=0;
	for(int mask=0;mask<1<<N;mask++) {
		FOR(x,N) yes[x]=(mask>>x)&1;
		if(yes[0]==0 || yes[N-1]==0) continue;
		
		double pat=1;
		for(x=1;x<N;x++) {
			double hoge=1;
			FOR(y,N) if(yes[y]&&rr[y][x]) hoge*=(100-rr[y][x])/100.0;
			if(yes[x]) pat*=1-hoge;
			else pat*=hoge;
		}
		ret += pat;
	}
	_P("%.12lf\n",ret);
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
