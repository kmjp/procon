#include <cstdlib>
#include <cstring>
#include <memory>
#include <cstdio>
#include <iostream>
#include <cmath>
#include <string>
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
#define MINUS(a) _fill_int((int*)a,-1,sizeof(a)/4)
//-------------------------------------------------------

int N;
int isis[1002][1002];
int dist[1002][1002];
int X[1001],Y[1001];

void solve() {
	int f,i,j,k,l,x,y;
	cin>>N;
	FOR(i,N) cin>>X[i]>>Y[i];
	
	FOR(i,2) {
		vector<pair<int,int> > VV;
		ZERO(isis);
		if(i==0) FOR(j,N) isis[X[j]-1][Y[j]-1]=1;
		if(i==1) FOR(j,N) isis[Y[j]-1][X[j]-1]=1;
		
		MINUS(dist);
		FOR(x,1000) {
			FOR(y,1000) {
				if(isis[x][y]) dist[x][y]=0;
				else if(x==0) dist[x][y]=-1;
				else if(dist[x-1][y]==-1) dist[x][y]=-1;
				else dist[x][y]=dist[x-1][y]+1;
			}
			if(count(isis[x],isis[x]+1001,0)==1001) {
				memmove(isis[x],isis[x-1],sizeof(isis[x]));
				continue;
			}
			int pred=1005;
			FOR(y,1000) {
				if(isis[x][y]) pred=1005;
				else {
					if(dist[x][y]!=-1 && dist[x][y]<pred) {
						pred=dist[x][y];
						isis[x][y]=1;
						VV.push_back(make_pair(x,y));
					}
				}
			}
			pred=1005;
			for(y=999;y>=0;y--) {
				if(isis[x][y]) pred=1005;
				else {
					if(dist[x][y]!=-1 && dist[x][y]<pred) {
						pred=dist[x][y];
						isis[x][y]=1;
						VV.push_back(make_pair(x,y));
					}
				}
			}
		}
		if(VV.size()+N<=10000) {
			_P("%d\n",VV.size());
			if(i==0) ITR(it,VV) _P("%d %d\n",it->first+1,it->second+1);
			if(i==1) ITR(it,VV) _P("%d %d\n",it->second+1,it->first+1);
			return;
		}
	}
	
	
}


int main(int argc,char** argv){
	string s;
	if(argc==1) ios::sync_with_stdio(false);
	for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
	for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
	solve();
	return 0;
}


