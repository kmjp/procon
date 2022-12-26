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
int A[10101];
ll B[10101];

bool isprime(ll v) {
	for(ll i=2;i*i<=v;i++) if(v%i==0) return false;
	return (v!=1);
}



void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	j=0;
	int g=0;
	N++;
	FOR(i,N) {
		cin>>A[i];
		g=__gcd(g,abs(A[i]));
	}
	
	reverse(A,A+N);
	
	set<int> cand;
	
	for(i=1;i*i<=g;i++) {
		if(g%i==0) {
			cand.insert(i);
			cand.insert(g/i);
		}
	}
	for(i=2;i<=20005;i++) cand.insert(i);
	
	
	FORR(c,cand) if(isprime(c) && A[0]%c==0) {
		ZERO(B);
		FOR(i,N) B[i%(c-1)]+=A[i];
		FOR(i,N) if(B[i%(c-1)]%c) break;
		if(i==N) cout<<c<<endl;
	}
	
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
