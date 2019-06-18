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
pair<int,int> P[101010];
int mi[101010];
vector<pair<int,int>> D;


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>A[i];
		P[i]={A[i],i};
	}
	sort(P,P+N);
	int C[2]={};
	FOR(i,N) {
		if(P[i].first<0) mi[P[i].second]=1;
		C[mi[P[i].second]]++;
	}
	
	if(C[0]==N) {
		mi[P[0].second]=1;
	}
	if(C[1]==N) {
		mi[P[N-1].second]=0;
	}
	multiset<ll> S[2];
	FOR(i,N) S[mi[i]].insert(A[i]);
	
	vector<pair<ll,ll>> V;
	while(S[0].size()>1) {
		auto it=S[0].begin();
		auto it2=S[1].begin();
		ll a=*it;
		ll b=*it2;
		S[0].erase(it);
		S[1].erase(it2);
		V.push_back({b,a});
		S[1].insert(b-a);
	}
	while(S[1].size()) {
		auto it=S[0].begin();
		auto it2=S[1].begin();
		ll a=*it;
		ll b=*it2;
		S[0].erase(it);
		S[1].erase(it2);
		V.push_back({a,b});
		S[0].insert(a-b);
	}
	
	cout<<*S[0].begin()<<endl;
	FORR(d,V) cout<<d.first<<" "<<d.second<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
