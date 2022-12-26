#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N,K;
int X[100001],Y[100001],H[100001];
int AX[100001],AY[100001],W[100001],HH[100001],D[100001];

int DD[1505][1505];
int S[1505][1505];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	FOR(i,N) cin>>X[i]>>Y[i]>>H[i];
	
	FOR(i,K) {
		cin>>AX[i]>>AY[i]>>W[i]>>HH[i]>>D[i];
		for(y=AY[i]+500;y<=AY[i]+500+HH[i];y++) DD[y][AX[i]+500]+=D[i],DD[y][AX[i]+500+W[i]+1]-=D[i];
	}
	
	FOR(y,1502) FOR(x,1502) S[y][x]=((x>0)?S[y][x-1]:0)+DD[y][x];
	
	int tot=0;
	FOR(i,N) tot+=max(0,H[i]-S[Y[i]+500][X[i]+500]);
	cout<<tot<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
