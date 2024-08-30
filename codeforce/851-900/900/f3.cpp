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

const int prime_max = 1000001;
vector<int> prime;
int NP,divp[prime_max];

void cprime() {
	if(NP) return;
	for(int i=2;i<prime_max;i++) if(divp[i]==0) {
		//M[i]=NP;
		prime.push_back(i); NP++;
		for(ll j=1LL*i;j>=i&&j<prime_max;j+=i) divp[j]=i;
	}
}

int T,N,Q;


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cprime();
	cin>>T;
	while(T--) {
		cin>>N>>Q;
		map<int,int> M;
		x=N;
		while(x>1) {
			M[divp[x]]++;
			x/=divp[x];
		}
		ll cur=N;
		while(Q--) {
			cin>>i;
			if(i==2) {
				M.clear();
				x=N;
				while(x>1) {
					M[divp[x]]++;
					x/=divp[x];
				}
			}
			else {
				cin>>x;
				while(x>1) {
					M[divp[x]]++;
					x/=divp[x];
				}
				
				map<int,int> V;
				FORR2(a,b,M) {
					x=b+1;
					while(x>1) {
						V[divp[x]]++;
						x/=divp[x];
					}
				}
				int ok=1;
				FORR2(a,b,V) if(M.count(a)==0||M[a]<b) ok=0;
				if(ok) {
					cout<<"YES"<<endl;
				}
				else {
					cout<<"NO"<<endl;
				}
			}
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
