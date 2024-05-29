#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------

int T,H,W;
string S[555];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>H>>W;
		FOR(y,H) cin>>S[y];
		
		FOR(y,H) {
			int pre=-1;
			FOR(x,W) if(S[y][x]=='U') {
				if(pre==-1) pre=x;
				else {
					S[y][x]=S[y+1][pre]='B';
					S[y][pre]=S[y+1][x]='W';
					pre=-1;
				}
			}
		}
		FOR(x,W) {
			int pre=-1;
			FOR(y,H) if(S[y][x]=='L') {
				if(pre==-1) pre=y;
				else {
					S[y][x]=S[pre][x+1]='B';
					S[pre][x]=S[y][x+1]='W';
					pre=-1;
				}
			}
		}
		int ng=0;
		FOR(y,H) FOR(x,W) {
			if(S[y][x]=='L') ng++;
			if(S[y][x]=='R') ng++;
			if(S[y][x]=='D') ng++;
			if(S[y][x]=='U') ng++;
		}
		if(ng) {
			cout<<-1<<endl;
		}
		else {
			FOR(y,H) cout<<S[y]<<endl;
		}
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
