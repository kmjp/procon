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



int N,S,T;
int A[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>S>>T;
	S--,T--;
	
	T=(T-S+N)%N;
	FOR(i,N) cin>>A[(i-S+N)%N];
	ll ret=0;
	for(i=0,j=T;i<j;i++,j--) {
		ret+=A[i];
		ret-=A[j];
	}
	int step=0;
	if(i==j) step=A[i];
	for(i=N-1,j=T+1;j<i;j++,i--) {
		ret+=A[i];
		ret-=A[j];
	}
	int step2=0;
	if(i==j) step2=A[j];
	ret+=max(step,step2)-min(step,step2);
	cout<<ret<<endl;
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
