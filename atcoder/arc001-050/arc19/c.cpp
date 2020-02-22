#include <cstdlib>
#include <cstring>
#include <memory>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)

#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ZERO(a) memset(a,0,sizeof(a))
void _fill_int(int* p,int val,int rep) {int i;	FOR(i,rep) p[i]=val;}
#define FILL_INT(a,val) _fill_int((int*)a,val,sizeof(a)/4)
#define MINUS(a) _fill_int((int*)a,-1,sizeof(a)/4)
ll GETi() { ll i;scanf("%lld",&i); return i;}
//-------------------------------------------------------

int R,C,K;
string S[101];
int sx,sy,cx,cy,gx,gy;

int cost[3][101][101][101];

void solve() {
	int f,i,j,k,l,x,y,z;
	
	cin>>R>>C>>K;
	FOR(y,R) {
		cin>>S[y];
		FOR(x,C) {
			if(S[y][x]=='S') sx=x,sy=y,S[y][x]='.';
			if(S[y][x]=='C') cx=x,cy=y,S[y][x]='.';
			if(S[y][x]=='G') gx=x,gy=y,S[y][x]='.';
		}
	}
	
	set<pair<int,int> > SE;
	
	FOR(i,3) FOR(y,100) FOR(x,100) FOR(z,101) cost[i][y][x][z]=1<<25;
	cost[0][sy][sx][0]=cost[1][cy][cx][0]=cost[2][gy][gx][0]=0;
	SE.insert(make_pair(0,0*10000000+0*10000+sy*100+sx));
	SE.insert(make_pair(0,1*10000000+0*10000+cy*100+cx));
	SE.insert(make_pair(0,2*10000000+0*10000+gy*100+gx));
	
	while(!SE.empty()) {
		pair<int,int> k=*SE.begin();
		SE.erase(SE.begin());
		int type=k.second/10000000;
		int ccy=k.second/100%100,ccx=k.second%100,lk=k.second/10000%1000;
		if(k.first!=cost[type][ccy][ccx][lk]) continue;
		
		FOR(i,4) {
			int dx[]={1,-1,0,0};
			int dy[]={0,0,1,-1};
			int ty=ccy+dy[i],tx=ccx+dx[i];
			if(tx<0 || tx>=C || ty<0 || ty>=R) continue;
			if(S[ty][tx]=='T') continue;
			if(S[ty][tx]=='E'){
				if(lk<K && cost[type][ty][tx][lk+1]>cost[type][ccy][ccx][lk]+1) {
					cost[type][ty][tx][lk+1]=cost[type][ccy][ccx][lk]+1;
					SE.insert(make_pair(cost[type][ty][tx][lk+1],type*10000000+ty*100+tx+(lk+1)*10000));
				}
			}
			else {
				if(cost[type][ty][tx][lk]>cost[type][ccy][ccx][lk]+1) {
					cost[type][ty][tx][lk]=cost[type][ccy][ccx][lk]+1;
					SE.insert(make_pair(cost[type][ty][tx][lk],type*10000000+ty*100+tx+lk*10000));
				}
			}
		}
	}
	
	int ret=1<<30;
	FOR(y,R) FOR(x,C) {
		if(S[y][x]=='T') continue;
		FOR(i,3) FOR(z,K) cost[i][y][x][z+1]=min(cost[i][y][x][z],cost[i][y][x][z+1]);
		if(S[y][x]=='E') {
			FOR(i,K+1) for(j=0;j<=K-i;j++) {
				if(cost[0][y][x][i]+cost[1][y][x][j+1]+cost[2][y][x][K-i-j+1]<1<<25) 
				ret=min(ret,cost[0][y][x][i]+cost[1][y][x][j+1]*2+cost[2][y][x][K-i-j+1]);
			}
		}
		else {
			FOR(i,K+1) for(j=0;j<=K-i;j++) {
				if(cost[0][y][x][i]+cost[1][y][x][j]+cost[2][y][x][K-i-j]<1<<25) 
				ret=min(ret,cost[0][y][x][i]+cost[1][y][x][j]*2+cost[2][y][x][K-i-j]);
			}
		}
		
	}
	
	if(ret>=1<<25) _P("-1\n");
	else cout << ret << endl;
	
}


int main(int argc,char** argv){
	string s;
	if(argc==1) ios::sync_with_stdio(false);
	for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
	for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
	solve();
	return 0;
}


