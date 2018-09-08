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

int dy[4]={0,1,0,-1};
int dx[4]={1,0,-1,0};

int X[4],Y[4];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>X[0]>>Y[0]>>X[1]>>Y[1];
	int dx=-(Y[1]-Y[0]),dy=(X[1]-X[0]);
	X[2]=X[1]+dx;
	Y[2]=Y[1]+dy;
	X[3]=X[0]+dx;
	Y[3]=Y[0]+dy;
	cout<<X[2]<<" "<<Y[2]<<" "<<X[3]<<" "<<Y[3]<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
