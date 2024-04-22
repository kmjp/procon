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

ll P,Q,N,L,R;

__int128 hoge(__int128 L,__int128 R) {
	if(L==0) L++;
	R=min(R,(__int128)N);
	if(R<L) return 0;
	__int128 sum=R-L+1;
	
	L=(L+Q-1)/Q*P;
	R=R/Q*P+P-1;
	return sum+hoge(L,R);
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>P>>Q>>N>>L>>R;
	ll num=R-L;
	L++;
	
	__int128 cur=0;
	vector<ll> V;
	while(1) {
		L--;
		if(L==0) break;
		assert(cur%Q==0);
		ll a=cur/Q*P;
		ll b=cur/Q*P+(P-1);
		for(i=60;i>=0;i--) if(hoge(a,b-(1LL<<i))>=L) b-=(1<<i);
		
		L-=hoge(a,b-1);
		V.push_back(b-a);
		cur=b;
	} 
	
	cout<<(ll)cur<<endl;
	
	while(num--) {
		if(cur%Q==0&&cur/Q*P<=N) {
			V.push_back(0);
			cur=cur/Q*P;
		}
		else {
			while(V.back()==P-1||cur+1>N) {
				V.pop_back();
				cur=cur/P*Q;
			}
			V.back()++;
			cur++;
		}
		cout<<(ll)cur<<endl;
		
	}
}

int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
