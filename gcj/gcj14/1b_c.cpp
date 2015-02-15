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
#include <sys/time.h>
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

int N,M;
int Z[101];
ll mat[101];
vector<int> R,st;

ll reach(int cur, ll mask) {
	int i;
	queue<int> Q;
	Q.push(cur);
	while(!Q.empty()) {
		cur=Q.front();
		Q.pop();
		FOR(i,N) if((mat[cur]&(1LL<<i)) && ((mask&(1LL<<i))==0)) {
			mask |= 1LL<<i;
			Q.push(i);
		}
	}
	return mask;
}

ll dfs(int cur, ll mask) {
	int i;
	R.push_back(cur);
	mask |= 1LL<<cur;
	
	st.push_back(cur);
	
	int tar;
	retry:
	FOR(tar,N) if((mask & (1LL<<tar))==0) {
		if(mat[cur]&(1LL<<tar)) {
			mask=dfs(tar,mask);
			goto retry;
		}
		ll nm=mask;
		FOR(i,st.size()-1) {
			nm |= reach(st[i],mask);
			if((nm+1==(1LL<<N)) && (mat[st[i]]&(1LL<<tar))) goto out;
		}
	}
	out:
	st.pop_back();
	return mask;
}

void solve(int _loop) {
	int f,i,j,k,l,x,y,z;
	
	map<int,int> C;
	cin>>N>>M;
	FOR(i,N) {
		cin>>Z[i];
		C[Z[i]]=i;
	}
	i=0;
	int conv[51];
	ITR(it,C) Z[i]=it->first, conv[it->second]=i++;
	
	
	ZERO(mat);
	FOR(i,M) {
		cin>>x>>y;
		x=conv[x-1];
		y=conv[y-1];
		mat[x] |= 1LL<<y;
		mat[y] |= 1LL<<x;
	}
	
	R.clear();
	st.clear();
	dfs(0,0);
	
	_P("Case #%d: ",_loop);
	FOR(i,N) _P("%d",Z[R[i]]);
	_P("\n");
	
}

void init() {
}

int main(int argc,char** argv){
	int loop,loops;
	long long span;
	char tmpline[1000];
	struct timeval start,end,ts;
	
	if(argc>1) freopen(argv[1], "r", stdin);
	gettimeofday(&ts,NULL);
	cin>>loops;
	init();
	
	for(loop=1;loop<=loops;loop++) {
		gettimeofday(&start,NULL); solve(loop); gettimeofday(&end,NULL);
		span = (end.tv_sec - start.tv_sec)*1000000LL + (end.tv_usec - start.tv_usec);
		fprintf(stderr,"Case : %d                                     time: %lld ms\n",loop,span/1000);
	}
	
	start = ts;
	span = (end.tv_sec - start.tv_sec)*1000000LL + (end.tv_usec - start.tv_usec);
	fprintf(stderr,"**Total time: %lld ms\n",span/1000);
	
	return 0;
}


