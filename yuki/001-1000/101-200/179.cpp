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
string S[100],T[100];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	FOR(y,H) cin>>S[y];
	
	i=0;
	FOR(y,H) FOR(x,W) i+=S[y][x]=='#';
	if(i==0) return _P("NO\n");
	
	int dy,dx;
	for(dy=-H;dy<=H;dy++) {
		for(dx=-W;dx<=W;dx++) {
			if(dx==0 && dy==0) continue;
			
			FOR(y,H) T[y]=S[y];
			FOR(y,H) FOR(x,W) if(T[y][x]=='#') {
				int ty=y+dy,tx=x+dx;
				if(tx<0 || tx>=W || ty<0 || ty>=H) goto out;
				if(T[ty][tx]!='#') goto out;
				T[y][x]='R';
				T[ty][tx]='B';
			}
			return _P("YES\n");
			out:
			;
		}
	}
	_P("NO\n");
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
