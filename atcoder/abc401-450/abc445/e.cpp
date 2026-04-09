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
int N;
int A[202020];
map<int,int> M[202020];
pair<int,int> B[11202020];

const ll mo=998244353;
ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		vector<int> cand;
		FOR(i,N) {
			cin>>x;
			for(j=2;j*j<=x;j++) {
				int num=0;
				while(x%j==0) {
					num++;
					x/=j;
				}
				if(num) {
					M[i][j]=num;
					if(num>B[j].first) {
						B[j].second=B[j].first;
						B[j].first=num;
					}
					else if(num>B[j].second) {
						B[j].second=num;
					}
					cand.push_back(j);
				}
			}
			if(x>1) {
				M[i][x]=1;
				if(1>B[x].first) {
					B[x].second=B[x].first;
					B[x].first=1;
				}
				else if(1>B[x].second) {
					B[x].second=1;
				}
				cand.push_back(x);
			}
		}
		sort(ALL(cand));
		cand.erase(unique(ALL(cand)),cand.end());
		ll ret=1;
		FORR(c,cand) {
			(ret*=modpow(c,B[c].first))%=mo;
		}
		FOR(i,N) {
			ll tmp=ret;
			FORR2(a,b,M[i]) {
				if(B[a].first==b) (tmp*=modpow(modpow(a,B[a].first-B[a].second)))%=mo;
			}
			M[i].clear();
			cout<<tmp<<" ";
		}
		cout<<endl;
		
		FORR(c,cand) {
			B[c]={0,0};
		}
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
