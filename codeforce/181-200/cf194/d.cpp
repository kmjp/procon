#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int H,W;
int A[1005][1005];

void solve() {
	int i,j,k,l,r,x,y,y1,y2; string s;
	
	cin>>H>>W;
	FOR(y,H) FOR(x,W) cin>>A[y][x];
	
	int ret=0;
	FOR(y1,H) for(y2=y1+1;y2<H;y2++) {
		int t1=0,t2=0;
		FOR(x,W) {
			r=min(A[y1][x],A[y2][x]);
			if(r>t2) {
				if(r>t1) t2=t1, t1=r;
				else t2=r;
			}
		}
		ret=max(ret,t2);
	}
	
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
