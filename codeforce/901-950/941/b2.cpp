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
		int LW=W,RW=-1,UW=H,DW=-1;
		int LB=W,RB=-1,UB=H,DB=-1;
		FOR(y,H) {
			cin>>S[y];
			FOR(x,W) {
				if(S[y][x]=='W') {
					LW=min(LW,x);
					RW=max(RW,x);
					UW=min(UW,y);
					DW=max(DW,y);
				}
				else {
					LB=min(LB,x);
					RB=max(RB,x);
					UB=min(UB,y);
					DB=max(DB,y);
				}
			}
		}
		if(LW==0&&RW==W-1&&UW==0&&DW==H-1) {
			cout<<"YES"<<endl;
		}
		else if(LB==0&&RB==W-1&&UB==0&&DB==H-1) {
			cout<<"YES"<<endl;
		}
		else {
			cout<<"NO"<<endl;
		}

	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
