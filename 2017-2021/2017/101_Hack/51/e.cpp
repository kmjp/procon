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

int N,M;
string S[1010];
int sum[2010][2010];
int LT[2010][2010];
int LD[2010][2010];
int RT[2010][2010];
int RD[2010][2010];

int Q,T;
int RS[2020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(y,N) cin>>S[y];
	
	for(x=0;x<2*M;x+=2) {
		for(y=1;y<N;y++) sum[y][x]=sum[y-1][x]+(S[y][x]=='t');
		
		RS[x]=sum[N-1][x];
		if(x) RS[x]+=RS[x-2];
		
		for(y=1;y<N-1;y++) {
			LT[y][x]=sum[y][x];
			if(y>=2&&x>=2) LT[y][x]+=LT[y-2][x-2];
			LD[y][x]=sum[N-1][x]-sum[y-1][x];
			if(y+2<=N-1&&x>=2) LD[y][x]+=LD[y+2][x-2];
		}
	}
	for(x=2*M-2;x>=0;x-=2) {
		for(y=1;y<N-1;y++) {
			RT[y][x]=sum[y][x];
			if(y>=2&&x+2<=2*M) RT[y][x]+=RT[y-2][x+2];
			RD[y][x]=sum[N-1][x]-sum[y-1][x];
			if(y+2<=N-1&&x+2<=2*M) RD[y][x]+=RD[y+2][x+2];
		}
	}
	
	
	
	cin>>Q;
	while(Q--) {
		cin>>T;
		
		ll ret=0;
		ll mo=1000000007;
		for(y=1;y<N-1;y++) for(x=0;x<=2*M-1;x+=2) {
			// same row
			ll cnt=sum[min(N-1,y+T)][x]-sum[max(0,y-T-1)][x];
			
			int lef=x;
			for(i=10;i>=0;i--) {
				int tmp=lef-(2<<i);
				int top=max(0,T-y-(x-tmp));
				int bot=max(0,T-(N-1-y)-(x-tmp));
				
				if(top+bot>=N-1) lef=tmp;
			}
			
			if(x) cnt+=RS[x-2];
			if(lef>=2) cnt-=RS[lef-2];
			lef-=2;
			if(lef>=0) {
				int top=max(0,T-y-(x-lef));
				int bot=max(0,T-(N-1-y)-(x-lef));
				cnt+=LT[top][lef]+LD[N-1-bot][lef];
			}
			
			int ri=x;
			for(i=10;i>=0;i--) {
				int tmp=ri+(2<<i);
				int top=max(0,T-y-(tmp-x));
				int bot=max(0,T-(N-1-y)-(tmp-x));
				if(top+bot>=N-1) ri=tmp;
			}
			
			cnt+=RS[min(2*M-2,ri)];
			cnt-=RS[x];
			ri+=2;
			if(ri<=2*M-1) {
				int top=max(0,T-y-(ri-x));
				int bot=max(0,T-(N-1-y)-(ri-x));
				cnt+=RT[top][ri]+RD[N-1-bot][ri];
			}
			
			(ret+=cnt*cnt%mo*((x+1)*(y+1)))%=mo;
		}
		cout<<ret<<endl;
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
