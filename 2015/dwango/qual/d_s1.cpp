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

int N,L;
int A[101000],B[101000],C[101000];
ll tot=0,TL;
vector<int> AA,BB;


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>L;
	FOR(i,N) {
		cin>>A[i]>>B[i]>>C[i];
		x=min(B[i],C[i]);
		B[i]-=x;
		C[i]-=x;
		tot+=B[i];
		FOR(x,B[i]) AA.push_back(i);
		FOR(x,C[i]) BB.push_back(i);
	}
	if(tot==0) return _P("0\n");
	
	ll mi=1LL<<60;
	FOR(x,tot) {
		ll t=0;
		FOR(y,tot) t += min(abs(A[BB[(x+y)%tot]]-A[AA[y]]),L-abs(A[BB[(x+y)%tot]]-A[AA[y]]));
		_P("%lld\n",t);
		mi=min(mi,t);
	}
	cout<<mi<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
