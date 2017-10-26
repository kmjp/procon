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

int N,X;
int A[101010];
int add[101010];
int sum[101010];

int hoge() {
	int pt=0;
	for(int i=1;i<N;i++) pt+=(1LL*pt*N < 1LL*i*A[i]);
	return pt;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>X;
	FOR(i,N) cin>>A[i];
	
	sort(A,A+N);
	if(hoge()<=X) goto out;
	
	reverse(A,A+N);
	if(X<=hoge()) goto out;
	
	reverse(A,A+N);
	{
		int num=N;
		for(i=20;i>=0;i--) {
			if(num-(1<<i)<0) continue;
			reverse(A+(num-(1<<i)),A+N);
			x = hoge();
			reverse(A+(num-(1<<i)),A+N);
			if(x>=X) num-=1<<i;
			
		}
		reverse(A+num,A+N);
	}
	out:
	FOR(i,N) _P("%d%c",A[i],(i==N-1)?'\n':' ');
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
