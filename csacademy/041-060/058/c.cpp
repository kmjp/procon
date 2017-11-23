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
set<pair<int,int>> S;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,M) {
		cin>>x>>y;
		S.insert({x-1,y-1});
		S.insert({y-1,x-1});
	}
	
	int ma=0;
	FOR(i,N) {
		x=i-1;
		y=i+1;
		while(1) {
			if(S.count({x,y})==0) break;
			x--;
			y++;
		}
		ma=max(ma,y-x-1);
	}
	FOR(i,N-1) if(S.count({i,i+1})) {
		x=i-1;
		y=i+2;
		while(1) {
			if(S.count({x,y})==0) break;
			x--;
			y++;
		}
		ma=max(ma,y-x-1);
	}
	cout<<ma<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
