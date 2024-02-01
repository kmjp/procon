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
int N,K;
int F[3030],D[3030];
int num[2020];
int dp[3030];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>K;
		ZERO(num);
		FOR(i,N) {
			cin>>F[i];
			num[F[i]]++;
		}
		vector<ll> P;
		FOR(i,N) {
			cin>>D[i];
			P.push_back(1LL*F[i]*D[i]);
		}
		sort(ALL(P));
		int mi=N;
		FOR(i,N) {
			ll L=max(1LL,1LL*F[i]*D[i]-K);
			ll R=1LL*F[i]*D[i];
			ZERO(dp);
			for(j=1;j<=2000;j++) {
				int n=num[j];
				if(j<=K+1) {
					dp[0]+=n;
				}
				else {
					ll cur=L;
					if(cur%j==0) {
						dp[0]+=n;
						cur++;
						dp[cur-L]-=n;
					}
					else if(cur%j+K>=j) {
						dp[0]+=n;
						cur=(cur/j+1)*j+1;
						dp[cur-L]-=n;
					}
					while(cur-L<=1500) {
						assert(cur%j<j-K);
						cur+=(j-K)-cur%j;
						dp[cur-L]+=n;
						cur=(cur/j+1)*j+1;
						if(cur-L>2000) break;
						dp[cur-L]-=n;
					}
				}
			}
			for(ll a=L;a<=R;a++) {
				if(a>L) dp[a-L]+=dp[a-L-1];
				if(dp[a-L]<N) continue;
				x=lower_bound(ALL(P),a+K+1)-lower_bound(ALL(P),a);
				mi=min(mi,N-x);
			}
			
			
		}
		cout<<mi<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
