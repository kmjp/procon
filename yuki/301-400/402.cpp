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
string S[3030];
int D[3030][3030];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	
	FOR(y,H) cin>>S[y+1], S[y+1]='.'+S[y+1]+'.';
	
	FOR(x,W+2) S[0]+='.', S[H+1]+='.';
	H+=2;
	W+=2;
	
	FOR(y,H) FOR(x,W) D[y][x]=3030;
	queue<int> Q;
	FOR(y,H) FOR(x,W) if(S[y][x]=='.') D[y][x]=0, Q.push(y*10000+x);
	
	int ma=0;
	while(Q.size()) {
		k=Q.front();
		Q.pop();
		int cy=k/10000,cx=k%10000;
		FOR(i,9) {
			int ty=cy+(i/3-1);
			int tx=cx+(i%3-1);
			if(tx<0 || tx>=W || ty<0||ty>=H || D[ty][tx]<=D[cy][cx]+1) continue;
			ma=D[ty][tx]=D[cy][cx]+1;
			Q.push(ty*10000+tx);
		}
	}
	
	cout<<ma<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
