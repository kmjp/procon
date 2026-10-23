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

ll N;
ll A[202020],B[202020];

bool cmp(pair<ll,ll> L,pair<ll,ll> R) {
	return (__int128)L.first*R.second<(__int128)L.second*R.first;
}

pair<ll,ll> hoge() {
	
	vector<pair<ll,ll>> P;
	int i;
	ll LA=0,RA=0;
	FOR(i,N) if(A[i]) {
		P.push_back({-B[i],A[i]});
		LA+=A[i];
	}
	sort(ALL(P),cmp);
	pair<ll,ll> pq={1,1};
	FORR2(b,a,P) {
		ll d1=LA-RA;
		LA-=a;
		RA+=a;
		ll d2=LA-RA;
		
		if(d1<=0&&d2>=0||d1>=0&&d2<=0) {
			pq={-b,a};
			break;
		}
		
	}
	
	ll p=0,q=pq.second;
	FOR(i,N) p+=abs(B[i]*pq.second-A[i]*pq.first);
	
	ll g=__gcd(p,q);
	return {p/g,q/g};
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>A[i];
	FOR(i,N) cin>>B[i];
	FOR(i,N) {
		if(A[i]<0) A[i]=-A[i],B[i]=-B[i];
	}
	auto ret1=hoge();
	FOR(i,N) {
		swap(A[i],B[i]);
		if(A[i]<0) A[i]=-A[i],B[i]=-B[i];
	}
	auto ret2=hoge();
	
	if((__int128)ret1.first*ret2.second<(__int128)ret2.first*ret1.second) ret2=ret1;
	cout<<ret2.first<<" "<<ret2.second<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
