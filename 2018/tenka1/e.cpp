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

int H,W;
string S[303];

int R[2003][2003];
int L[2003][2003];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	FOR(y,H) cin>>S[y];
	FOR(y,2000) FOR(x,2000) {
		if(y&&x) R[y][x]=R[y-1][x-1];
		if(y) L[y][x]=L[y-1][x+1];
		if(y-700>=0 && y-700<H && x-700>=0 && x-700<W) {
			R[y][x]+=S[y-700][x-700]=='#';
			L[y][x]+=S[y-700][x-700]=='#';
		}
		
	}
	
	ll ret=0;
	FOR(y,H) FOR(x,W) {
		for(l=1;l<=300;l++) {
			int num[11]={};
			if(y-l>=0) num[8]=S[y-l][x]=='#';
			if(y+l<H) num[2]=S[y+l][x]=='#';
			if(x-l>=0) num[4]=S[y][x-l]=='#';
			if(x+l<W) num[6]=S[y][x+l]=='#';
			num[7]=L[y+700][x-l+700]-L[y-l+700][x+700]-num[4];
			num[3]=L[y+l+700][x+700]-L[y+700][x+l+700]-num[2];
			num[9]=R[y+700][x+l+700]-R[y-l+700][x+700]-num[6];
			num[1]=R[y+l+700][x+700]-R[y+700][x-l+700]-num[2];
			ll p=ret;
			ret+=num[2]*(num[6]*num[8]+num[4]*num[8]+num[4]*num[6]);
			ret+=num[4]*num[6]*num[8];
			ret+=num[1]*num[6]*num[8];
			ret+=num[3]*num[4]*num[8];
			ret+=num[9]*num[2]*num[4];
			ret+=num[7]*num[2]*num[6];
		}
	}
	
	cout<<ret<<endl;
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
