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

int N,L,K;
ll A[702020],C[702020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>L>>K;
	FOR(i,N) {
		cin>>A[i+1];
		cin>>C[i+1];
	}
	A[N+1]=L;
	N++;
	ll ssum=K;
	deque<pair<ll,ll>> cand;
	cand.push_front({0,K});
	
	ll sum=0;
	FOR(i,N) {
		ll d=A[i+1]-A[i];
		while(d) {
			if(ssum==0) {
				cout<<-1<<endl;
				return;
			}
			ll x=min(cand[0].second,d);
			cand[0].second-=x;
			d-=x;
			ssum-=x;
			sum+=1LL*cand[0].first*x;
			if(cand[0].second==0) cand.pop_front();
		}
		while(cand.size()&&cand.back().first>=C[i+1]) {
			ssum-=cand.back().second;
			cand.pop_back();
		}
		cand.push_back({C[i+1],K-ssum});
		ssum=K;
	}
	cout<<sum<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
