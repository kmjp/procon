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

string S,T;
int A,B;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>S>>T;
	A=S.size();
	B=T.size();
	FOR(i,2) {
		int turn=i;
		int s=0,t=0;
		x=0;
		while(x<A) {
			if(turn==0) {
				while(s<A && S[x]!=S[s]) s++;
				if(s==A) break;
				s++;
			}
			else {
				while(t<B && S[x]!=T[t]) t++;
				if(t==B) break;
				t++;
			}
			x++;
			turn^=1;
		}
		if(x==S.size()) return _P("Yes\n");
	}
	_P("No\n");
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
