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
ll A[202020];
ll P2[202020];
const ll mo=1000000007;

ll p2[202020*80];

int ok(ll a,int a2,ll b,int b2) {
	if(b2>=30) return 1;
	if((b<<b2)>=a) return 1;
	return 0;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	p2[0]=1;
	for(i=1;i<=202020*70;i++) p2[i]=p2[i-1]*2%mo;
	
	cin>>T;
	while(T--) {
		cin>>N;
		ll sum=0;
		vector<int> V;
		FOR(i,N) {
			cin>>A[i];
			P2[i]=0;
			while(A[i]%2==0) {
				A[i]/=2;
				P2[i]++;
			}
			sum+=A[i]*p2[P2[i]]%mo;
			while(V.size()) {
				x=V.back();
				if(ok(A[x],P2[x],A[i],P2[i])) {
					sum-=A[x]*p2[P2[x]]%mo;
					sum-=A[i]*p2[P2[i]]%mo;
					P2[i]+=P2[x];
					P2[x]=0;
					sum+=A[x]*p2[P2[x]]%mo;
					sum+=A[i]*p2[P2[i]]%mo;
					V.pop_back();
				}
				else {
					break;
				}
				sum%=mo;
			}
			V.push_back(i);
			sum=(sum%mo+mo)%mo;
			cout<<sum<<" ";
		}
		cout<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
