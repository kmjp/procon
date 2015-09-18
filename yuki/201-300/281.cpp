#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int D;
int H[3],H2[3];
int ret=2e9;

int iskado(int a,int b,int c) {
	if(a!=c && a<b && c<b) return 1;
	if(a!=c && a>b && c>b) return 1;
	return 0;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>D;
	FOR(i,3) cin>>H[i],H2[i]=H[i];
	
	if(D==0) {
		if(iskado(H[0],H[1],H[2])) ret=0;
	}
	else {
		// up
		x = max(0, (H[0]-H[1]+1+(D-1))/D);
		y = max(0, (H[2]-H[1]+1+(D-1))/D);
		H[0]=max(0,H[0]-x*D);
		H[2]=max(0,H[2]-y*D);
		if(H[0]==H[2] && H[0]!=0) x++, H[0]=max(0,H[0]-D);
		if(iskado(H[0],H[1],H[2])) ret=min(ret,x+y);
		
		// down
		FOR(i,3) H[i]=H2[i];
		x=0;
		if(H[0]==H[2]) x++,H[2]=max(0,H[2]-D);
		if(H[0]>H[2]) swap(H[0],H[2]);
		y = max(0, (H[1]-H[0]+1+(D-1))/D);
		H[1]-=y*D;
		if(H[1]>=0 && iskado(H[0],H[1],H[2])) ret=min(ret,x+y);
	}
	
	if(ret==2e9) ret=-1;
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
