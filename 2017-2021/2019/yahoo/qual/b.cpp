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


int mat[4][4];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	FOR(i,3) {
		cin>>x>>y;
		mat[x-1][y-1]=mat[y-1][x-1]=1;
	}
	
	vector<int> V;
	FOR(i,4) V.push_back(i);
	do {
		if(mat[V[0]][V[1]] && mat[V[1]][V[2]] && mat[V[2]][V[3]]) {
			return _P("YES\n");
		}
		
	} while(next_permutation(ALL(V)));
	
	_P("NO\n");
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
