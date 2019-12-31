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

int N,K;
vector<int> V[52];
int mat[52][52];
int bad[52];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	FOR(i,K) {
		cin>>x;
		FOR(j,x) cin>>y, V[i].push_back(y);
	}
	cin>>i;
	while(i--) cin>>x>>y, mat[x][y]=mat[y][x]=1;
	
	FOR(i,K) {
		FOR(y,V[i].size()) FOR(x,y) if(mat[V[i][x]][V[i][y]]) bad[V[i][x]]=bad[V[i][y]]=1;
	}
	cout<<count(bad,bad+52,1)<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
