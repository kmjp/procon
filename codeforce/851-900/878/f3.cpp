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

int te;
int H,W,R;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>te;
	while(te--) {
		cin>>H>>W>>R;
		int ok[H+1][W+1][R+1]={};
		int ng[H+1][W+1][R+1]={};
		FOR(i,R) {
			int T,D,C;
			cin>>T>>D>>C;
			if(D==1) {
				FOR(x,W+1) {
					int t=T-C-x;
					if(t>=0&&t<=R) ng[C][x][t]=1;
				}
			}
			else {
				FOR(y,H+1) {
					int t=T-C-y;
					if(t>=0&&t<=R) ng[y][C][t]=1;
				}
			}
		}
		ok[0][0][0]=1;
		FOR(y,H+1) FOR(x,W+1) FOR(r,R+1) if(ng[y][x][r]==0) {
			if(y) ok[y][x][r]|=ok[y-1][x][r];
			if(x) ok[y][x][r]|=ok[y][x-1][r];
			if(r) ok[y][x][r]|=ok[y][x][r-1];
			
		}
		
		int ret=-1;
		for(r=R;r>=0;r--) if(ok[H][W][r]) ret=H+W+r;
		cout<<ret<<endl;
		
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
