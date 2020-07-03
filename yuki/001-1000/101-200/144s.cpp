#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

// ２回以上行うならNP,prime,divを要クリア
const int prime_max = 10005;
int NP,prime[100000],divp[prime_max];
map<int,int> M;

void cprime() {
	for(int i=2;i<prime_max;i++) if(divp[i]==0) {
		//M[i]=NP;
		prime[NP++]=i;
		for(int j=i;j<prime_max;j+=i) divp[j]=i;
	}
}

int N;
double P;
double ret;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>P;
	P=1-P;
	cprime();
	for(i=2;i<=N;i++) {
		y=x=i;
		double hoge=1;
		vector<int> V;
		for(j=0;prime[j]*prime[j]<=x;j++) {
			if(x%prime[j]==0) {
				r=0;
				while(x%prime[j]==0) r++, x/=prime[j];
				V.push_back(r);
			}
		}
		if(x!=i && x>1) V.push_back(1);
		y=1;
		ITR(it,V) y*=(1+*it);
		if(y==1) y=0;
		else y-=2;
		while(y--) hoge *=P;
		ret += hoge;
	}
	
	_P("%.12lf\n",ret);
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
