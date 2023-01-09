#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------

const int prime_max = 100000;
set<int> prime;
int NP,divp[prime_max];

void cprime() {
	if(NP) return;
	for(int i=2;i<prime_max;i++) if(divp[i]==0) {
		//M[i]=NP;
		prime.insert(i); NP++;
		for(ll j=1LL*i*i;j>=i&&j<prime_max;j+=i) if(divp[j]==0) divp[j]=i;
	}
}

ll M;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>M;
	cprime();
	vector<int> V;
	
	if(M==0) V={1};
	
	while(M) {
		int n=0;
		while((1<<(n+1))-1<=M) n++;
		M-=(1<<n)-1;
		int a=*prime.begin();
		prime.erase(a);
		V.push_back(a);
		n--;
		while(n) {
			int b=*prime.rbegin();
			prime.erase(b);
			if(a*b<=100000) {
				n--;
				V.push_back(a*b);
			}
		}
	}
	
	
	cout<<V.size()<<endl;
	FORR(v,V) cout<<v<<" ";
	cout<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}