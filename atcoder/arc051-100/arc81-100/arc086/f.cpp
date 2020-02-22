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
ll K;
vector<ll> A;
ll mo=1000000007;
map<vector<ll>,vector<pair<ll,ll>>> S;

ll cost(ll a,ll b) {
	ll ret=0;
	if(a==0) return 0;
	for(int i=60;i>=0;i--) {
		if((a&(1LL<<i))==(b&(1LL<<i))) {
			if(a&(1LL<<i)) ret |= 1LL<<i;
		}
		else {
			for(int j=0;j<i;j++) if(a&(1LL<<j)) ret |= 1LL<<i;
			break;
		}
	}
	return ret;
}

void hoge(int shift, ll mi) {
	ll left=K-shift-__builtin_popcountll(mi);
	if(left<0) return;
	int i;
	
	vector<ll> V;
	FOR(i,N) {
		if(A[i]-mi<0) return;
		if(i) V.push_back(((A[i]-mi)>>shift)-((A[i-1]-mi)>>shift));
		left=min(left,((A[i]-mi)>>shift));
	}
	/*
	cout<<"! "<<shift<<" "<<mi<<" : ";
	FORR(v,V) cout<<v<<" ";
	cout<<"  : "<<left<<endl;
	*/
	pair<ll,ll> p={((A[0]-mi)>>shift)-left,(A[0]-mi)>>shift};
	//cout<<p.first<<" "<<p.second<<endl;
	S[V].push_back(p);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	A.resize(N);
	FOR(i,N) cin>>A[i];
	
	FOR(i,61) {
		vector<ll> V;
		FOR(j,N) V.push_back(A[j]&((1LL<<i)-1));
		sort(ALL(V));
		V.erase(unique(ALL(V)),V.end());
		ll prev=0;
		FORR(c,V) {
			//cout<<i<<" "<<prev<<":"<<cost(prev,c)<<":"<<c<<"   "<<hoge(i,cost(prev,c))<<endl;
			hoge(i,cost(prev,c));
			prev=c+1;
		}
	}
	
	ll ret=0;
	FORR(m,S) {
		auto p=m.second;
		sort(ALL(p));
		FOR(i,p.size()) {
			int j=i+1;
			ll L=p[i].first,R=p[i].second;
			while(j<p.size() && p[j].first<=L) R=max(R,p[j++].second);
			(ret+=R-L+1)%=mo;
			i=j-1;
		}
		
	}
	
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
