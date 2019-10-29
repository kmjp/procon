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

int N,A,B,C,D;
string S;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>A>>B>>C>>D;
	cin>>S;
	A--,B--,C--,D--;
	x=A;
	while(x<C) {
		if(x+1==C) break;
		if(x+2==C) break;
		if(S[x+1]=='.') {
			x++;
			continue;
		}
		if(S[x+2]=='.') {
			x+=2;
			continue;
		}
		return _P("No\n");
	}
	
	x=B;
	while(x<D) {
		if(x+1==D) break;
		if(x+2==D) break;
		if(S[x+1]=='.') {
			x++;
			continue;
		}
		if(S[x+2]=='.') {
			x+=2;
			continue;
		}
		return _P("No\n");
	}
	
	if(C>D) {
		int ok=0;
		for(i=B;i<=D;i++) {
			if(S[i-1]=='.' && S[i]=='.' && S[i+1]=='.') ok=1;
		}
		if(ok==0) return _P("No\n");
	}
	cout<<"Yes"<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
