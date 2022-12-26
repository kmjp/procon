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

int H,W;
string A[101010];
int R[101010],C[101010];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	FOR(y,H) {
		cin>>A[y];
		FOR(x,W) {
			R[y] |= 1<<(A[y][x]-'0');
			C[x] |= 1<<(A[y][x]-'0');
		}
	}
	if(H==1) {
		if(R[0]!=3) return _P("NO\n");
		cout<<"YES"<<endl;
	}
	else if(W==1) {
		if(C[0]!=3) return _P("NO\n");
		cout<<"YES"<<endl;
	}
	else {
		int ng=0;
		FOR(y,H) if(R[y]!=3) ng=1;
		if(ng==0) return _P("YES\n");
		ng=0;
		FOR(x,W) if(C[x]!=3) ng=1;
		if(ng==0) return _P("YES\n");
		return _P("NO\n");
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
