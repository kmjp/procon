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

ll A[2020][2020];
ll B[2020][2020];
int Y,X,S,L;
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q;
	while(Q--) {
		cin>>Y>>X>>L>>S;
		Y--,X--;
		A[Y][X]+=S;
		A[Y+L][X+L]-=S;
		B[Y+L][X]-=S;
		B[Y+L][X+L]+=S;
	}
	FOR(y,N) FOR(x,N) {
		if(y&&x) A[y][x]+=A[y-1][x-1];
	}
	FOR(y,N) FOR(x,N) {
		if(x) B[y][x]+=B[y][x-1];
	}
	FOR(y,N) FOR(x,N) {
		if(y) A[y][x]+=A[y-1][x];
		if(y) B[y][x]+=B[y-1][x];
	}
	
	FOR(y,N) {
		FOR(x,N) cout<<A[y][x]+B[y][x]<<" ";
		cout<<endl;
		
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
