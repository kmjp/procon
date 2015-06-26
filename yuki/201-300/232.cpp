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

int T,A,B;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T>>A>>B;
	if(A>T || B>T) return _P("NO\n");
	if(T==1 && A==0 && B==0) return _P("NO\n");
	
	_P("YES\n");
	if((T-A)%2==1 && (T-B)%2==1) {
		if(A==0) _P("v\n"), A++;
		else _P("^\n"), A--;
		if(B==0) _P("<\n"), B++;
		else _P(">\n"), B--;
		T-=2;
	}
	FOR(i,T) {
		if(i<A) _P("^");
		else if((T-A)%2==0) _P("%c","^v"[(i-A)%2]);
		if(i<B) _P(">");
		else if((T-B)%2==0) _P("%c","><"[(i-B)%2]);
		_P("\n");
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
