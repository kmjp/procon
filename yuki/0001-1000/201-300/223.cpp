#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N,X,Y,Z;
int pat[16][16];
int pat2[16][16];


int get1(int a,int y,int x) {
	int patt[5][4][4]={
		{{1,1,0,0},{0,0,1,1},{1,1,0,0},{0,0,1,1}},
		{{1,0,1,0},{0,1,0,1},{0,1,0,1},{1,0,1,0}},
		{{1,1,0,0},{0,0,1,1},{0,0,1,1},{1,1,0,0}},
		{{1,1,0,0},{1,1,0,0},{1,0,1,0},{0,0,1,1}},
		{{0,1,0,1},{1,1,0,0},{0,0,1,1},{1,0,1,0}},
	};
	if(a<5) return patt[a][y][x];
	if(a<10) return patt[a-5][3-y][3-x];
	if(a<15) return patt[a-10][x][3-y];
	return patt[a-15][3-x][y];
}
int get2(int a,int b,int c,int d,int y,int x) {
	return get1(a,y,x)*8+get1(b,y,x)*4+get1(c,y,x)*2+get1(d,y,x);
}

void magic4(int yy,int xx,int zz) {
	int a,b,c,d;
	int y,x;
	FOR(a,20) FOR(b,20) FOR(c,20) FOR(d,20) {
		if(zz!=get2(a,b,c,d,yy,xx)) continue;
		set<int> S;
		FOR(y,4) FOR(x,4) pat[y][x]=get2(a,b,c,d,y,x), S.insert(pat[y][x]);
		if(S.size()!=16) continue;
		int ng=0;
		FOR(y,4) if(pat[y][0]+pat[y][1]+pat[y][2]+pat[y][3]!=30) ng++;
		FOR(x,4) if(pat[0][x]+pat[1][x]+pat[2][x]+pat[3][x]!=30) ng++;
		if(pat[0][0]+pat[1][1]+pat[2][2]+pat[3][3]!=30) ng++;
		if(pat[0][3]+pat[1][2]+pat[2][1]+pat[3][0]!=30) ng++;
		if(ng==0) return;
	}
	assert(0);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>X>>Y>>Z;
	X--,Y--,Z--;
	
	magic4(Y%4,X%4,Z%16);
	
	int p[4][4]={{0,3,1,2},{3,0,2,1},{1,2,0,3},{2,1,3,0}};
	
	if(N>=8) {
		FOR(y,4) FOR(x,4) pat[y+4][x+4]=pat[y+4][x]=pat[y][x+4]=pat[y][x];
		memmove(pat2,pat,sizeof(pat));
		FOR(i,4) {
			memmove(pat,pat2,sizeof(pat));
			FOR(y,8) FOR(x,8) pat[y][x] += 16*p[i^(y<4)][x/2];
			if(pat[Y%8][X%8]==Z%64) break;
		}
		
		if(N>=16) {
			FOR(y,8) FOR(x,8) pat[y+8][x+8]=pat[y+8][x]=pat[y][x+8]=pat[y][x];
			memmove(pat2,pat,sizeof(pat));
			FOR(i,4) {
				memmove(pat,pat2,sizeof(pat));
				FOR(y,16) FOR(x,16) pat[y][x] += 64*p[i^(y<8)][x/4];
				if(pat[Y][X]==Z) break;
			}
		}
	}
	FOR(y,N) FOR(x,N) _P("%d%c",pat[y][x]+1,(x==N-1)?'\n':' ');
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
