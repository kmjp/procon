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

int N,M,K;
pair<int,int> P[100010];

int okok(int dist) {
	int kk=K;
	int day=0,s=0,ma=0;
	
	priority_queue<int,vector<int>,greater<int> > Q;
	
	while(day+dist<M+1) {
		while(s<N && day+dist>=P[s].first) {
			Q.push(P[s].second);
			ma=max(ma,P[s].second);
			s++;
		}
		
		if(Q.empty()) {
			if(kk<=0 || day>=ma) return 0;
			kk--;
			day = ma;
		}
		else {
			if(Q.top()>day) day = min(day+dist, Q.top());
			Q.pop();
		}
	}
	return 1;
}


void solve() {
	int f,i,j,k,l,x,y;
	
	cin>>N>>M>>K;
	FOR(i,N) cin>>P[i].first>>P[i].second;
	sort(P,P+N);
	int L=1,R=M;
	while(L<R) {
		int po=(L+R)/2;
		if(okok(po)) R=po;
		else L=po+1;
	}
	while(okok(R-1)) R--;
	while(!okok(R)) R++;
	
	_P("%d\n",R);
}


int main(int argc,char** argv){
	string s;
	if(argc==1) ios::sync_with_stdio(false);
	for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
	for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
	solve();
	return 0;
}


