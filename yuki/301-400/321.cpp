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

ll P,Q;
int N;
ll X[101010],Y[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	int ret=0;
	cin>>P>>Q>>N;
	if(P>Q) swap(P,Q);
	
	FOR(i,N) cin>>X[i]>>Y[i];
	if(Q) {
		int g=__gcd(P,Q);
		if(((P/g)+(Q/g))%2) {
			FOR(i,N) if(X[i]%g==0 && Y[i]%g==0) ret++;
		}
		else {
			FOR(i,N) if(X[i]%g==0 && Y[i]%g==0 && abs(X[i]/g+Y[i]/g)%2==0) ret++;
		}
	}
	else {
		FOR(i,N) if(X[i]==0 && Y[i]==0) ret++;
	}
	
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
