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

int N;
int A[8]={2,3,4,6,8,9,10,12};
int hoge[9]={};
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	if(N==3) {
		cout<<"2 5 63"<<endl;
		return;
	}
	int mask;
	FOR(mask,1<<8) {
		int g=0;
		int S=0;
		FOR(i,8) if(mask&(1<<i)) {
			g=__gcd(g,A[i]);
			S+=A[i];
		}
		if(g==1 && S%6==0) hoge[__builtin_popcount(mask)]=mask;
	}
	
	
	
	hoge[1]=1<<7;
	hoge[2]=(1<<2)|(1<<4);
	hoge[3]=(1<<0)|(1<<2)|(1<<3);
	
	x=N%8;
	if(x==0) x=8;
	N-=x;
	FOR(i,8) if(hoge[x]&(1<<i)) cout<<A[i]<<" ";
	for(x=1;x<=N/8;x++) {
		FOR(y,8) cout<<12*x+A[y]<<" ";
	}
	cout<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
