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
ll H;
ll T[303030],D[303030];
vector<pair<__int128,__int128>> V;

__int128 get(ll d,ll t,ll v) {
	__int128 sum=0;
	if(v<=t) {
		sum=(1+v)*v/2;
	}
	else {
		sum=(1+t)*t/2;
		sum+=(v-t)*t;
	}
	
	return sum*d;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>H;
	map<ll,ll> M;
	FOR(i,N) {
		cin>>T[i]>>D[i];
		M[D[i]]=max(M[D[i]],T[i]);
	}
	FORR2(d,t,M) {
		while(V.size()&&V.back().first*V.back().second<d*t) V.pop_back();
		V.push_back({d,t});
	}
	reverse(ALL(V));
	
	vector<ll> S={0};
	FOR(i,V.size()-1) {
		ll tv=(V[i].first*V[i].second+V[i+1].first-1)/V[i+1].first;
		S.push_back(tv);
	}
	S.push_back(V.back().second+1);
	ll cur=0;
	ll sum=0;
	FOR(i,V.size()) {
		__int128 add=get(V[i].first,V[i].second,S[i+1]-1)-get(V[i].first,V[i].second,S[i]-1);
		if(sum+add<H) {
			sum+=add;
			continue;
		}
		ll L=S[i]-1,R=S[i+1]-1;
		while(L+1<R) {
			ll M=(L+R)/2;
			__int128 add=get(V[i].first,V[i].second,M)-get(V[i].first,V[i].second,S[i]-1);
			if(sum+add>=H) {
				R=M;
			}
			else {
				L=M;
			}
		}
		cout<<R<<endl;
		return;
	}
	cur=S.back()-1;
	__int128 a=V.back().first*V.back().second;
	cur+=(H-sum+(a-1))/a;
	cout<<cur<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
