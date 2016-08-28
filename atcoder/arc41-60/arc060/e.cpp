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
int L;
int Q;
int X[101010];
int ne[101010][20];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>X[i];
	cin>>L;
	
	FOR(i,N) ne[i][0]=lower_bound(X+i,X+N,X[i]+L+1)-1-X;
	FOR(i,19) {
		FOR(x,N) ne[x][i+1]=ne[ne[x][i]][i];
	}
	
	cin>>Q;
	while(Q--) {
		cin>>x>>y;
		x--,y--;
		if(x>y) swap(x,y);
		
		int day=0;
		for(i=19;i>=0;i--) if(ne[x][i]<y) {
			x=ne[x][i];
			day+=1<<i;
		}
		
		cout<<day+1<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
