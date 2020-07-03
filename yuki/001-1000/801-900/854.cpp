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

int N;
int A[101010];
int S[101010][305],Z[101010];
int Q,P,L,R;

const int prime_max = 2000;
vector<int> prime;
int NP,divp[prime_max];

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
	cin>>N;
	FOR(i,N) {
		cin>>x;
		FOR(j,NP) {
			S[i+1][j]=S[i][j];
			if(x) {
				while(x%prime[j]==0) {
					S[i+1][j]++;
					x/=prime[j];
				}
			}
		}
		Z[i+1]=Z[i];
		if(x==0) Z[i+1]++;
	}
	cin>>Q;
	while(Q--) {
		cin>>P>>L>>R;
		L--;
		
		if(Z[R]-Z[L]) {
			cout<<"Yes"<<endl;
			continue;
		}
		
		FOR(i,NP) {
			x=0;
			while(P%prime[i]==0) {
				P/=prime[i];
				x++;
			}
			if(S[R][i]-S[L][i]<x) break;
		}
		if(i!=NP || P!=1) {
			cout<<"NO"<<endl;
		}
		else {
			cout<<"Yes"<<endl;
		}
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
