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
int A[2020];
ll from[2020],to[2020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,N) cin>>A[i];
	sort(A,A+N);
	
	FOR(i,N) from[i+1]=1LL<<60;
	while(M--) {
		FOR(i,N+1) to[i]=1LL<<60;
		FOR(x,N) {
			ll tot=0;
			for(y=x;y<N;y++) {
				tot+=A[y];
				to[y+1]=min(to[y+1],from[x]+tot*(y-x+1));
			}
		}
		
		swap(from,to);
	}
	cout<<from[N]<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
