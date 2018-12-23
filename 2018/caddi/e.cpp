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
ll A[201010];
int L[202020];
int R[202020];
ll LSS[202020];
ll RSS[202020];

ll B[201010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>A[i];
	
	FOR(i,N) B[i]=A[i];
	for(i=N-2;i>=0;i--) {
		LSS[i]=LSS[i+1];
		while(1) {
			x=lower_bound(B+i+1,B+N,B[i])-B;
			if(x==i+1) break;
			for(j=i+1;j<x;j++) {
				B[j]*=4;
				LSS[i]+=2;
			}
			for(j=x;j<N;j++) {
				if(B[j]>1LL<<40) {
					LSS[i]+=(N-j)*2;
					break;
				}
				if(B[j]>=B[j-1]) break;
				B[j]*=4;
				LSS[i]+=2;
			}
		}
	}
	FOR(i,N) B[N-i-1]=A[i];
	for(i=0;i<N;i++) {
		if(i) RSS[i]=RSS[i-1];
		RSS[i]++;
		while(1) {
			x=lower_bound(B+(N-1-i)+1,B+N,A[i])-B;
			if(x==(N-1-i)+1) break;
			for(j=(N-1-i)+1;j<x;j++) {
				B[j]*=4;
				RSS[i]+=2;
			}
			for(j=x;j<N;j++) {
				if(B[j]>1LL<<40) {
					RSS[i]+=(N-j)*2;
					break;
				}
				if(B[j]>=B[j-1]) break;
				B[j]*=4;
				RSS[i]+=2;
			}
		}
	}
	
	
	
	ll mi=LSS[0];
	
	for(i=1;i<N;i++) {
		ll tot=LSS[i]+RSS[i-1];
		mi=min(mi,tot);
	}
	cout<<mi<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
