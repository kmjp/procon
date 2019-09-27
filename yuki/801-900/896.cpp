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

int M,N;
ll MX,AX,MY,AY,mo;
int X[1010],Y[1010],A[1010],B[1010];
ll Z[1<<24];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>M>>N>>MX>>AX>>MY>>AY>>mo;
	FOR(i,M) cin>>X[i];
	FOR(i,M) cin>>Y[i];
	FOR(i,M) cin>>A[i];
	FOR(i,M) cin>>B[i];
	
	ll px=X[M-1],py=Y[M-1];
	FOR(i,N) {
		if(i<M) {
			Z[X[i]]+=Y[i];
		}
		else {
			px=(px*MX+AX)%mo;
			py=(py*MY+AY)%mo;
			Z[px]+=py;
		}
	}
	for(i=1;i<mo;i++) {
		for(j=i*2;j<mo;j+=i) Z[i]+=Z[j];
	}
	
	ll pa=A[M-1],pb=B[M-1],xo=0;
	FOR(i,N) {
		
		ll ret=0;
		if(i<M) {
			if(A[i]<mo) {
				ret+=Z[A[i]];
				if(A[i]*B[i]<mo) ret-=Z[A[i]*B[i]];
			}
			cout<<ret<<endl;
		}
		else {
			pa=(pa*MX+AX+mo-1)%mo+1;
			pb=(pb*MY+AY+mo-1)%mo+1;
			if(pa<mo) {
				ret+=Z[pa];
				if(pa*pb<mo) ret-=Z[pa*pb];
			}
		}
		xo^=ret;
	}
	cout<<xo<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
