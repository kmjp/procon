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

int H,W,K;
string S;
ll A[101000];
ll B[101000];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W>>K>>S;
	
	ll ret;
	if(S=="*") {
		ll a=0,b=0;
		FOR(x,W) {
			cin>>A[x];
			a+=A[x];
		}
		FOR(y,H) {
			cin>>B[y];
			b+=B[y];
		}
		ret=(a%K)*(b%K)%K;
	}
	else {
		ll a=0,b=0;
		FOR(x,W) {
			cin>>A[x];
			ret+=H*A[x];
		}
		FOR(y,H) {
			cin>>B[y];
			ret+=W*B[y];
		}
		ret%=K;
	}
	
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
