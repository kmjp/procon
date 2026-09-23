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

const int prime_max = 10010101;
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
ll p10[10];
int N;
string S;
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cprime();
	p10[0]=1;
	FOR(i,7) p10[i+1]=p10[i]*10;
	
	cin>>S;
	N=S.size();
	FORR(p,prime) if(p>=p10[N-1]&&p<p10[N]) {
		int ok=1;
		map<char,int> A;
		map<int,char> B;
		FOR(i,N) {
			int v=p/p10[N-1-i]%10;
			if(A.count(S[i])&&A[S[i]]!=v) break;
			if(B.count(v)&&B[v]!=S[i]) break;
			A[S[i]]=v;
			B[v]=S[i];
		}
		if(i==N) {
			cout<<p<<endl;
			return;
		}
	}
	cout<<-1<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
