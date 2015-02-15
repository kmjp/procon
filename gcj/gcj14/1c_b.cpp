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

int N;
string S[101],TS;
char C[101][2];

int tar[26];
ll mo=1000000007;
int ishead[26];
ll kai[505];
int same[26];

ll dfs(int cur) {
	if(cur==-1) return 1;
	return dfs(tar[cur])*kai[same[cur]]%mo;
}

int isloop(int cur,int dst) {
	if(tar[cur]==-1) return 0;
	if(tar[cur]==dst) return 1;
	return isloop(tar[cur],dst);
}

void solve(int _loop) {
	int f,i,j,k,l,x,y;
	kai[0]=1;
	FOR(i,500) kai[i+1]=kai[i]*(i+1)%mo;
	MINUS(tar);
	ZERO(same);
	
	cin>>N;
	
	
	FOR(i,N) cin>>S[i];
	FOR(i,N) {
		string s2;
		s2+=S[i][0];
		for(x=1;x<S[i].size();x++) if(S[i][x-1]!=S[i][x]) s2+=S[i][x];
		for(x=1;x<s2.size()-1;x++) {
			FOR(y,N) if(i!=y && count(S[y].begin(),S[y].end(),s2[x])>0) return _P("Case #%d: 0\n",_loop);
		}
		FOR(x,s2.size()) FOR(y,s2.size()) if(x!=y && s2[x]==s2[y]) return _P("Case #%d: 0\n",_loop);
		
		if(s2[0]==s2[s2.size()-1]) {
			same[s2[0]-'a']++;
		}
		else {
			if(tar[s2[0]-'a']>=0) return _P("Case #%d: 0\n",_loop);
			tar[s2[0]-'a']=s2[s2.size()-1]-'a';
		}
	}
	
	ZERO(ishead);
	FOR(i,26) ishead[i]=1;
	FOR(i,26) if(tar[i]>=0) ishead[tar[i]]=0;
	FOR(i,26) if(ishead[tar[i]]==0 && isloop(i,i)) return _P("Case #%d: 0\n",_loop);
	FOR(i,26) if(tar[i]==-1 && same[i]==0) ishead[i]=-1;
	
	int num=0;
	ll ret=1;
	FOR(i,26) if(ishead[i]==1) num++, ret=ret*dfs(i)%mo;
	ret *= kai[num];
	
	_P("Case #%d: %lld\n",_loop,ret%mo);
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


