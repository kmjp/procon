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
int L[303030],R[303030];

ll hoge(int m) {
	vector<ll> V;
	int i;
	FOR(i,N) {
		if(m<L[i]) V.push_back(L[i]);
		else if(m>R[i]) V.push_back(R[i]);
		else V.push_back(m);
	}
	sort(ALL(V));
	ll ret=0;
	FOR(i,N) {
		ret+=i*V[i]-(N-1-i)*V[i];
	}
	return ret;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	vector<int> cand;
	FOR(i,N) {
		cin>>L[i]>>R[i];
		cand.push_back(L[i]);
		cand.push_back(R[i]);
	}
	sort(ALL(cand));
	cand.erase(unique(ALL(cand)),cand.end());
	
	ll mi=1LL<<60;
	int TL=0,TR=cand.size()-1;
	mi=min(mi,hoge(TL));
	mi=min(mi,hoge(TR));
	while(TR-TL>=3) {
		int m1=(TL*2+TR)/3;
		int m2=(TR*2+TL)/3;
		ll v1=hoge(cand[m1]);
		ll v2=hoge(cand[m2]);
		mi=min(mi,v1);
		mi=min(mi,v2);
		if(v1<v2) TR=m2;
		else if(v1>v2) TL=m1;
		else TL=m1,TR=m2;
	}
	for(i=TL;i<=TR;i++) mi=min(mi,hoge(cand[i]));
	
	cout<<mi<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
