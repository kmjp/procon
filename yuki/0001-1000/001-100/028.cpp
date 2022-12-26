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

int Q;
ll S,N,K,B;
int num[3][10003];
ll mo=100000009;

map<ll,int> enumdiv(ll n) {
	map<ll,int> V;
	for(ll i=2;i*i<=n;i++) while(n%i==0) V[i]++,n/=i;
	if(n>1) V[n]++;
	return V;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>Q;
	while(Q--) {
		cin>>S>>N>>K>>B;
		N++;
		map<ll,int> D=enumdiv(B);
		vector<int> V;
		ITR(it,D) V.push_back(it->first);
		
		ZERO(num);
		FOR(i,N) {
			FOR(j,V.size()) {
				ll t=S;
				while(t%V[j]==0) num[j][i]++, t/=V[j];
			}
			S = 1+(S*S+S*12345)%mo;
		}
		int mi=1000000000;
		FOR(j,V.size()) {
			sort(num[j],num[j]+N);
			x=0;
			FOR(i,K) x+=num[j][i];
			mi=min(mi,x/D[V[j]]);
		}
		cout<<mi<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
