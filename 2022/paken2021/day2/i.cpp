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

int N;
int A[202020];
int B[202020];

const int prime_max = 1000000;
vector<int> prime;
int NP,divp[prime_max];

void cprime() {
	if(NP) return;
	for(int i=2;i<prime_max;i++) if(divp[i]==0) {
		//M[i]=NP;
		prime.push_back(i); NP++;
		for(ll j=i;j>=i&&j<prime_max;j+=i) if(divp[j]==0) divp[j]=i;
	}
}

set<int> NA[202020];
vector<pair<int,int>> ret;

void go(int a,int b) {
	if(a==b) return;
	if(a>b) swap(a,b);
	assert(b%a==0);
	ret.push_back({a,b});
	swap(A[a],A[b]);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cprime();
	
	cin>>N;
	for(i=2;i<=N;i++) {
		cin>>A[i];
		NA[A[i]].insert(i);
	}
	for(i=2;i<=N;i++) cin>>B[i];
	
	for(i=2;i<=N;i++) if(divp[i]==i&&i*2>N) {
		if(A[i]!=B[i]) {
			cout<<-1<<endl;
			return;
		}
		NA[A[i]].erase(i);
		A[i]=B[i]=0;
	}
	for(i=2;i<=N;i++) if(B[i]) {
		if(NA[B[i]].empty()) {
			cout<<-1<<endl;
			return;
		}
		x=*NA[B[i]].begin();
		if(x!=i) {
			NA[A[x]].erase(x);
			NA[A[i]].erase(i);
			vector<int> T={x,divp[x],2*divp[x],2,2*divp[i],divp[i],i};
			FOR(j,T.size()) {
				for(k=T.size()-1;k>j;k--) {
					if(T[j]==T[k]) {
						FOR(y,k-j) T.erase(T.begin()+j);
						break;
					}
				}
			}
			FOR(j,T.size()-1) go(T[j],T[j+1]);
			for(j=(int)T.size()-3;j>=0;j--) go(T[j],T[j+1]);
			NA[A[x]].insert(x);
		}
		
		assert(A[i]==B[i]);
		NA[B[i]].erase(i);
	}
	
	cout<<ret.size()<<endl;
	FORR2(a,b,ret) cout<<a<<" "<<b<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
