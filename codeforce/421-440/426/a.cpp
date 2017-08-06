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
int A,B;


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cprime();
	scanf("%d",&N);
	FOR(i,N) {
		scanf("%d%d",&A,&B);
		
		ll X=A,Y=B;
		
		if(X*X%Y!=0 || Y*Y%X!=0) {
			_P("NO\n");
			continue;
		}
		X*=Y;
		
		ll a=0;
		for(j=20;j>=0;j--) {
			ll b=a+(1LL<<j);
			if(b*b*b<=X) a=b;
		}
		if(a*a*a==X) {
			_P("YES\n");
		}
		else {
			_P("NO\n");
		}

	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
