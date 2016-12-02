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
ll B[101010];
ll A[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	
	A[0]=0;
	FOR(i,N) {
		cin>>B[i];
		if(i%2==0) A[i+1]=B[i]-A[i];
		else A[i+1]=A[i]-B[i];
	}
	
	ll mi=A[0];
	FOR(i,N+1) if(i%4==0 || i%4==3) mi=min(mi,A[i]);
	if(mi<1) {
		FOR(i,N+1) {
			if(i%4==0 || i%4==3) A[i]-=mi-1;
			else A[i]+=mi-1;
			
		}
	}
	mi=A[1];
	FOR(i,N+1) if(i%4==1 || i%4==2) mi=min(mi,A[i]);
	if(mi<1) {
		FOR(i,N+1) {
			if(i%4==0 || i%4==3) A[i]+=mi-1;
			else A[i]-=mi-1;
		}
	}
	FOR(i,N+1) if(A[i]<=0) return _P("-1\n");
	
	
	cout<<N+1<<endl;
	FOR(i,N+1) cout<<A[i]<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
