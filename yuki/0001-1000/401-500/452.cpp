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

int N,M;
int C[101][101];
vector<vector<int>> V[202];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,M) {
		FOR(y,N) FOR(x,N) cin>>C[y][x];
		FOR(y,N) {
			V[i].push_back(vector<int>());
			FOR(x,N) V[i].back().push_back(C[y][x]);
			sort(ALL(V[i].back()));
		}
		FOR(x,N) {
			V[i].push_back(vector<int>());
			FOR(y,N) V[i].back().push_back(C[y][x]);
			sort(ALL(V[i].back()));
		}
		V[i].push_back(vector<int>());
		FOR(y,N) V[i].back().push_back(C[y][y]);
		sort(ALL(V[i].back()));
		V[i].push_back(vector<int>());
		FOR(y,N) V[i].back().push_back(C[y][N-1-y]);
		sort(ALL(V[i].back()));
	}
	int mi=1010;
	FOR(y,M) FOR(x,y) {
		FORR(v1,V[y]) FORR(v2,V[x]) {
			int num=0,i1=0,i2=0;
			while(i1<N || i2<N) {
				if(i1==N) num++, i2++;
				else if(i2==N) num++, i1++;
				else if(v1[i1]==v2[i2]) num++,i1++,i2++;
				else if(v1[i1]<v2[i2]) num++,i1++;
				else num++,i2++;
			}
			mi=min(mi,num-1);
		}
	}
	_P("%d\n",mi);
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
