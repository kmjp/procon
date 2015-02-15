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
string S;
int I[1000800];
int NN[1000800],DD[1000800],TT[1000800],H,TA;


void solve() {
	int f,i,j,k,l,x,y;
	
	cin>>S;
	S+="------------";
	N=S.size();
	x=5;
	ll tot=0;
	FOR(i,N) {
		if(S[i]=='N' && x>0) {
			x--;
			I[i+6]++;
			NN[i+1]++;
			DD[i]+=1*(10+H/10);
		}
		if(S[i]=='C' && x>=3) {
			x-=3;
			I[i+8]+=3;
			NN[i+3]++;
			DD[i+2]+=5*(10+H/10);
			S[i+1]=S[i+2]='-';
		}
		// 0.5
		tot+=DD[i];
		x+=I[i];
		H+=NN[i];
	}
	cout<<tot<<endl;
}


int main(int argc,char** argv){
	string s;
	if(argc==1) ios::sync_with_stdio(false);
	for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
	for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
	solve();
	return 0;
}


