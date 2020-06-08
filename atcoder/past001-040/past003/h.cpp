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

int N,L;
int X[101010];
int A[3];
int T[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>L;
	FOR(i,N) {
		cin>>x;
		X[x]=1;
	}
	FOR(i,L+10) T[i]=1<<30;
	FOR(i,3) cin>>A[i];
	T[0]=0;
	
	FOR(i,L) {
		T[i+1]=min(T[i+1],T[i]+A[0]+X[i+1]*A[2]);
		T[i+2]=min(T[i+2],T[i]+A[0]+A[1]+X[i+2]*A[2]);
		if(i+1==L) T[L]=min(T[L],T[i]+A[0]/2+A[1]/2);
		T[i+4]=min(T[i+4],T[i]+A[0]+3*A[1]+X[i+4]*A[2]);
		if(i+4>L) T[L]=min(T[L],T[i]+A[0]/2+(L-i-1)*A[1]+A[1]/2);
	}
	cout<<T[L]<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
