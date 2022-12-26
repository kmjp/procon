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

int T;
int N;
ll P[20];
int bi[20];
int minbi[1<<15];
double bip[20][65];
double bipsum[20][65];
double memo[1<<15];

double dodo(int pm) {
	
	if(__builtin_popcount(pm)<=1) return __builtin_popcount(pm);
	if(memo[pm]>=0) return memo[pm];
	
	vector<int> id;
	double ret=0;
	double left=1, p2b=1;
	int mask,i,x;
	
	FOR(i,N) if(pm&(1<<i)) id.push_back(i), p2b *= (P[i]-1.0)/P[i];
	int n=id.size();
	
	
	FOR(mask,1<<n) {
		double p1=1;
		int nm[2]={};
		FOR(i,n) {
			if(mask&(1<<i)) p1 *= 1.0/P[id[i]], nm[0] |= 1<<id[i];
			else p1 *= (P[id[i]]-1.0)/P[id[i]], nm[1] |= 1<<id[i];
		}
		if(nm[0] && nm[1]) {
			int mb=minbi[nm[0]];
			
			double p2=0;
			for(x=1;x<=63;x++) {
				double hoge=1;
				FOR(i,n) {
					if(mask&(1<<i)) hoge *= bip[id[i]][x];
					else hoge *= bipsum[id[i]][x-1];
				}
				p2+=hoge;
			}
			
			double pat = p1 + p2*p2b;
			left -= pat;
			ret += pat * (dodo(nm[0])+dodo(nm[1]));
		}
	}
	
	return memo[pm]=(1+ret)/(1-left);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,1<<N) memo[i]=-1;
	
	ZERO(bip);
	ZERO(bipsum);
	FOR(i,N) {
		cin>>P[i];
		ll p=P[i]-1;
		bi[i]=0;
		while(p%2==0) bi[i]++, p/=2;
		
		bipsum[i][0]=bip[i][0]=pow(0.5,bi[i]);
		for(x=1;x<=64;x++) {
			if(x<=bi[i]) bip[i][x]=pow(0.5,bi[i]+1-x);
			bipsum[i][x]=bipsum[i][x-1]+bip[i][x];
		}
		
	}
	
	FOR(i,1<<N) {
		minbi[i]=100;
		FOR(j,N) if(i & (1<<j)) minbi[i]=min(minbi[i],bi[j]);
	}
	
	_P("%.12lf\n",dodo((1<<N)-1));
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cin>>T;
	FOR(i,T) solve();
	return 0;
}
