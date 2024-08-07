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
ll A[202020];
int Q;
ll X,Y;

ll issq(ll V) {
	if(V<0) return -1;
	ll a=sqrt(V);
	if(a*a==V) return a;
	if((a-1)*(a-1)==V) return a-1;
	if((a+1)*(a+1)==V) return a+1;
	return -1;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		map<ll,int> M;
		FOR(i,N) {
			cin>>x;
			M[x]++;
		}
		cin>>Q;
		FOR(i,Q) {
			cin>>X>>Y;
			ll D=issq(X*X-4*Y);
			
			if(D<0) {
				cout<<0<<" ";
			}
			else if(D==0) {
				x=0;
				if(X%2==0) {
					x=M[X/2];
				}
				cout<<1LL*x*(x-1)/2<<" ";
			}
			else if((X+D)%2) {
				cout<<0<<" ";
			}
			else {
				ll a=(X+D)/2;
				ll b=(X-D)/2;
				cout<<1LL*M[a]*M[b]<<" ";
			}
			
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
