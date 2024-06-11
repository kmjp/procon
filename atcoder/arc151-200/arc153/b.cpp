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

int H,W,Q;
string S[505050];
string T[505050];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	FOR(y,H) {
		cin>>S[y];
		T[y]=S[y];
	}
	int TY=0,TX=0;
	cin>>Q;
	FOR(i,Q) {
		int a,b;
		cin>>a>>b;
		if(TY<a) {
			TY=a-1-TY;
		}
		else {
			TY=H-1-(TY-a);
		}
		if(TX<b) {
			TX=b-1-TX;
		}
		else {
			TX=W-1-(TX-b);
		}
	}
	vector<int> AY,AX;
	if(Q%2==0) {
		FOR(i,H) AY.push_back((TY+i)%H);
		FOR(i,W) AX.push_back((TX+i)%W);
	}
	else {
		FOR(i,H) AY.push_back((TY-i+H)%H);
		FOR(i,W) AX.push_back((TX-i+W)%W);
	}
	FOR(y,H) {
		FOR(x,W) T[AY[y]][AX[x]]=S[y][x];
	}
	FOR(y,H) cout<<T[y]<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
