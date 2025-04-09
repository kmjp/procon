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

int Q;
ll A;

const int prime_max = 1010101;
vector<int> prime;
int NP,divp[prime_max];
vector<ll> V[101010];
void cprime() {
	if(NP) return;
	for(int i=2;i<prime_max;i++) if(divp[i]==0) {
		//M[i]=NP;
		prime.push_back(i); NP++;
		for(ll j=1LL*i*i;j>=i&&j<prime_max;j+=i) if(divp[j]==0) divp[j]=i;
	}
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cprime();
	FOR(i,NP) {
		ll a=1;
		while(a<=1LL<<40) {
			a=a*prime[i];
			if(a>=1LL<<40) break;
			a=a*prime[i];
			if(a>=1LL<<40) break;
			V[i].push_back(a);
		}
	}
	vector<ll> cand;
	FOR(i,NP) {
		FORR(a,V[i]) {
			for(j=i+1;j<NP;j++) {
				if((1LL<<40)/a<V[j][0]) break;
				FORR(b,V[j]) {
					if((1LL<<40)/a<b) break;
					cand.push_back(a*b);
				}
				
			}
		}
	}
	sort(ALL(cand));
	
	
	cin>>Q;
	while(Q--) {
		cin>>A;
		x=lower_bound(ALL(cand),A+1)-cand.begin();
		cout<<cand[x-1]<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
