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
int A[202020];
int L,R;
ll ret,lef;
const ll mo=1000000007;
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	ll cur=1;
	FOR(i,N) {
		cin>>A[i];
		cur=min(cur*A[i],2LL*N+1);
	}
	while(L<N&&A[L]==1) lef++,L++;
	
	R=N;
	while(L<R&&A[R-1]==1) lef++,R--;
	
	if(L==R) {
		cout<<lef<<endl;
		return;
	}
	
	if(cur>=2*N) {
		ret=1;
		for(i=L;i<R;i++) ret=ret*A[i]%mo;
		cout<<(ret+lef)%mo<<endl;
	}
	else {
		vector<pair<ll,ll>> V;
		for(i=L;i<R;i++) {
			if(A[i]==1) {
				if(V.back().first==2) V.push_back({1,0});
				V.back().second++;
			}
			else {
				if(V.empty()||V.back().first==1) V.push_back({2,1});
				V.back().second*=A[i];
			}
		}
		ll ma=0;
		int mask,M=V.size()/2;
		FOR(mask,1<<M) {
			int cur=V[0].second;
			ll pat=0;
			FOR(i,M) {
				if(mask&(1<<i)) {
					cur*=V[i*2+2].second;
					
				}
				else {
					pat+=cur+V[i*2+1].second;
					cur=V[i*2+2].second;
				}
			}
			ma=max(ma,cur+pat+lef);
		}
		cout<<ma<<endl;
		
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
