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
const ll mo=1000000007;
vector<pair<ll,ll>> V;
vector<pair<__int128,__int128>> P;

bool cmp(pair<ll,ll>& L,pair<ll,ll>& R) {
	return L.first*R.second<L.second*R.first;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>x>>y;
		if(x<0) {
			x=-x;
			y=-y;
		}
		if(x||y) V.push_back({x,y});
	}
	
	
	sort(ALL(V),cmp);
	
	ll B=0;
	P.push_back({0,0});
	FOR(i,V.size()) {
		P.push_back(P.back());
		P.back().first+=V[i].first;
		P.back().second+=V[i].second;
		B+=__gcd(abs(V[i].first),abs(V[i].second));
	}
	FOR(i,V.size()) {
		P.push_back(P.back());
		P.back().first-=V[i].first;
		P.back().second-=V[i].second;
		B+=__gcd(abs(V[i].first),abs(V[i].second));
	}
	
	__int128 A=0;
	FOR(i,P.size()-1) {
		A+=P[i+1].first*P[i].second-P[i].first*P[i+1].second;
	}
	if(A<0) A=-A;
	__int128 ret=(A-B+2)/2+B;
	cout<<(ll)(ret%mo)<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
