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
int A[2020][2020];
int B[2020][2020];
int ma;

int ok(int t) {
	int y,x,i;
	if(t<0) return 0;
	FOR(y,H) FOR(x,W) {
		B[y][x]=0;
		if(A[y][x]>=ma-t) B[y][x] |= 1;
		if(A[y][x]<=t) B[y][x] |= 2;
		if(B[y][x]==0) return 0;
	}
	
	
	// 2|->1 
	int L[2020]={},R[2020]={};
	FOR(i,2) {
		FOR(y,H) {
			R[y]=y?R[y-1]:-1;
			FOR(x,W) if(B[y][x]==1+i) R[y]=max(R[y],x);
		}
		for(y=H-1;y>=0;y--) {
			L[y]=(y==H-1)?W+1:L[y+1];
			FOR(x,W) if(B[y][x]==2-i) L[y]=min(L[y],x);
			if(L[y]<=R[y]) break;
		}
		if(y<0) return 1;
		
		FOR(y,H) {
			L[y]=y?L[y-1]:W+1;
			FOR(x,W) if(B[y][x]==1+i) L[y]=min(L[y],x);
		}
		for(y=H-1;y>=0;y--) {
			R[y]=(y==H-1)?-1:R[y+1];
			FOR(x,W) if(B[y][x]==2-i) R[y]=max(R[y],x);
			if(L[y]<=R[y]) break;
		}
		if(y<0) return 1;
	}
	return 0;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	int mi=1<<30;
	FOR(y,H) FOR(x,W) {
		cin>>A[y][x];
		ma=max(ma,A[y][x]);
		mi=min(mi,A[y][x]);
	}
	
	ma-=mi;
	FOR(y,H) FOR(x,W) A[y][x]-=mi;
	int ret=ma;
	for(i=30;i>=0;i--) if(ok(ret-(1<<i))) ret-=1<<i;
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
