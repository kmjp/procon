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

int N,X,Y,Z;
int A[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>X>>Y>>Z;
	FOR(i,N) {
		cin>>A[i];
		A[i]++;
		x=min(A[i]/10000,Z);
		Z-=x;
		A[i]-=x*10000;
	}
	sort(A,A+N);
	reverse(A,A+N);
	FOR(i,N) {
		if(A[i]&&Z) {
			A[i]=0;
			Z--;
		}
	}
	FOR(i,N) {
		x=min(A[i]/5000,Y);
		Y-=x;
		A[i]-=x*5000;
	}
	sort(A,A+N);
	reverse(A,A+N);
	FOR(i,N) {
		if(A[i]&&Y) {
			A[i]=0;
			Y--;
		}
	}
	FOR(i,N) {
		x=min((A[i]+999)/1000,X);
		X-=x;
		A[i]-=x*1000;
		if(A[i]>0) return _P("No\n");
	}
	_P("Yes\n");
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
