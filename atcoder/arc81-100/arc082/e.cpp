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
ll X[202],Y[202];
ll mo=998244353;
int did[202][202];
ll p2[202];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>X[i]>>Y[i];
	
	ll ret=1;
	p2[0]=1;
	FOR(i,N) p2[i+1]=p2[i]*2%mo;
	
	ret=(p2[N]+mo-1-N-N*(N-1)/2)%mo;
	
	FOR(y,N) FOR(x,y) if(did[y][x]==0) {
		vector<int> V;
		V.push_back(x);
		V.push_back(y);
		FOR(i,N) if(i!=x && i!=y) if((X[i]-X[x])*(Y[y]-Y[x])-(X[y]-X[x])*(Y[i]-Y[x])==0) V.push_back(i);
		FORR(a,V) FORR(b,V) did[a][b]=1;
		r=V.size();
		if(r>=3) ret=(ret+mo-p2[r]+r+r*(r-1)/2+1)%mo;
	}
	
	
	cout<<(ret%mo+mo)%mo<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
