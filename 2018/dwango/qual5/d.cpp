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

int N,D;
int X[101010];
int Y[101010];

int A[2][2110][2110];
int S[2][2110][2110];
int num[2020][2020];

int sum(int type,int x,int y,int d) {
	return S[type][x+d][y+d]-S[type][x+d][y]-S[type][x][y+d]+S[type][x][y];
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>D;
	int R=0;
	FOR(i,N) {
		cin>>X[i]>>Y[i];
		num[X[i]%D][Y[i]%D]++;
		R=max(R,num[X[i]%D][Y[i]%D]);
	}
	
	x=1;
	while(x*x<R) x++;
	R=x;
	
	FOR(x,D) FOR(y,D) {
		if(num[x][y]<=(R-1)*(R-1)) {
			continue;
		}
		else if(num[x][y]<=R*(R-1)) {
			A[1][x][y]=1;
		}
		else {
			A[0][x][y]=1;
		}
	}
	FOR(i,2) FOR(x,2*D+1) FOR(y,2*D+1) {
		if(x) S[i][x][y]+=S[i][x-1][y];
		if(y) S[i][x][y]+=S[i][x][y-1];
		if(x&&y) {
			S[i][x][y]-=S[i][x-1][y-1];
			S[i][x][y]+=A[i][(x-1)%D][(y-1)%D];
		}
	}
	
	int mi=101010;
	FOR(x,D) FOR(y,D) {
		int cur=D;
		for(i=10;i>=0;i--) if(cur-(1<<i)>=1) {
			j=cur-(1<<i);
			if(sum(0,x,y,D)!=sum(0,x,y,j)) continue;
			if(sum(1,x+j,y+j,D-j)) continue;
			cur-=1<<i;
		}
		
		mi=min(mi,cur);
	}
	
	
	
	
	cout<<mi-1+(R-1)*D<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
