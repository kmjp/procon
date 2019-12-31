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

int H1,M1,H2,M2;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H1>>M1;
	cin>>H2>>M2;
	
	while(H2<12) {
		if(H2*60+M2<=H1*60+M1) return _P("Yes\n");
		int H3=(H2+6)%12;
		int M3=(M2+30)%60;
		if(H3*60+M3<=H1*60+M1) return _P("Yes\n");
		M2++;
		if(M2>=60) M2-=60, H2++;
	}
	_P("No\n");
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
