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

int T;
int H,W;
string S;


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>H>>W>>S;
		int LD=H-1,LR=W-1;
		FORR(c,S) {
			if(c=='R') LR--;
			if(c=='D') LD--;
		}
		string A[2]={S,S};
		FOR(i,2) {
			x=LR,y=LD;
			FORR(c,A[i]) if(c=='?') {
				if(i==0) {
					if(x) c='R', x--;
					else c='D', y--;
				}
				else {
					if(y) c='D', y--;
					else c='R', x--;
				}
			}
		}
		ll ret=1;
		int x1,y1,x2,y2;
		x1=y1=x2=y2=0;
		FOR(i,A[0].size()) {
			if(A[0][i]=='R') x1++;
			else y1++;
			if(A[1][i]=='R') x2++;
			else y2++;
			ret+=abs(y1-y2)+1;
		}
		cout<<ret<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
