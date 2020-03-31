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

map<pair<int,int>,int> M;
map<int,vector<int>> W;

int nex(int cur,int mask) {
	
	if(mask&(1<<((cur+3)%4))) return (cur+3)%4;
	if(mask&(1<<((cur+0)%4))) return (cur+0)%4;
	if(mask&(1<<((cur+1)%4))) return (cur+1)%4;
	return (cur+2)%4;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	x=y=0;
	while(1) {
		cin>>s;
		if(s=="Q") break;
		if(s=="E") {
			M[{x,y}] |= 1;
			x++;
			M[{x,y}] |= 4;
		}
		if(s=="N") {
			M[{x,y}] |= 8;
			y++;
			M[{x,y}] |= 2;
		}
		if(s=="W") {
			M[{x,y}] |= 4;
			x--;
			M[{x,y}] |= 1;
		}
		if(s=="S") {
			M[{x,y}] |= 2;
			y--;
			M[{x,y}] |= 8;
		}
	}
	
	auto m=M.begin()->first;
	int sx=m.first;
	int sy=m.second;
	int sd=nex(2,M[{sx,sy}]);
	
	int dir=sd;
	x=sx,y=sy;
	int step=0;
	
	while(1) {
		if(step && x==sx && y==sy && sd==dir) break;
		step++;
		
		if(dir==0) x++;
		if(dir==1) y--, W[y].push_back(x);
		if(dir==2) x--;
		if(dir==3) W[y].push_back(x),y++;
		dir=nex(dir,M[{x,y}]);
	}
	
	ll ret=0;
	FORR(w,W) {
		sort(ALL(w.second));
		
		for(i=0;i<w.second.size();i+=2) ret+=w.second[i+1]-w.second[i];
	}
	cout<<ret<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
