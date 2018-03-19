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
int A[202020];
int B[202020];
int C[602020];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>A[i];
	FOR(i,N) cin>>B[i];
	
	int ret=0;
	FOR(i,29) {
		FOR(x,N) C[x]=B[x]&((1<<(i+1))-1);
		sort(C,C+N);
		FOR(x,2*N) C[N+x]=C[x]+(1<<(i+1));
		ll tot=0;
		FOR(x,N) {
			y=A[x]&((1<<(i+1))-1);
			tot += lower_bound(C,C+3*N,(4<<i)-y)-lower_bound(C,C+3*N,(3<<i)-y);
		}
		if(tot%2) ret+=1<<i;
	}
	
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
