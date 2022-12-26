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

long double comb(int P_,int Q_) {
	static const int N_=102;
	static long double C_[N_][N_];
	
	if(C_[0][0]==0) {
		int i,j;
		FOR(i,N_) C_[i][0]=C_[i][i]=1;
		for(i=1;i<N_;i++) for(j=1;j<i;j++) C_[i][j]=(C_[i-1][j-1]+C_[i-1][j]);
	}
	if(P_<0 || P_>N_ || Q_<0 || Q_>P_) return 0;
	return C_[P_][Q_];
}

int N;
long double ret;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	long double tot=comb(99,N);
	for(int mask=0;mask<1<<25;mask++) {
		x=0;
		if(__builtin_popcount(mask)>N) continue;
		long double prob = comb(74,N-__builtin_popcount(mask))/tot;
		if(prob==0) continue;
		
		FOR(i,5) {
			if((mask & (((1+(1<<5)+(1<<10)+(1<<15)+(1<<20)))<<i))==(((1+(1<<5)+(1<<10)+(1<<15)+(1<<20)))<<i)) x++;
			if((mask & (31<<(i*5)))==(31<<(i*5))) x++;
		}
		if((mask & ((1+(1<<6)+(1<<12)+(1<<18)+(1<<24))))==((1+(1<<6)+(1<<12)+(1<<18)+(1<<24)))) x++;
		if((mask & (((1<<4)+(1<<8)+(1<<12)+(1<<16)+(1<<20))))==(((1<<4)+(1<<8)+(1<<12)+(1<<16)+(1<<20)))) x++;
		ret += prob*x;
	}
	
	_P("%.10Lf\n",ret);
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
