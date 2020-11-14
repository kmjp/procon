#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

vector<int> ok[1<<6][1<<6];

ll from[1<<6][1<<6];
ll to[1<<6][1<<6];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	int m1,m2,m3;
	FOR(m1,1<<6) FOR(m2,1<<6) FOR(m3,1<<6) {
		int c=1;
		FOR(y,6) {
			x=0;
			x+=(m1>>y)&1;
			x+=(m3>>y)&1;
			x+=(m2>>y)&1;
			x+=(m2>>(y+1))&1;
			if(y) x+=(m2>>(y-1))&1;
			if(x>=3&&(m2&(1<<y))==0) c=0;
			if(x<3&&(m2&(1<<y))) c=0;
		}
		if(c) ok[m1][m2].push_back(m3);
	}
	FOR(m1,1<<6) from[0][m1]=1;
	FOR(i,18) {
		ZERO(to);
		cin>>s;
		FOR(m2,1<<6) {
			int c=1;
			FOR(y,6) {
				if(s[y]=='0'&&((m2>>y)&1)) c=0;
				if(s[y]=='1'&&((m2>>y)&1)==0) c=0;
			}
			if(c==0) continue;
			FOR(m1,1<<6) FORR(p,ok[m1][m2]) to[m2][p]+=from[m1][m2];
		}
		swap(from,to);
	}
	ll ret=0;
	FOR(m1,1<<6) ret+=from[m1][0];
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
