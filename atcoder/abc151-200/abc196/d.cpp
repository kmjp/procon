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

int H,W,A,B;

int did[16][16];
int ret=0;

void dfs(int y,int x,int A,int B) {
	if(A<0||B<0) return;
	if(x==W) {
		dfs(y+1,0,A,B);
		return;
	}
	if(y==H) {
		ret++;
		return;
	}
	
	if(did[y][x]) {
		dfs(y,x+1,A,B);
	}
	else {
		if(B) {
			did[y][x]=1;
			dfs(y,x+1,A,B-1);
			did[y][x]=0;
		}
		if(A) {
			if(x+1<W&&did[y][x+1]==0) {
				did[y][x]=did[y][x+1]=1;
				dfs(y,x+2,A-1,B);
				did[y][x]=did[y][x+1]=0;
			}
			if(y+1<H&&did[y+1][x]==0) {
				did[y][x]=did[y+1][x]=1;
				dfs(y,x+1,A-1,B);
				did[y][x]=did[y+1][x]=0;
			}
		}
	}
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W>>A>>B;
	
	dfs(0,0,A,B);
	
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
