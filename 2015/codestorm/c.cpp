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
int A[101010];
int V[25050];
int S[25050];
ll C,R,O;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	
	FOR(i,N) cin>>A[i], V[A[i]]=1;
	FOR(i,22001) S[i+1]=S[i]+V[i+1];
	
	FOR(x,N) {
		for(y=x+1;y<N;y++) {
			
			int r=sqrt(A[y]*A[y]+A[x]*A[x])+1e-9;
			if(r*r==A[y]*A[y]+A[x]*A[x] && V[r]) {
				R++;
				C+=S[r-1]-S[A[y]];
				O+=S[A[x]+A[y]-1]-S[r];
			}
			else {
				C+=S[r]-S[A[y]];
				O+=S[A[x]+A[y]-1]-S[r];
			}
		}
	}
	_P("%lld %lld %lld\n",C,R,O);
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
