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
int T[202020],F[202020];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>A[i];
		B[A[i]]=i+1;
	}
	
	T[N]=0;
	F[N]=N;
	for(i=N-1;i>=1;i--) {
		if(T[i+1]==0) {
			if(B[i]<B[i+1]) {
				T[i]=0;
				F[i]=i;
			}
			else {
				T[i]=1;
				F[i]=i+1;
			}
		}
		else {
			if((B[F[i+1]]<B[i] && B[i]<B[i+1]) || (B[i]<B[i+1] &&  B[i+1]<B[F[i+1]]) || (B[i+1]<B[F[i+1]] && B[F[i+1]]<B[i])) {
				T[i]=T[i+1];
				F[i]=F[i+1];
			}
			else {
				T[i]=T[i+1]+1;
				F[i]=i+1;
			}
		}
	}
	cout<<T[1]<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
