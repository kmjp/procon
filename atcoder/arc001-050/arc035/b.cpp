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
ll T[101000],fact[10100];
ll mo=1000000007;

void solve() {
	int i,j,k,l,r,x,y; string s;
	cin>>N;
	FOR(i,N) cin>>T[i];
	sort(T,T+N);
	
	ll tot=0,S=0;
	FOR(i,N) S+=T[i], tot+=S;
	fact[0]=1;
	FOR(i,N) fact[i+1]=fact[i]*(i+1)%mo;
	ll pat=1,suc=1;
	for(i=1;i<N;i++) {
		if(T[i]!=T[i-1]) {
			pat = pat*fact[suc]%mo;
			suc=0;
		}
		suc++;
	}
	pat = pat*fact[suc]%mo;
	
	cout<<tot<<endl;
	cout<<pat<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
