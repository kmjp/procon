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

int N;
int X,Y;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>X>>Y;
	int cnt[4]={};
	FOR(i,N) {
		cin>>x>>y;
		// up up
		if(min(X,Y)<=x && x<y) cnt[0]++;
		// up down
		if((X<=x && x<y)||(x<=Y&&y<x)) cnt[1]++;
		// down up
		if((Y<=x && x<y)||(x<=X&&y<x)) cnt[2]++;
		// down down
		if(x<=max(X,Y) && y<x) cnt[3]++;
	}
	cout<<max({cnt[0],cnt[1],cnt[2],cnt[3]})<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
