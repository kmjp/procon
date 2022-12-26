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

ll W,H;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	
	ll ret=0;
	if(H%2 + W%2 == 0) {
		while(H&&W) {
			ret += 2*(W+H-1);
			W-=2;
			H-=2;
		}
		if(H||W) ret++;
	}
	else if(H%2 + W%2 == 1) {
		ret = (W+1)*(H+1) - ((H%2)?H:W);
	}
	else if(H%2 + W%2 == 2) {
		ret = (W+1)*(H+1) - min(H,W);
	}
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
