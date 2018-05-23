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

int T,testcase;
int R,B;
int from[501][501];

void solve(int TC) {
	int i,j,k,l,r,x,y; string s;
	
	cin>>R>>B;
	ZERO(from);
	FOR(x,501) FOR(y,501) from[x][y]=-10101;
	from[R][B]=0;
	
	int ma=0;
	FOR(x,40) FOR(y,40) if(x*(x-1)/2*(y+1)<=R && y*(y-1)/2*(x+1)<=B && x+y>0) {
		for(i=x;i<=R;i++) for(j=y;j<=B;j++) {
			from[i-x][j-y]=max(from[i-x][j-y],from[i][j]+1);
			ma=max(ma,from[i-x][j-y]);
		}
	}
	
	_P("Case #%d: %d\n",TC, ma);
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0);
	
	cin>>T;
	for(testcase=1;testcase<=T;testcase++) solve(testcase);
	return 0;
}
