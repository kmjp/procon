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
ll A[2020],B[2020];
vector<int> R;

void go(int r) {
	R.push_back(r);
	int i;
	for(i=1;i<=r;i++) B[i]^=B[i-1];
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>A[i];
	FOR(i,N) cin>>B[i];
	
	for(i=N-1;i>=0;i--) if(A[i]!=B[i]) {
		vector<pair<ll,int>> D;
		ll dif=A[i]^B[i];;
		FOR(j,i) {
			ll a=B[j];
			FORR2(v,j,D) a=min(a,a^v);
			if(a) {
				D.push_back({a,j});
				dif=min(dif,a^dif);
			}
		}
		if(dif) {
			cout<<"No"<<endl;
			return;
		}
		
		for(j=D.size()-1;j>=0;j--) {
			ll v=A[D[j].second];
			ll tar=A[i];
			FOR(x,i+1) tar^=B[x];
			
			vector<ll> NB;
			FOR(x,j+1) {
				ll w=B[D[x].second];
				FORR(nv,NB) w=min(w,w^nv);
				NB.push_back(w);
				if(x!=j) tar=min(tar,tar^w);
			}
			if(tar) go(D[j].second+1);
		}
		
		go(i);
	}
	
	reverse(ALL(R));
	cout<<"Yes"<<endl;
	cout<<R.size()<<endl;
	FORR(r,R) cout<<r+1<<" ";
	cout<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
