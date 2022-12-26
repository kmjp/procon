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
int M[1010][1010];
set<int> S[1010][1010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	vector<pair<int,int>> V;
	FOR(y,H) FOR(x,W) {
		cin>>M[y][x];
		V.push_back({M[y][x],y*1000+x});
	}
	sort(ALL(V));
	int ret=0;
	FORR(e,V) {
		int cy=e.second/1000;
		int cx=e.second%1000;
		
		set<int> T;
		int dd[4]={1,0,-1,0};
		FOR(i,4) {
			int ty=cy+dd[i];
			int tx=cx+dd[i^1];
			if(ty<0 || ty>=H || tx<0||tx>=W||M[ty][tx]>M[cy][cx]) continue;
			FORR(r,S[ty][tx]) S[cy][cx].insert(r);
		}
		
		if(S[cy][cx].empty()) S[cy][cx].insert(cy*1000+cx);
		if(S[cy][cx].size()>1) {
			ret++;
			while(S[cy][cx].size()>2) S[cy][cx].erase(S[cy][cx].begin());
		}
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
