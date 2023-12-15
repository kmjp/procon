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

int N,Q;
ll A[303030];


auto compare = [](const pair<ll,ll> a, const pair<ll,ll> b) { return a.first*b.second < b.first*a.second; };
multiset<pair<ll,ll>, decltype(compare)> V{compare};

pair<ll,ll> get(int L,int R) {
	ll p=A[R]-A[L];
	ll q=R-L;
	ll g=__gcd(p,q);
	p/=g;
	q/=g;
	return {p,q};
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	set<int> S;
	cin>>N>>Q;
	FOR(i,N) {
		cin>>x;
		A[i+1]=A[i]+x;
	}
	while(Q--) {
		cin>>i;
		if(i==1) {
			cin>>x;
			
			if(S.count(x)) {
				auto it=S.find(x);
				if(it!=S.begin()) {
					V.erase(V.find(get(*prev(it),x)));
				}
				if(next(it)!=S.end()) {
					V.erase(V.find(get(x,*next(it))));
				}
				if(it!=S.begin()&&next(it)!=S.end()) {
					V.insert(get(*prev(it),*next(it)));
				}
				S.erase(x);
			}
			else {
				S.insert(x);
				auto it=S.find(x);
				if(it!=S.begin()) {
					V.insert(get(*prev(it),x));
				}
				if(next(it)!=S.end()) {
					V.insert(get(x,*next(it)));
				}
				if(it!=S.begin()&&next(it)!=S.end()) {
					V.erase(V.find(get(*prev(it),*next(it))));
				}
			}
			
		}
		else {
			auto p=*V.rbegin();
			cout<<p.first<<" "<<p.second<<endl;
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
