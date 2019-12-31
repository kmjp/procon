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

int T,W,H,L;
char fl[100];
int field[12][12][12];
int SX,SY,SZ,GX,GY,GZ;
int SDX[12],SDY[12],SUX[12],SUY[12];
ll cost[12][12][12][101];
ll dcost[101];

void solve() {
	int f,i,j,k,l,x,y,z;
	cin>>T>>W>>H>>L;
	L=min(L,100);
	
	gets(fl); /* skip first line*/
	FOR(z,T) {
		FOR(y,H) {
			gets(fl);
			FOR(x,W) {
				if(fl[x*2]=='K') SX=x, SY=y,SZ=z;
				if(fl[x*2]=='$') GX=x, GY=y, GZ=z;
				if(fl[x*2]=='-') SDX[z]=x, SDY[z]=y;
				if(fl[x*2]=='_') SUX[z]=x, SUY[z]=y;
				if(fl[x*2]==' ' || fl[x*2]=='#') field[z][y][x]=1000;
				if(fl[x*2]>='0' && fl[x*2]<='9') field[z][y][x]=(fl[x*2]-'0')*10+fl[x*2+1]-'0';
				if(fl[x*2]=='H') field[z][y][x]=100;
				FOR(j,101) cost[z][y][x][j]=1LL<<40;
			}
		}
	}
	cost[SZ][SY][SX][L]=0;
	
	set<pair<ll,int> > S;
	S.insert(make_pair(0,L*1000+SZ*100+SY*10+SX));
	
	while(!S.empty()) {
		pair<ll,int> key = *S.begin();
		S.erase(S.begin());
		ll co=key.first;
		int cz=(key.second/100)%10,cy=(key.second/10)%10,cx=key.second%10;
		j=key.second/1000;
		//_P("%d %d %d %d %lld\n",cz,cy,cx,j,co);
		FOR(f,4) {
			int dx[4]={1,-1,0,0},dy[4]={0,0,1,-1};
			int ty=cy+dy[f],tx=cx+dx[f];
			if(ty<0 || ty>=H || tx<0 || tx>=W) continue;
			if(field[cz][ty][tx]>j) continue;
			if(field[cz][ty][tx]==j && j<=99) {
				// same level emeny
				if(cost[cz][ty][tx][j+1] > co+j+1) {
					if(cost[cz][ty][tx][j+1]<1LL<<40) S.erase(make_pair(cost[cz][ty][tx][j+1],(j+1)*1000+cz*100+ty*10+tx));
					cost[cz][ty][tx][j+1] = co+j+1;
					S.insert(make_pair(cost[cz][ty][tx][j+1],(j+1)*1000+cz*100+ty*10+tx));
				}
			}
			else if(cost[cz][ty][tx][j] > co+field[cz][ty][tx]+1) {
				if(cost[cz][ty][tx][j]<1LL<<40) S.erase(make_pair(cost[cz][ty][tx][j],j*1000+cz*100+ty*10+tx));
				cost[cz][ty][tx][j] = co+field[cz][ty][tx]+1;
				S.insert(make_pair(cost[cz][ty][tx][j],j*1000+cz*100+ty*10+tx));
				
				// downstair
				if(ty==SDY[cz] && tx==SDX[cz] && cz>SZ && cost[cz-1][SUY[cz-1]][SUX[cz-1]][j]>cost[cz][ty][tx][j]+1) {
					if(cost[cz-1][SUY[cz-1]][SUX[cz-1]][j]<1LL<<40)
						S.erase(make_pair(cost[cz-1][SUY[cz-1]][SUX[cz-1]][j],j*1000+(cz-1)*100+SUY[cz-1]*10+SUX[cz-1]));
					cost[cz-1][SUY[cz-1]][SUX[cz-1]][j] = cost[cz][ty][tx][j]+1;
					S.insert(make_pair(cost[cz-1][SUY[cz-1]][SUX[cz-1]][j],j*1000+(cz-1)*100+SUY[cz-1]*10+SUX[cz-1]));
				}
				// upstair
				if(ty==SUY[cz] && tx==SUX[cz] && cost[cz+1][SDY[cz+1]][SDX[cz+1]][j]>cost[cz][ty][tx][j]+1) {
					if(cost[cz+1][SDY[cz+1]][SDX[cz+1]][j]<1LL<<40)
						S.erase(make_pair(cost[cz+1][SDY[cz+1]][SDX[cz+1]][j],j*1000+(cz+1)*100+SDY[cz+1]*10+SDX[cz+1]));
					cost[cz+1][SDY[cz+1]][SDX[cz+1]][j] = cost[cz][ty][tx][j]+1;
					S.insert(make_pair(cost[cz+1][SDY[cz+1]][SDX[cz+1]][j],j*1000+(cz+1)*100+SDY[cz+1]*10+SDX[cz+1]));
				}
			}
		}
	}
	
	ll mi=1LL<<40;
	FOR(j,101) mi=min(mi,cost[GZ][GY][GX][j]);
	if(mi>=1LL<<40) cout << "Impossible" << endl;
	else cout << mi << endl;
}


int main(int argc,char** argv){
	if(argc>1) freopen(argv[1], "r", stdin);
	solve();
	return 0;
}


