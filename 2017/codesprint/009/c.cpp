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

int N,K;
int X,Y;
set<pair<int,int>> S;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	cin>>X>>Y;
	FOR(i,K) {
		cin>>x>>y;
		S.insert({x,y});
	}
	
	int dx[]={1,-1,0,0,1,1,-1,-1};
	int dy[]={0,0,1,-1,1,-1,1,-1};
	int tot=0;
	FOR(i,8) {
		x=X;
		y=Y;
		while(1) {
			x+=dx[i];
			y+=dy[i];
			if(x<=0||x>N||y<=0||y>N) break;
			if(S.count({x,y})) break;
			tot++;
		}
	}
	cout<<tot<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
