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
int X[101010],Y[101010];

int miX,maX,miY,maY;

int ok(int V) {
	int flag[2]={1,1};
	int i;
	
	FOR(i,N) {
		if(!((miX<=X[i]&&X[i]<=miX+V&&miY<=Y[i]&&Y[i]<=miY+V)||(maX-V<=X[i]&&X[i]<=maX&&maY-V<=Y[i]&&Y[i]<=maY))) flag[0]=0;
		if(!((miX<=X[i]&&X[i]<=miX+V&&maY-V<=Y[i]&&Y[i]<=maY)||(maX-V<=X[i]&&X[i]<=maX&&miY<=Y[i]&&Y[i]<=miY+V))) flag[1]=0;
	}
	return flag[0]|flag[1];
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	
	miX=miY=1<<30;
	maX=maY=-1<<30;
	FOR(i,N) {
		cin>>x>>y;
		X[i]=x+y;
		Y[i]=x-y+100000;
		miX=min(miX,X[i]);
		maX=max(maX,X[i]);
		miY=min(miY,Y[i]);
		maY=max(maY,Y[i]);
	}
	
	int ret=1<<30;
	for(i=29;i>=0;i--) if(ok(ret-(1<<i))) ret-=1<<i;
	cout<<ret<<endl;
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
