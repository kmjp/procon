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

int A,B;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>A>>B;
	int mia=1000001,mib=10000001;
	FOR(x,1001) FOR(y,1001) if(x+y>0) {
		double aa=100.0*x/(x+y);
		double bb=100.0*y/(x+y);
		if((int)(aa+0.5)==A && (int)(bb+0.5)==B) {
			if(x+y<mia+mib) mia=x,mib=y;
		}
	}
	_P("%d\n",mia+mib);
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
