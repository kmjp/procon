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

int N,K;
ll A[505050];
ll S[505050];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	FOR(i,N) {
		cin>>A[i];
		S[i+1]=S[i]+A[i];
	}
	//æ“ªKŒÂ
	multiset<ll> M;
	ll cur=S[N]-S[0];
	for(i=1;i<K;i++) {
		ll a=S[N]-S[i];
		M.insert(a);
		cur+=a;
	}
	ll ret=cur-K*(S[N]-S[K]);
	for(i=K;i<N;i++) {
		ll a=S[N]-S[i];
		cur+=a;
		M.insert(a);
		cur-=*M.begin();
		M.erase(M.begin());
		chmax(ret,cur-K*(S[N]-S[(i+1)]));
		
	}
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
