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

int H,W;
typedef vector<vector<int> > TT;
TT v;
map<TT,int> P[2];

void dfs(TT& c,int zy,int zx,int num,int id) {
	int i;
	if(num>12) return;
	if(P[id].count(c) && P[id][c]<num) return;
	P[id][c]=num;
	
	FOR(i,4) {
		int dd[4]={1,0,-1,0};
		int ty=zy+dd[i],tx=zx+dd[i^1];
		if(tx<0 || ty<0 || tx>=W || ty>=H) continue;
		swap(c[zy][zx],c[ty][tx]);
		dfs(c,ty,tx,num+1,id);
		swap(c[zy][zx],c[ty][tx]);
	}
}


void solve() {
	int i,j,k,l,r,x,y;
	
	cin>>H>>W;
	TT s,t;
	FOR(y,H) s.push_back(vector<int>(W));
	FOR(y,H) t.push_back(vector<int>(W));
	int sy,sx;
	
	FOR(y,H) FOR(x,W) {
		cin>>s[y][x];
		if(s[y][x]==0) sx=x,sy=y;
		t[y][x]=((y)*W + (x+1))%(H*W);
	}
	dfs(s,sy,sx,0,0);
	dfs(t,H-1,W-1,0,1);
	int mi=24;
	ITR(it,P[0]) if(P[1].count(it->first)) mi=min(mi,it->second+P[1][it->first]);
	cout<<mi<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
