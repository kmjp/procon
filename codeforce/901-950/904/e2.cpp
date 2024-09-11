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

int T,N;
ll A[3010101];
const ll mo=1000000007;
ll R[3010101];
ll L[3010101];
ll ret1[1010101];
ll ret2[1010101];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		ll ma=0;
		FOR(i,N) {
			cin>>A[i];
			ma=max(ma,A[i]);
		}
		FOR(i,N) A[2*N+i]=A[N+i]=A[i]=ma-A[i];
		ll sum=0;
		FOR(i,N) {
			sum+=max(0LL,A[i+1]-A[i]);
		}
		FOR(i,N) {
			ret1[i]=sum-max(0LL,A[i]-A[i+N-1])+A[i];
		}
		vector<pair<ll,ll>> V={{0,0}};
		ll sum2=0;
		ll sum1=0;
		ll rsum=0;
		set<int> Z;
		FOR(i,3*N) {
			if(A[i]==0) {
				R[i+1]=0;
				sum1=sum2=0;
				V={{i+1,0}};
			}
			else {
				while(V.back().second>A[i]) {
					auto p=V.back();
					auto q=V[V.size()-2];
					if(q.second>=A[i]) {
						(sum2+=1LL*(p.second-q.second)*i%mo*i)%=mo;
						(sum2-=2LL*(p.second-q.second)*i%mo*p.first)%=mo;
						(sum1-=1LL*(p.second-q.second)*p.first)%=mo;
						V.pop_back();
					}
					else {
						(sum2+=1LL*(p.second-A[i])*i%mo*i)%=mo;
						(sum2-=2LL*(p.second-A[i])*i%mo*p.first)%=mo;
						(sum1-=1LL*(p.second-A[i])*p.first)%=mo;
						V.back().second=A[i];
						break;
					}
				}
				if(V.back().second<A[i]) {
					(sum1+=1LL*(A[i]-V.back().second)*i)%=mo;
					(sum2+=1LL*(A[i]-V.back().second)*i%mo*i)%=mo;
					V.push_back({i,A[i]});
				}
				sum1=(sum1%mo+mo)%mo;
				sum2=(sum2%mo+mo)%mo;
				R[i+1]=((A[i]*(i+1)%mo*(i+1)%mo-2*sum1*(i+1)+sum2)%mo+mo)%mo;
			}
			if(A[i]==0) {
				Z.insert(i);
			}
			if(i>=N&&i<2*N&&A[i]==0) {
				(rsum+=R[i])%=mo;
			}
		}
		V={{3*N,0}};
		for(i=3*N-1;i>=0;i--) {
			if(A[i]==0) {
				L[i]=0;
				sum1=sum2=0;
				V={{i,0}};
			}
			else {
				while(V.back().second>A[i]) {
					auto p=V.back();
					auto q=V[V.size()-2];
					if(q.second>=A[i]) {
						(sum2+=1LL*(p.second-q.second)*(i+1)%mo*(i+1))%=mo;
						(sum2-=2LL*(p.second-q.second)*(i+1)%mo*p.first)%=mo;
						(sum1-=1LL*(p.second-q.second)*p.first)%=mo;
						V.pop_back();
					}
					else {
						(sum2+=1LL*(p.second-A[i])*(i+1)%mo*(i+1))%=mo;
						(sum2-=2LL*(p.second-A[i])*(i+1)%mo*p.first)%=mo;
						(sum1-=1LL*(p.second-A[i])*p.first)%=mo;
						V.back().second=A[i];
						break;
					}
				}
				if(V.back().second<A[i]) {
					(sum1+=1LL*(A[i]-V.back().second)*(i+1))%=mo;
					(sum2+=1LL*(A[i]-V.back().second)*(i+1)%mo*(i+1))%=mo;
					V.push_back({(i+1),A[i]});
				}
				sum1=(sum1%mo+mo)%mo;
				sum2=(sum2%mo+mo)%mo;
				L[i]=((A[i]*i%mo*i%mo-2*sum1*i+sum2)%mo+mo)%mo;
			}
		}
		FOR(i,N) {
			ll a=rsum;
			auto it=Z.lower_bound(N+i);
			x=*it;
			a-=R[x];
			a+=L[i];
			a+=R[i+N];
			cout<<ret1[i]<<" "<<(a%mo+mo)%mo<<"\n";
		}
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
