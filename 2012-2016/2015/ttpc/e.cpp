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

int N,K;
int X[20],Y[20];
int tot[2020][2020];
int sum[2020][2020];

int range(int L,int T,int R,int B) {
	if(L>R || T>B) return 0;
	if(L<0 || R>=N || T<0 || B>=N) return 0;
	return abs(sum[B+1][R+1] -sum[B+1][L]-sum[T][R+1]+sum[T][L]);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	FOR(y,N) FOR(x,N) tot[y][x]=((y+x)%2)?1:-1;
	FOR(i,K) {
		cin>>X[i]>>Y[i];
		X[i]--;
		Y[i]--;
		tot[Y[i]][X[i]]*=-1;
	}
	FOR(y,N) FOR(x,N) sum[y+1][x+1]= sum[y][x+1] + sum[y+1][x] -sum[y][x] +tot[y][x];
	int ma=1;
	for(int mask=1;mask<1<<K;mask++) {
		int L=N-1,R=0,T=N-1,B=0;
		FOR(i,K) if(mask&(1<<i)) L=min(L,X[i]),R=max(R,X[i]),T=min(T,Y[i]),B=max(B,Y[i]);
		
		for(int x1=L-1;x1<=L;x1++) for(int x2=R;x2<=R+1;x2++)
		for(int y1=T-1;y1<=T;y1++) for(int y2=B;y2<=B+1;y2++) ma=max(ma,range(x1,y1,x2,y2));
	}
	
	
	
	cout<<ma<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
