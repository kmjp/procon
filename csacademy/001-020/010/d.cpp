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
ll A[10101];
ll hoge[10101];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>A[i];
	
	ll ret=0;
	FOR(i,N) {
		ZERO(hoge);
		y=5000;
		for(x=i;x<N;x++) {
			if(A[x]>A[i]) y++;
			else y--;
			if(y>=0 && y<=10000) hoge[y] += x+1;
		}
		y=5000;
		for(x=i;x>=0;x--) {
			if(A[x]>=A[i]) y--;
			else y++;
			if(y>=0 && y<=10000) ret += A[i]*(1+x)*hoge[y];
		}
	}
	cout<<ret<<endl;
}




int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
