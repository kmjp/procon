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

int P,A,B;
ll mo;
ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>P>>A>>B;
	
	if(P==2) {
		cout<<"Yes"<<endl;
		cout<<"1 1"<<endl;
		return;
	}
	
	mo=P;
	set<int> S;
	if(A>1) S.insert(A);
	if(B>1) {
		if(modpow(B)!=A) S.insert(B);
	}
	
	FORR(x,S) {
		ll cur=1;
		FOR(i,P-2) {
			cur=cur*x%mo;
			if(cur==1) break;
		}
		if(i==P-2) {
			cout<<"Yes"<<endl;
			cur=1;
			FOR(i,P) {
				cout<<cur<<" ";
				cur=cur*x%mo;
			}
			cout<<endl;
			return;
		}
	}
	if(S.size()<=1) {
		cout<<"No"<<endl;
		return;
	}
	int x1=*S.begin();
	int x2=*S.rbegin();
	int r1=modpow(x1);
	int r2=modpow(x2);
	set<ll> T[2];
	vector<ll> V[2];
	
	FOR(j,2) {
		ll cur=1;
		V[j].push_back(1);
		FOR(i,P) {
			if(j==0) cur=cur*x1%mo;
			else cur=cur*x2%mo;
			if(cur==1) break;
			T[j].insert(cur);
			V[j].push_back(cur);
		}
	}
	
	FOR(k,2) {
		for(int tl=2;tl<=V[0].size();tl+=2) if((P-1)%tl==0) {
			int tw=(P-1)/tl;
			if(tw>V[1].size()) continue;
			
			vector<ll> R;
			set<ll> A;
			ll cur=1;
			FOR(y,tl) {
				R.push_back(cur);
				A.insert(cur);
				if(y<tl-1) cur=cur*x1%mo;
			}
			cur=cur*x2%mo;
			for(y=tl-1;y>=0;y--) {
				if(R.size()!=A.size()) break;
				FOR(x,tw-1) {
					R.push_back(cur);
					A.insert(cur);
					if(R.size()!=A.size()) break;
					if(x<tw-2) {
						if(y%2==1) {
							cur=cur*x2%mo;
						}
						else {
							cur=cur*r2%mo;
						}
					}
				}
				if(y) cur=cur*r1%mo;
			}
			if(A.size()==P-1) {
				R.push_back(1);
				cout<<"Yes"<<endl;
				FORR(r,R) cout<<r<<" ";
				cout<<endl;
				return;
			}
			
		}
		swap(x1,x2);
		swap(r1,r2);
		swap(T[0],T[1]);
		swap(V[0],V[1]);
	}
	
	cout<<"No"<<endl;
	
	
	
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
