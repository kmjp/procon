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


int H,W,N;
string T[12];
int ok[20][20];
vector<int> C[16];
string S[4][3]= {
	{".0..",
	 ".12.",
	 ".3.."},
	{".310",
	 "..2.",
	 "...."},
	{".3..",
	 "21..",
	 ".0.."},
	{".2..",
	 "013.",
	 "...."},
};
int X[5050],Y[5050],R[5050];
int num;
void dfs(int y,int x) {
	while(ok[y+4][x+4]==0) {
		x++;
		if(x==W) {
			x=0;
			y++;
			if(y==H) {
				int i;
				FOR(i,N) cout<<X[i]<<" "<<Y[i]<<" "<<R[i]<<endl;
				exit(0);
			}
		}
	}
	
	int i;
	int dy,dx;
	int ty,tx;
	FOR(i,4) {
		int ng=0;
		int mask=0;
		FOR(dy,3) FOR(dx,4) if(S[i][dy][dx]!='.') {
			if(ok[y+dy+4][x+dx+3]==0) ng=1;
			if(ok[y+dy+4][x+dx+3]==1 && T[y+dy][x+dx-1]=='#') mask|=1<<(S[i][dy][dx]-'0');
			if(S[i][dy][dx]=='0') ty=y+dy,tx=x+dx-1;
		}
		if(ng==0 && C[mask].size()){
			int tar=C[mask].back();
			C[mask].pop_back();
			X[tar]=tx+1;
			Y[tar]=ty+1;
			R[tar]=i;
			FOR(dy,3) FOR(dx,4) if(S[i][dy][dx]!='.') ok[y+dy+4][x+dx+3]=0;
			dfs(y,x);
			FOR(dy,3) FOR(dx,4) if(S[i][dy][dx]!='.') ok[y+dy+4][x+dx+3]=1;
			C[mask].push_back(tar);
		}
	}
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	FOR(y,H) cin>>T[y];
	cin>>N;
	FOR(i,N) {
		cin>>x;
		C[x-1].push_back(i);
	}
	FOR(y,H) FOR(x,W) ok[y+4][x+4]=1;
	dfs(0,0);
	cout<<-1<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
