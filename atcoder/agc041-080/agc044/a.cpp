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


int T;
ll N,A,B,C,D;
map<ll,__int128> M;

__int128 hoge(__int128 v) {
	if(v==0) return 0;
	if(M.count(v)) {
		if(M[v]==-1) return 1LL<<60;
		return M[v];
	}
	M[v]=-1;
	
	__int128 ret=1LL<<60;
	
	if(ret/v>D) ret=D*v;
	if(v%2==0) {
		ret=min(ret,A+hoge(v/2));
	}
	else {
		ret=min(ret,D+A+hoge((v+1)/2));
		ret=min(ret,D+A+hoge((v-1)/2));
	}
	if(v%3==0) {
		ret=min(ret,B+hoge(v/3));
	}
	else {
		ret=min(ret,(v%3)*D+B+hoge(v/3));
		ret=min(ret,(3-v%3)*D+B+hoge(v/3+1));
	}
	if(v%5==0) {
		ret=min(ret,C+hoge(v/5));
	}
	else {
		ret=min(ret,(v%5)*D+C+hoge(v/5));
		ret=min(ret,(5-v%5)*D+C+hoge(v/5+1));
	}
	
	return M[v]=ret;
	
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>A>>B>>C>>D;
		M.clear();
		cout<<(ll)hoge(N)<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
