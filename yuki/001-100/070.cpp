#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

void solve() {
	int i,j,k,l,r,x1,y1,x2,y2; string s;
	int N;
	scanf("%d",&N);
	int x=0;
	while(N--) {
		scanf("%d:%d %d:%d",&x1,&y1,&x2,&y2);
		i=x1*60+y1;
		j=x2*60+y2;
		if(i>j) j+=24*60;
		x+=j-i;
	}
	cout<<x<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
