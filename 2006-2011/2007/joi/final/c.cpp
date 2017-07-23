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
int X[3030],Y[3030];
bool ok[5050][5050];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>X[i]>>Y[i];
		ok[X[i]][Y[i]]=1;
	}
	
	int ma=0;
	FOR(y,N) FOR(x,y) if((X[x]-X[y])*(X[x]-X[y])+(Y[x]-Y[y])*(Y[x]-Y[y])>ma) {
		int nx=X[y]-(Y[y]-Y[x]),ny=Y[y]+(X[y]-X[x]);
		if(nx<0 || nx>5000 || ny<0 ||  ny>=5000 || ok[nx][ny]==0) continue;
		nx=X[x]-(Y[y]-Y[x]),ny=Y[x]+(X[y]-X[x]);
		if(nx<0 || nx>5000 || ny<0 ||  ny>=5000 || ok[nx][ny]==0) continue;
		ma=(X[x]-X[y])*(X[x]-X[y])+(Y[x]-Y[y])*(Y[x]-Y[y]);
	}
	cout<<ma<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
