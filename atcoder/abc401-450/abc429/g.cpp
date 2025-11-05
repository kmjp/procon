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
ll N,M,A,B,X;
ll mo;

ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

ll hoge(ll V, ll step) {
	if(step==0) return 0;
	if(step==1) return 1;
	if(step%2) return (1+V*hoge(V,step-1))%mo;
	ll a=hoge(V,step/2);
	a=(1+modpow(V,step/2))*a%mo;
	return a;
}
	

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>M>>A>>B>>X>>mo;
		
		if(A==0) {
			ll a=modpow(X,B);
			cout<<a*N%mo<<endl;
			continue;
		}
		ll g=__gcd(A,M);
		ll m=modpow(X,B%g);
		X=modpow(X,g);
		B/=g;
		A/=g;
		M/=g;
		ll ret=0;
		ret=(N/M)*hoge(X,M)%mo;
		N%=M;
		
		if(N<=100000) {
			FOR(i,N) {
				ll a=(A*i+B)%M;
				(ret+=modpow(X,a))%=mo;
			}
		}
		else if(M/A>=100000) {
			ll cur=B;
			while(N) {
				ll step=min((M-cur+A-1)/A,N);
				
				(ret+=modpow(X,cur)*hoge(modpow(X,A),step))%=mo;
				N-=step;
				cur=(cur+step*A)%M;
			}
		}
		else {
			vector<pair<int,int>> V;
			for(i=0;i<=10000;i++) {
				ll a=(A*i+B)%M;
				V.push_back({a,i});
			}
			sort(ALL(V));
			V.push_back(V[0]);
			V.back().first+=M;
			ll mi=1<<30;
			int d=0;
			FOR(i,V.size()-1) if(V[i+1].first-V[i].first<abs(mi)) {
				if(V[i+1].second>V[i].second) {
					mi=V[i+1].first-V[i].first;
					d=V[i+1].second-V[i].second;
				}
				else {
					mi=V[i].first-V[i+1].first;
					d=V[i].second-V[i+1].second;
				}
			}
			
			ll ami=abs(mi);
			ll Xa=modpow(X,ami);
			FOR(i,min((int)N,d)) {
				ll num=N/d+(i<N%d);
				ll cur=(A*i+B)%M;
				if(mi<0) {
					cur=((A*i+(num-1)*mi+B)%M+M)%M;
				}
				while(num) {
					ll step=min((M-cur+ami-1)/ami,num);
					
					(ret+=modpow(X,cur)*hoge(Xa,step))%=mo;
					num-=step;
					cur=(cur+step*ami)%M;
				}
			}
		}
		
		ret=ret*m%mo;
		cout<<ret<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
