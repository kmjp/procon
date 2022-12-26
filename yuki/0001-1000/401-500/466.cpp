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

int A,B,C,D;

vector<pair<int,int>> V;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>A>>B>>C>>D;
	if(A==C && B==C) {
		if(A==1) return _P("-1\n");
		FOR(i,A) V.push_back({i,(i+1)%A});
	}
	else if(A==C) {
		x=1,y=2;
		FOR(i,B-A-1) V.push_back({x,y}),x=y++;
		V.push_back({x,0});
		x=0;
		FOR(i,A-1) V.push_back({x,y}),x=y++;
	}
	else if(B==C) {
		x=0,y=2;
		FOR(i,A-B-1) V.push_back({x,y}),x=y++;
		V.push_back({x,1});
		x=1;
		FOR(i,B-1) V.push_back({x,y}),x=y++;
	}
	else if(C==0) {
		x=2;
		FOR(i,A-1) V.push_back({0,x++});
		FOR(i,B-1) V.push_back({1,x++});
	}
	else {
		V.push_back({0,2});
		V.push_back({1,2});
		x=2,y=3;
		FOR(i,C-1) V.push_back({x,y}),x=y++;
		x=y;
		FOR(i,A-(C+1)) V.push_back({0,x++});
		FOR(i,B-(C+1)) V.push_back({1,x++});
	}
	
	if(V.size()>D) _P("-1\n");
	else {
		int ma=1;
		FORR(v,V) ma=max(ma,max(v.first,v.second));
		_P("%d %d\n",ma+1,V.size());
		FORR(v,V) _P("%d %d\n",v.first,v.second);
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
