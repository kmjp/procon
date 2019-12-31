#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int H,W;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	scanf("%d%d",&H,&W);
	if(H*W%2==1) {
		_P("First\n");
		fflush(stdout);
		_P("%d %d %d\n",H/2+1,W/2+1,1);
		fflush(stdout);
		while(1) {
			scanf("%d%d%d",&y,&x,&r);
			if(r==-1) break;
			_P("%d %d %d\n",H+1-y,W+1-x,r);
			fflush(stdout);
		}
	}
	else {
		_P("Second\n");
		fflush(stdout);
		while(1) {
			scanf("%d%d%d",&y,&x,&r);
			if(r==-1) break;
			_P("%d %d %d\n",H+1-y,W+1-x,r^1);
			fflush(stdout);
		}
	}
	
}


int main(int argc,char** argv){
	solve(); return 0;
}
