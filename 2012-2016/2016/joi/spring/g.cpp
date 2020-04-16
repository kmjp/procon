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

#include "dungeon2.h"

int N;
int NE[202];
int to[202][202];
int fe[202][202];

int dir[202][202];
int p3[10];
int step;

int mat[202][202];

int dfs(int f) {
	int c=Color();
	int from=LastRoad();
	if(c>=2) {
		
		Move(from,c);
		return c;
		
	}
	
	
	int cur=N++;
	NE[cur]=NumberOfRoads();
	int i;
	if(from!=-1) {
		dir[cur][from]=0;
		to[cur][from]=f;
	}
	for(i=1;i<=NE[cur];i++) if(i!=from) {
		Move(i,2);
		dir[cur][i]=dfs(cur);
		if(dir[cur][i]>=100) {
			to[cur][i]=dir[cur][i]-100;
			dir[cur][i]=1;
		}
	}
	if(from>=1) Move(from,3);
	return cur+100;
	
}


void dfs2(int cur) {
	int i;
	assert(NE[cur]==NumberOfRoads());
	
	for(i=1;i<=NE[cur];i++) {
		if(dir[cur][i]==1) {
			Move(i,cur/p3[step]%3+1);
			dfs2(to[cur][i]);
		}
		else if(dir[cur][i]==2) {
			Move(i,cur/p3[step]%3+1);
			int c=Color();
			int from=LastRoad();
			Move(from,c);
			to[cur][i] += (c-1)*p3[step];
			fe[cur][i]=from;
		}
	}
	
	if(cur!=0) {
		for(i=1;i<=NE[cur];i++) if(dir[cur][i]==0) {
			Move(i,cur/p3[step]%3+1);
			break;
		}
	}
	return;
}

void Inspect(int R){
	int i;
	
	p3[0]=1;
	FOR(i,8) p3[i+1]=p3[i]*3;
	
	dfs(-1);
	for(step=0;step<=4;step++) {
		dfs2(0);
	}
	int j,k;
	
	FOR(i,N) FOR(j,N) mat[i][j]=(i==j)?0:101010;
	FOR(i,N) for(j=1;j<=NE[i];j++) if(dir[i][j]!=3) mat[i][to[i][j]]=mat[to[i][j]][i]=1;
	FOR(k,N) FOR(i,N) FOR(j,N) mat[i][j]=min(mat[i][j],mat[i][k]+mat[k][j]);
	
	/*
	FOR(i,N) {
		for(j=1;j<=NE[i];j++) cout<<dir[i][j]<<":"<<to[i][j]<<" ";
		cout<<endl;
	}
	
	FOR(i,N) {
		FOR(j,N) cout<<mat[i][j];
		cout<<endl;
	}
	*/
	int cnt[202]={};
	FOR(i,N) FOR(j,i) cnt[mat[i][j]]++;
	for(i=1;i<=R;i++) Answer(i,cnt[i]);
	
}


