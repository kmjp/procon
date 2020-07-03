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
ll K;
vector<ll> A,B;
ll mo=1000000007;
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	FOR(i,N) {
		cin>>x;
		if(x*2<=K) A.push_back(x);
		else B.push_back(x);
	}
	sort(ALL(A));
	sort(ALL(B));
	if(B.size()>A.size()) return _P("0\n");
	
	reverse(ALL(B));
	ll ret=1;
	FOR(i,B.size()) {
		x=lower_bound(ALL(A),K-B[i]+1)-A.begin();
		if(x<=i) return _P("0\n");
		ret=ret*(x-i)%mo;
	}
	
	x=A.size()-B.size();
	while(x) {
		ret=ret*(x-1)%mo;
		x-=2;
	}
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
