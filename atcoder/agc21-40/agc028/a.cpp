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

int N,M;
string S,T;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>S>>T;
	
	ll g=__gcd(N,M);
	ll L=N/g*M;
	ll a=L/N;
	ll b=L/M;
	
	int ok=1;
	FOR(i,N) if(i*a%b==0 && S[i]!=T[i*a/b]) ok=0;
	if(ok==1) {
		cout<<L<<endl;
	}
	else {
		cout<<-1<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
