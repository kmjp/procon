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
ll A[101010],B[101010];
ll SA,SB;


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>A[i];
		SA+=A[i];
	}
	FOR(i,N) {
		cin>>B[i];
		SB+=B[i];
	}
	if(SA>SB) return _P("No\n");
	ll R=SB-SA;
	
	ll RA=R,RB=R;
	FOR(i,N) {
		if(A[i]<B[i]) {
			ll a=(B[i]-A[i]+1)/2;
			A[i]+=a*2;
			RA-=a;
		}
		if(A[i]>B[i]) {
			RB-=A[i]-B[i];
			B[i]=A[i];
		}
	}
	
	
	if(RA<0 || RB<0) return _P("No\n");
	_P("Yes\n");
	
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
