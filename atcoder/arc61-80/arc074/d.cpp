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
ll A[303030];
set<pair<ll,int>> L,M,R;
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,3*N) cin>>A[i];
	ll X=0,Y=0;
	FOR(i,N) {
		L.insert({A[i],i});
		X+=A[i];
	}
	for(i=N;i<3*N;i++) {
		R.insert({A[i],i});
	}
	FOR(i,N) {
		Y+=R.begin()->first;
		M.insert(*R.begin());
		R.erase(R.begin());
	}
	ll ret=X-Y;
	for(i=N;i<2*N;i++) {
		L.insert({A[i],i});
		X+=A[i];
		X-=L.begin()->first;
		L.erase(L.begin());
		
		if(M.count({A[i],i})) {
			Y-=A[i];
			M.erase({A[i],i});
			M.insert(*R.begin());
			Y+=R.begin()->first;
			R.erase(R.begin());
		}
		else {
			R.erase({A[i],i});
		}
		ret=max(ret,X-Y);
		
	}
	
	cout<<ret<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
