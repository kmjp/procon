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

int A;

ll from[101][101][601];
ll to[101][101][601];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	double X;
	cin>>X;
	A=X*4+0.01;
	
	from[100][0][0]=1;
	FOR(i,6) {
		ZERO(to);
		FOR(x,101) FOR(y,101) FOR(j,i*100+1) if(from[x][y][j]) {
			FOR(k,101) to[min(x,k)][max(y,k)][j+k] += from[x][y][j];
		}
		swap(from,to);
	}
	
	ll ret=0;
	FOR(x,101) FOR(y,101) FOR(i,601) if(i-x-y==A) ret += from[x][y][i];
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
