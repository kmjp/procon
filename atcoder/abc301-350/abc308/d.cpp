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

int H,W;
string S[555];
int ok[555][555];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	FOR(y,H) {
		cin>>S[y];
		FORR(c,S[y]) {
			if(c=='s') c=0;
			else if(c=='n') c=1;
			else if(c=='u') c=2;
			else if(c=='k') c=3;
			else if(c=='e') c=4;
			else c=10;
		}
	}
	queue<int> Q;
	if(S[0][0]==0) {
		ok[0][0]=1;
		Q.push(0);
	}
	while(Q.size()) {
		int cy=Q.front()/1000;
		int cx=Q.front()%1000;
		Q.pop();
		int d[4]={1,0,-1,0};
		FOR(i,4) {
			int ty=cy+d[i];
			int tx=cx+d[i^1];
			if(ty<0||ty>=H||tx<0||tx>=W) continue;
			if(ok[ty][tx]) continue;
			if((S[cy][cx]+1)%5!=S[ty][tx]) continue;
			ok[ty][tx]=1;
			Q.push(ty*1000+tx);
		}
		
	}
	if(ok[H-1][W-1]) {
		cout<<"Yes"<<endl;
	}
	else {
		cout<<"No"<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
