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

int H,W,X;

string S[1010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W>>X;
	X-=(H-1)+(W-1);
	if(X%2) return _P("-1\n");
	if(X<0||X%4) return _P("-1\n");
	X/=4;
	
	if(W%4==1) {
		FOR(y,H) {
			S[y]=string(W,'#');
			FOR(x,W) if(y==0||x%2==0) S[y][x]='.';
		}
		for(x=1;x<W;x+=4) {
			for(y=0;y<H-1;y+=2) if(X) {
				X--;
				S[y][x]='#';
				S[y+2][x]='.';
			}
		}
	}
	else if(H%4==1) {
		FOR(y,H) {
			S[y]=string(W,'#');
			FOR(x,W) if(y%2==0||x==0) S[y][x]='.';
		}
		for(y=1;y<W;y+=4) {
			for(x=0;x<W-1;x+=2) if(X) {
				X--;
				S[y][x]='#';
				S[y][x+2]='.';
			}
		}
	}
	else {
		FOR(y,H) {
			S[y]=string(W,'#');
			FOR(x,W) if(y==0||x==W-1||(x>=W-3&&y%2==0)||(x<W-3&&x%2==0)) S[y][x]='.';
		}
		for(x=1;x<W-3;x+=4) {
			for(y=0;y<H-1;y+=2) if(X) {
				X--;
				S[y][x]='#';
				S[y+2][x]='.';
			}
		}
		for(y=3;y<H;y+=4) if(X) {
			X--;
			S[y][W-1]='#';
			S[y][W-3]='.';
		}
	}
	
	if(X) return _P("-1\n");
	FOR(y,H) cout<<S[y]<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
