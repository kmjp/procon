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

ll N;
vector<ll> V;
map<ll,int> M;

ll dodo(ll L) {
	if(L==0) return 0;
	if(M.count(L)) return M[L];
	
	ll ret=L;
	FORR(r,V) if(r<=L) ret=min(ret,(L%r)+dodo(L/r));
	return M[L]=ret;
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	FOR(i,2) {
		V.push_back(i*3+2);
		while(V.back()*10<1LL<<60) V.push_back(V.back()*10+(7-V.back()%10));
	}
	
	cin>>N;
	cout<<dodo(N)<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
