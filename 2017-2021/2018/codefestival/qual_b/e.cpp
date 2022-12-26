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

const int prime_max = 1000000;
int NP,prime[100000],divp[prime_max];
int num[101],mp[101];
int pl[100];
int hoge[101];
int N;
vector<int> P[2];

void cprime() {
	for(int i=2;i<=N;i++) if(divp[i]==0) {
		prime[NP++]=i;
		for(ll j=1LL*i*i;j>=i&&j<prime_max;j+=i) if(divp[j]==0) divp[j]=i;
	}
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	
	if(N==1) {
		cout<<1<<endl;
		cout<<"+ 1"<<endl;
		return;
	}
	
	cprime();
	FOR(i,NP) {
		mp[i]=1;
		while(mp[i]*prime[i]<=N) num[i]++, mp[i]*=prime[i];
	}
	
	int tot=0;
	vector<double> V[2];
	FOR(i,NP) {
		x=1;
		FOR(j,NP) if(j!=i) x=x*mp[j]%mp[i];
		pl[i]=x;
		for(y=0;x*y%mp[i]!=1;y++);
		if(2*y<mp[i]) {
			hoge[i]=y;
			FOR(x,hoge[i]) P[0].push_back(mp[i]);
			V[0].push_back(hoge[i]*1.0/mp[i]);
		}
		else {
			hoge[i]=y-mp[i];
			FOR(x,-hoge[i]) P[1].push_back(mp[i]);
			V[1].push_back(-hoge[i]*1.0/mp[i]);
		}
		tot+=abs(hoge[i]);
	}
	sort(ALL(V[0]));
	sort(ALL(V[1]));
	double a=0,d=0;
	FORR(v,V[0]) a+=v;
	FORR(v,V[1]) d+=v;
	double ret=a-d;
	while(ret<-0.1) ret+=1.0, P[0].push_back(1);
	while(ret>0.9) ret-=1.0, P[1].push_back(1);
	
	cout<<P[0].size()+P[1].size()<<endl;
	FORR(p,P[0]) cout<<"+ "<<p<<endl;
	FORR(p,P[1]) cout<<"- "<<p<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
