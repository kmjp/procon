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

void solve() {
	int f,i,j,k,l,x,y,xx;
	int N,T;
	string SS[11];
	
	cin>>T;
	FOR(xx,T) {
		cin>>N;
		FOR(i,N) cin>>SS[i];
		x=0;
		FOR(j,1000) {
			
			for(y=1;y<N;y++) if(SS[(x+y)%N].size()) break;
			char aa=SS[(x+y)%N][0];
			SS[(x+y)%N]=SS[(x+y)%N].substr(1);
			
			FOR(f,SS[x].size()) {
				if(SS[x][f]==aa) {
					SS[x] = SS[x].substr(0,f)+SS[x].substr(f+1);
					goto ne;
				}
			}
			SS[x]+=aa;
			ne:
			k=0;
			FOR(i,N) k+=SS[i].size();
			if(k==1) break;
			
			x=(x+1)%N;
			while(SS[x].empty()) x=(x+1)%N;
			
		}
		j++;
		_P("%d\n",(j>=1000)?-1:j);
	}
}


int main(int argc,char** argv){
	string s;
	for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
	for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
	solve();
	return 0;
}


