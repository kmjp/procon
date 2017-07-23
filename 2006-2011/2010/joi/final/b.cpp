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
int C[10101];
int from[10101][2],to[10101][2];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N-1) cin>>C[i];
	
	FOR(i,N+1) from[i][0]=from[i][1]=1<<30;
	from[0][0]=0;
	
	FOR(i,N-1) {
		FOR(x,N+1) to[x][0]=to[x][1]=1<<30;
		FOR(x,N+1) {
			to[x+1][1]=min(from[x][1],from[x][0]+C[i]);
			to[x][0]=min(from[x][0],from[x][1]+C[i]);
		}
		
		swap(from,to);
	}
	
	cout<<min(from[N/2][0],from[N/2][1])<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
