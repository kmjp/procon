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
multiset<ll> L,R;
ll sum;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	FOR(i,202020) {
		L.insert(0);
		R.insert(0);
	}
	
	
	cin>>N;
	FOR(i,N) {
		ll T,D,X;
		cin>>T>>D>>X;
		if(D==0) {
			sum+=max(0LL,X-(*R.begin()+T));
			R.insert(X-T);
			ll a=*R.begin()+T;
			R.erase(R.begin());
			L.insert(-a-T);
		}
		else {
			sum+=max(0LL,(-*L.begin()-T)-X);
			L.insert(-X-T);
			ll a=-*L.begin()-T;
			L.erase(L.begin());
			R.insert(a-T);
		}
	}
	cout<<sum<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
