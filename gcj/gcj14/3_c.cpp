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


void solve(int _loop) {
	int f,i,j,k,l,x,y,s,t;
	
	int N;
	pair<char,int> Q[1001];
	int S[3005]; // 0-out 1-in
	vector<int> E[3005];
	int pos[3005];
	int NE=0, NL=0;
	
	_P("Case #%d: ",_loop);
	cin>>N;
	FOR(i,N) {
		cin>>Q[i].first>>Q[i].second;
		if(Q[i].first=='E') NE++;
		else NL++;
		if(Q[i].second>0) E[Q[i].second].push_back(i);
	}
	
	FOR(s,N+1) {
		t=s+NE-NL;
		if(t<0) continue;
		
		set<pair<int,int> > TBE,TBL;
		ZERO(S);
		ZERO(pos);
		FOR(i,3005) if(!E[i].empty()) {
			if(Q[E[i][0]].first=='L') TBL.insert(make_pair(E[i][0],i));
		}
		
		int nid=2001;
		FOR(i,s) {
			if(TBL.empty()) S[nid++]=1;
			else {
				pair<int,int> p=*TBL.begin();
				TBL.erase(TBL.begin());
				x=p.second;
				S[x]=1;
				if(pos[x]<E[p.second].size() && Q[E[x][pos[x]]].first=='E') TBE.insert(make_pair(E[x][pos[x]],x));
			}
		}
		int ng=0;
		FOR(i,N) {
			x=Q[i].second;
			if(x==0) {
				if(Q[i].first=='E') {
					if(TBL.empty()) {
						S[nid++]=1;
						continue;
					}
					pair<int,int> p=*TBL.begin();
					TBL.erase(TBL.begin());
					x=p.second;
				}
				else {
					if(TBE.empty()) {
						FOR(y,3005) if(S[y]==1 && pos[y]==E[y].size()) break;
						if(y!=3005) {
							S[y]=0;
							continue;
						}
						FOR(y,3005) {
							if(S[y]==1 && pos[y]<E[y].size() && Q[E[y][pos[y]]].first=='L') {
								if(x==0 || E[y][pos[y]] > E[x][pos[x]]) x=y;
							}
						}
						if(x==0) {
							ng=1;
							break;
						}
					}
					else {
						pair<int,int> p=*TBE.begin();
						TBE.erase(TBE.begin());
						x=p.second;
					}
				}
			}
			
			if(Q[i].first=='E') ng=S[x]==1, S[x]=1;
			else ng=S[x]==0, S[x]=0;
			if(ng) break;
				
			while(pos[x]<E[x].size() && E[x][pos[x]]<=i) pos[x]++;
			if(pos[x]<E[x].size()) {
				if(S[x]==0 && Q[E[x][pos[x]]].first=='L') TBL.insert(make_pair(E[x][pos[x]],x));
				if(S[x]==1 && Q[E[x][pos[x]]].first=='E') TBE.insert(make_pair(E[x][pos[x]],x));
			}
			if(ng) break;
		}
		if(ng) continue;
		return _P("%d\n",t);
	}
	_P("CRIME TIME\n");
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


