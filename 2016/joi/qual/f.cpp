#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int H,W;
string S[1010];

int memo[1010][1010][16];
int dy[4]={-1,0,0,1};
int dx[4]={0,-1,1,0};

// *01
// 234
// 56*

int dfs(int y,int x,int mask) {
	int add=0;
	if((mask&(1<<3))==0) add+=S[y][x];
	mask |= 1<<3;
	int memomask=(mask&7) | ((mask&32)>>2);
	
	if(memo[y][x][memomask]<0) {
		int ret=10101010;
		
		int i,j;
		FOR(i,4) {
			int nmask=mask;
			int tadd=0;
			FOR(j,4) if(i!=j) {
				int ty=y+dy[j];
				int tx=x+dx[j];
				if(tx<0 || tx>=W || ty<0||ty>=H) continue;
				if((nmask & (1<<(2*j)))==0) {
					tadd+=S[ty][tx];
					nmask |= 1<<(2*j);
				}
			}
			
			if(y<H-1) ret=min(ret,tadd+dfs(y+1,x,nmask>>3));
			if(x<W-1) ret=min(ret,tadd+dfs(y,x+1,(nmask&(0x5A))>>1));
			if(y==H-1 && x==W-1) ret=min(ret,tadd);
		}
		
		memo[y][x][memomask]=ret;
	}
	return add+memo[y][x][memomask];
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	FOR(y,H) {
		cin>>S[y];
		FORR(c,S[y]) {
			if(c=='.') c=0;
			else c=c-'0';
		}
	}
	MINUS(memo);
	cout<<dfs(0,0,0)<<endl;
	/*
	FOR(y,H) {
		FOR(x,W) {
			cout<<y<<" "<<x<<" "<<memo[y][x].size()<<endl;
			FORR(e,memo[y][x]) {
				cout<<"    ";
				FORR(e2,e.first) cout<<e2.first<<","<<e2.second<<"  ";
				cout<<endl;
			}
		}
	}
	*/
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
