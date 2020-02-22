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

int H,W,h,w;
int G[505][505];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W>>h>>w;
	if(h==1&&w==1) return _P("No\n");
	ll sum=0;
	ll mul=999999999/(h*w-1);
	FOR(y,H) {
		FOR(x,W) {
			G[y][x]=mul;
			if((y%h==h-1) && (x%w==w-1)) G[y][x]=-mul*(h*w-1)-1;
			sum += G[y][x];
		}
	}
	
	if(sum<=0) return _P("No\n");
	_P("Yes\n");
	FOR(y,H) FOR(x,W) _P("%d%c",G[y][x],(x==W-1)?'\n':' ');
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
