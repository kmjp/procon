#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int H,W;
ll A[51][51];
vector<pair<int,int> > V;
int ok[51][51];

int dist(int ty,int tx,int sy,int sx) {
	int y,x,i;
	int di[51][51];
	FOR(y,H) FOR(x,W) di[y][x]=100000;
	di[ty][tx]=0;
	queue<int> Q;
	Q.push(ty*100+tx);
	while(Q.size()) {
		int k=Q.front();
		Q.pop();
		int cy=k/100,cx=k%100;
		FOR(i,4) {
			int dx[4]={1,-1,0,0}, dy[4]={0,0,1,-1};
			int ttx=cx+dx[i],tty=cy+dy[i];
			if(ttx<0 || tty<0 || ttx>=W || tty>=H || ok[tty][ttx]==0) continue;
			if(di[tty][ttx]>di[cy][cx]+1) {
				di[tty][ttx]=di[cy][cx]+1;
				Q.push(tty*100+ttx);
			}
		}
	}
	return di[sy][sx];
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	V.clear();
	
	cin>>H>>W;
	FOR(y,H) FOR(x,W) {
		cin>>A[y][x];
		ok[y][x]=1;
		V.push_back(make_pair(A[y][x],y*100+x));
	}
	sort(V.begin(),V.end());
	
	y=V[0].second/100;
	x=V[0].second%100;
	for(i=1;i<V.size();i++) {
		int ty=V[i].second/100;
		int tx=V[i].second%100;
		ok[y][x]=0;
		int d=dist(y,x,ty,tx);
		if(d>=10000) return _P("NO\n");
		
		if(V[i].first-V[i-1].first<d) return _P("NO\n");
		if((V[i].first-V[i-1].first)%2!=d%2) return _P("NO\n");
		if(i==V.size()-1) {
			if(d!=1 || V[i].first-V[i-1].first!=1) return _P("NO\n");
		}
		
		x=tx; y=ty;
	}
	_P("YES\n");
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	int T;
	cin>>T;
	FOR(i,T) {
		_P("Case #%d:\n",i+1);
		solve();
	}
	return 0;
}
