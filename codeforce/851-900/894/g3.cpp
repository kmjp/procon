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

int T;
int N,Q;
int A[202020];
multiset<ll> X,Y;

void add(ll x) {
	auto it=X.lower_bound(x);
	ll a=*it;
	ll b=*prev(it);
	Y.erase(Y.find(a-b));
	X.insert(x);
	Y.insert(a-x);
	Y.insert(x-b);
}

void del(ll x) {
	auto it=X.find(x);
	ll a=*next(it);
	ll b=*prev(it);
	Y.erase(Y.find(a-x));
	Y.erase(Y.find(x-b));
	X.erase(X.find(x));
	Y.insert(a-b);
	
}





void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		X={-1LL<<33,1LL<<33};
		Y={2LL<<33};
		cin>>N;
		FOR(i,N) {
			cin>>A[i];
			add(A[i]);
		}
		cin>>Q;
		while(Q--) {
			cin>>i>>x;
			i--;
			del(A[i]);
			A[i]=x;
			add(A[i]);
			ll ma=*next(X.rbegin());
			ll add=(Y.size()==2?0:*next(next(Y.rbegin())));
			cout<<ma+add<<" ";
		}
		cout<<endl;
		
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
