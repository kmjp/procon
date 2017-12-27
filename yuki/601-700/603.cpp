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

ll S[30];
string T;
int L;
vector<int> V[26];
int num[26];
ll mo=1000003;

ll modpow(ll a, ll n = mo-2) {
	ll r=1;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

struct comp {
	bool operator()(const pair<ll,ll> a, const pair<ll,ll> b) const {
		return (__int128_t)a.first*b.second < (__int128_t)a.second*b.first;
	}
};

pair<ll,ll> comb(ll a,ll b) {
	ll p=1;
	ll q=1;
	int dif=0;
	while(b) {
		if(a%mo==0) {
			dif++;
			if(a/mo%mo==0) {
				dif++;
				(p*=a/mo/mo)%=mo;
			}
			else {
				(p*=a/mo)%=mo;
			}
		}
		else {
			(p*=a%mo)%=mo;
		}
		if(b%mo==0) {
			dif--;
			(q*=b/mo)%=mo;
		}
		else {
			(q*=b%mo)%=mo;
		}
		a--;
		b--;
	}
	return {p*modpow(q)%mo,dif};
}

ll hoge(ll s,vector<int> p) {
	if(p.empty()) return 1;
	sort(ALL(p));
	
	
	ll a=1,b=1;
	priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,comp> Q;
	ll sum=0;
	FORR(r,p) sum+=r;
	ll pre=s/sum;
	s%=sum;
	int dif=0;
	FORR(r,p) {
		auto c=comb(r*pre,r);
		(a*=c.first)%=mo;
		dif+=c.second;
		Q.push(make_pair(r*pre+1,r*(pre-1)+1));
	}
	while(s--) {
		auto r=Q.top();
		Q.pop();
		
		
		ll x=r.first;
		while(x%mo==0) {
			dif++;
			x/=mo;
		}
		a = x%mo*a%mo;
		x=r.second;
		while(x%mo==0) {
			dif--;
			x/=mo;
		}
		b = x%mo*b%mo;
		
		r.first++;
		r.second++;
		Q.push(r);
	}
	/*
	while(Q.size()) {
		auto a=Q.top();
		Q.pop();
		cout<<a.first<<" "<<a.second<<endl;
	}
	*/
	if(dif) return 0;
	return a*modpow(b)%mo;
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	FOR(i,26) cin>>S[i];
	cin>>T;
	L=T.size();
	
	V[T[0]-'a'].push_back(1);
	FOR(i,L-1) {
		if(T[i]==T[i+1]) V[T[i+1]-'a'].back()++;
		else V[T[i+1]-'a'].push_back(1);
	}
	FOR(i,L) num[T[i]-'a']++;
	
	__int128 ret=1;
	FOR(i,26) if(num[i]>S[i]) return _P("0\n");
	FOR(i,26) (ret*=hoge(S[i],V[i]))%=mo;
	
	cout<<(ll)ret<<endl;
}

int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
