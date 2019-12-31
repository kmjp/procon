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

int L,F;
unsigned char hoge[1000];
int ng[200][256];
vector<int> cand[128];

int okok(int id,int val,int val2) {
	ITR(it,cand[id%L]) if((hoge[id]^*it)>=val && (hoge[id]^*it)<=val2) return 1;
	return 0;
}


void solve() {
	int f,i,j,k,l,x,y;
	
	FOR(i,F) {
		FOR(y,256) {
			x=y^hoge[i];
			if(x!=0xA && x!=0x20 && (x<'0' || x>'9')) ng[i%L][y]=1;
		}
	}
	FOR(i,L) FOR(x,256) if(ng[i][x]==0) cand[i].push_back(x);
	
	FOR(i,F) if(i>5 && i<F-1 && cand[i%L].size()>1) {
		vector<int> c2;
		ITR(it,cand[i%L]) {
			x = hoge[i] ^ *it;
			int ng=0;
			
			if(x=='0') {
				ng |= !okok(i-1,'1','1');
				ng |= !okok(i+1,' ',' ') && !okok(i+1,0xa,0xa);
			}
			else if(x=='1') {
				ng |= !okok(i-1,' ',' ') && !okok(i-1,0xa,0xa);
				ng |= !okok(i+1,'0','0') && !okok(i+1,' ',' ') && !okok(i+1,0xa,0xa);
			}
			else if(x>='2' && x<='9') {
				ng |= !okok(i-1,' ',' ') && !okok(i-1,0xa,0xa);
				ng |= !okok(i+1,' ',' ') && !okok(i+1,0xa,0xa);
			}
			else if(x==' ' || x==0xa) {
				ng |= !okok(i-1,'0','9');
				ng |= !okok(i+1,'1','9');
				if(x==' ' && i>8 && i<F-7) ng |= !okok(i-2,0xa,0xa) && !okok(i-3,0xa,0xa);
				if(x==' ' && i>8 && i<F-7) ng |= !okok(i+2,0xa,0xa) && !okok(i+3,0xa,0xa);
				if(x==0xa && i>8 && i<F-7) ng |= !okok(i-2,' ',' ') && !okok(i-3,' ',' ');
				if(x==0xa && i>8 && i<F-7) ng |= !okok(i+2,' ',' ') && !okok(i+3,' ',' ');
				
			}
			if(!ng) c2.push_back(*it);
		}
		cand[i%L]=c2;
	}
	
	ll h=1;
	FOR(i,L) h*=cand[i].size();
	if(h!=1) return;
	
	FOR(i,F) ungetc(hoge[F-1-i]^cand[(F-1-i)%L][0],stdin);
	cin>>j;
	FOR(i,j) {
		cin>>x>>y;
		_P("%d\n",x^y);
	}
}


int main(int argc,char** argv){
	L=atoi(argv[1]);
	F=0;
	int c;
	
	FILE* fp = fopen( argv[2], "r" );
	while((c=fgetc(fp))>=0) hoge[F++]=c;
	fclose(fp);
	solve();
	
	return 0;
}


