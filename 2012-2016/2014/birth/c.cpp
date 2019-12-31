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

int N,K;
string S[100];
string L;
char SS[1000][1000];

void solve() {
	int f,i,j,k,l,x,y;
	
	FOR(i,26) L+='A'+i;
	FOR(i,26) L+='a'+i;
	
	cin>>N>>K;
	
	if(N==2) {
		FOR(i,K) S[0]+='A',S[1]+='B';
		return _P("%d %d\n%s\n%s\n",K,2,S[0].c_str(),S[1].c_str());
	}
	if(K==1) {
		if(N==4) return _P("2 2\nAB\nDC\n");
		if(N<8 || N%2) return _P("-1\n");
		x=(N-2)/2;
		
		FOR(i,x) SS[0][i]=SS[1][i]=SS[2][i]='.';
		y=0;
		FOR(i,x) SS[0][i]=L[y++];
		SS[1][x-1]=L[y++];
		FOR(i,x) SS[2][x-1-i]=L[y++];
		SS[1][0]=L[y++];
		_P("%d %d\n%s\n%s\n%s\n",x,3,SS[0],SS[1],SS[2]);
		return;
	}
	if(N==3) {
		FOR(i,K) S[0]+='A';
		FOR(i,K) S[0]+='B';
		FOR(i,2*K) S[1]+='.';
		FOR(i,K) S[1][i+K/2]='C';
		return _P("%d 2\n%s\n%s\n",S[0].size(),S[0].c_str(),S[1].c_str());
	}
	if(K==2) {
		ZERO(SS);
		int w=N-1;
		FOR(x,w) SS[1][x]='.';
		i=0;
		FOR(x,w) SS[0][x]=L[(i++)/2];
		SS[1][w-1]=L[(i++)/2];
		FOR(x,w) SS[2][w-1-x]=L[(i++)/2];
		SS[1][0]=L[(i++)/2];
		return _P("%d 3\n%s\n%s\n%s\n",w,SS[0],SS[1],SS[2]);
	}
	
	for(int w=3;w<=max(N,K);w++) {
		for(int h=1;h<=K-1;h++) {
			int num=(w+(h-1)+(K-1))/K;
			int rem=1+(num*K-(w+h-1))%K;
			
			int lnum=w;
			if(h>2) lnum--;
			if(rem>2) lnum--;
			if(lnum!=N-num) continue;
			ZERO(SS);
			FOR(y,K+2) FOR(x,w) SS[y][x]='.';
			FOR(i,num*K) {
				int tx,ty;
				if(i<h) tx=0,ty=h-1-i;
				else if(i<h+w-1) tx=i-(h-1),ty=0;
				else tx=w-1,ty=i-(h+w)+2;
				SS[ty][tx]=L[i/K];
			}
			for(i=num;i<N;i++) {
				int xdif=w-2;
				int ydif=2;
				if(rem<=2) xdif++;
				if(i==num && rem<=1) ydif--;
				if(i==N-1 && h<=1) ydif--;
				FOR(y,K) SS[y+ydif][xdif-(i-num)]=L[i];
			}
			FOR(i,N) {
				num=0;
				FOR(y,K+2) FOR(x,w) if(SS[y][x]=='A'+i) num++;
			}
			
			_P("%d %d\n",w,K+2);
			FOR(y,K+2) _P("%s\n",SS[y]);
			return;
		}
	}
	return _P("-1\n");
}


int main(int argc,char** argv){
	string s;
	if(argc==1) ios::sync_with_stdio(false);
	for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
	for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
	solve();
	return 0;
}


