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
ll T,A[202020],B[202020];
pair<ll,ll> P[202020];
priority_queue<ll> Q1;
multiset<ll> Q3;
unordered_multiset<ll> Q2;

ll ok(int v) {
	if(v>N) return T+1;
	while(Q1.size()) Q1.pop();
	Q2.clear();
	Q3.clear();
	
	ll S=0;
	int i;
	FOR(i,K) {
		S+=B[i];
		Q1.push(B[i]);
	}
	vector<ll> V(N-K);
	FOR(i,N-K) {
		V[i]=A[i+K];
	}
	sort(ALL(V));
	Q3.insert(1LL<<60);
	FOR(i,V.size()) {
		if(i<v-K) {
			Q2.insert(V[i]);
			S+=V[i];
		}
		else {
			Q3.insert(V[i]);
		}
	}
	if(S<=T) return S;
	for(i=K;i<N;i++) {
		ll a=A[i];
		auto it=Q2.find(a);
		if(it!=Q2.end()) {
			Q2.erase(it);
			S-=a;
			ll b=*Q3.begin();
			S+=b;
			if(b>=1LL<<60) return T+1;
			Q3.erase(Q3.begin());
			Q2.insert(b);
		}
		else {
			Q3.erase(Q3.find(a));
		}
		ll b=B[i];
		if(b<Q1.top()) {
			S-=Q1.top();
			Q1.pop();
			S+=b;
			Q1.push(b);
		}
		if(S<=T) return S;
	}
	return T+1;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K>>T;
	FOR(i,N) {
		cin>>A[i]>>B[i];
		P[i]={-(A[i]-B[i]),A[i]};
	}
	sort(P,P+N);
	vector<ll> V;
	FOR(i,N) {
		A[i]=P[i].second;
		B[i]=P[i].first+P[i].second;
		V.push_back(B[i]);
	}
	// Kà»â∫ÅH
	sort(ALL(V));
	ll sum=0;
	int num=0;
	FOR(i,N) {
		sum+=V[i];
		if(sum<=T) num++;
	}
	if(num<=K) {
		cout<<num<<endl;
		return;
	}
	int ret=K;
	for(i=20;i>=0;i--) if(ok(ret+(1<<i))<=T) ret+=1LL<<i;
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
