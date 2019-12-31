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

int R,M,N;

double dodo(int id) {
	if(id<=0 || id>=N) return 0;
	double H=R-2.0*R*id/N;
	return sqrt(1LL*R*R-H*H)*2;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>R>>N>>M;
	double ret=0;
	
	for(i=1;i<=N+M-1;i++) ret += max(dodo(i),dodo(i-M));
	
	_P("%.12lf\n",ret);
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
