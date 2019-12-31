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

ll A,B,K;
ll pata,patb;

ll move(__int128_t num) {
	if(num==1) return 1;
	return 2*(num+num*B/A-(num*B/A!=(num-1)*B/A));
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>A>>B>>K;
	ll g=__gcd(A,B);
	A/=g; B/=g;
	if(A<B) swap(A,B);
	
	if(K==0) return _P("1\n");
	
	for(i=40;i>=0;i--) if(move(pata+(1LL<<i))<=K) pata += 1LL<<i;
	for(i=40;i>=0;i--) if(move(patb+(1LL<<i))-2<=K) patb += 1LL<<i;
	cout << min(pata+patb,A)+1 << endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
