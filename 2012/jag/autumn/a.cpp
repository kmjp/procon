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

int N;
int mat[26][26];
string S[501];

void solve() {
	int i,j,k,l,r,x,y,z; string s;
	
	while(1) {
		cin>>N;
		if(N==0) return;
		ZERO(mat);
		FOR(i,N) cin>>S[i];
		FOR(i,N-1) {
			FOR(x,min(S[i].size(),S[i+1].size())) {
				if(S[i][x]==S[i+1][x]) continue;
				if(mat[S[i][x]-'a'][S[i+1][x]-'a']==1) {
					_P("no\n");
					goto out;
				}
				if(mat[S[i+1][x]-'a'][S[i][x]-'a']==0) {
					mat[S[i+1][x]-'a'][S[i][x]-'a']=1;
					FOR(x,26) FOR(y,26) FOR(z,26) mat[x][y] |= mat[x][z] & mat[z][y];
				}
				break;
			}
			if(x==min(S[i].size(),S[i+1].size()) && S[i].size()>S[i+1].size()) {
				_P("no\n");
				goto out;
			}
		}
		_P("yes\n");
		out:
		;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
