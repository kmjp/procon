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

int H,W,K;
string S[202];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W>>K;
	FOR(y,H*2+2) S[y]=string(W*2+2,' ');
	
	FOR(y,H+1) {
		FOR(x,2*W+1) S[y*2][x]='+';
	}
	FOR(x,W+1) {
		FOR(y,2*H+1) S[y][x*2]='+';
	}
	FOR(y,H-1) FOR(x,W) S[y*2+2][x*2+1]='-';
	FOR(x,W-1) FOR(y,H) S[y*2+1][x*2+2]='|';
	
	FOR(y,H) FOR(x,W) S[y*2+1][x*2+1]='o';
	
	K-=H;
	if(K<0||K%2) {
		cout<<"No"<<endl;
		return;
	}
	
	for(y=0;y+2<=H;y+=2) {
		int mi=min(K/2,W-1);
		K-=mi*2;
		FOR(i,mi) S[y*2+1][(W-1-i)*2]=S[y*2+3][(W-1-i)*2]='.';
		S[y*2+2][(W-mi)*2-1]='.';
		S[y*2+4][W*2-1]='.';
	}
	
	if(H%2&&H>1&&K) {
		for(x=0;x+2<=W;x+=2) if(K) {
			K-=2;
			S[(H-1)*2-1][x*2+2]='|';
			S[(H-1)*2+1][x*2+2]='.';
			S[(H-1)*2][x*2+1]='.';
			S[(H-1)*2][x*2+3]='.';
		}
	}
	
	
	S[0][2*W-1]='S';
	S[2*H][2*W-1]='G';
	if(K) {
		cout<<"No"<<endl;
	}
	else {
		cout<<"Yes"<<endl;
		FOR(y,2*H+1) cout<<S[y]<<endl;
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
