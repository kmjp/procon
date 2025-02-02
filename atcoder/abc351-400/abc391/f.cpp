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
ll A[202020];
ll B[202020];
ll C[202020];

ll val(ll a,ll b,ll c) {
	return A[a]*B[b]+B[b]*C[c]+C[c]*A[a];
}
void split(ll v,int& a,int& b,int& c) {
	a=v>>40;
	b=(v>>20)%(1<<20);
	c=v%(1<<20);
}
set<ll> S;
priority_queue<pair<ll,ll>> Q;

void add(ll a,ll b,ll c) {
	if(a<0||b<0||c<0) return;
	ll id=(a<<40)+(b<<20)+c;
	if(S.count(id)) return;
	S.insert(id);
	Q.push({val(a,b,c),id});
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	FOR(i,N) cin>>A[i];
	FOR(i,N) cin>>B[i];
	FOR(i,N) cin>>C[i];
	sort(A,A+N);
	sort(B,B+N);
	sort(C,C+N);
	add(N-1,N-1,N-1);
	while(K--) {
		ll v=Q.top().first;
		int a,b,c;
		split(Q.top().second,a,b,c);
		Q.pop();
		if(K==0) {
			cout<<v<<endl;
			return;
		}
		add(a-1,b,c);
		add(a,b-1,c);
		add(a,b,c-1);
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
