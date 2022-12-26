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

int N,Q;

int T[51];
ll A[51],B[51];
ll F[51];
ll mo=998244353;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	for(i=2;i<=N;i++) cin>>T[i]>>A[i]>>B[i];
	
	F[0]=1;
	cin>>Q;
	while(Q--) {
		cin>>F[1];
		for(i=2;i<=N;i++) {
			if(T[i]==1) F[i]=(F[A[i]]+F[B[i]])%mo;
			if(T[i]==2) F[i]=A[i]*F[B[i]]%mo;
			if(T[i]==3) F[i]=(F[A[i]]*F[B[i]])%mo;
		}
		cout<<F[N]<<endl;
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
