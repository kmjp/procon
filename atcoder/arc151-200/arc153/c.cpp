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
ll A[202020];
ll X[202020];
ll S[202020];

void out() {
	cout<<"Yes"<<endl;
	int i;
	ll sum=0;
	FOR(i,N) {
		cout<<X[i]<<" ";
		sum+=X[i]*A[i];
	}
	cout<<endl;
	assert(sum==0);
	exit(0);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	ll sum=0;
	FOR(i,N) {
		cin>>A[i];
		S[i+1]=S[i]+A[i];
		X[i]=i;
		sum+=A[i]*X[i];
	}
	
	if(sum==0) out();
	
	if(sum>0) {
		int cur=0;
		FOR(i,N) {
			cur+=A[i];
			if(cur==1) {
				ll s=sum;
				FOR(j,i+1) {
					X[j]-=s;
					sum-=s*A[j];
				}
				out();
				break;
			}
		}
		cur=0;
		for(i=N-1;i>=0;i--) {
			cur+=A[i];
			if(cur==-1) {
				ll s=sum;
				for(j=i;j<N;j++) {
					X[j]+=s;
					sum+=s*A[j];
				}
				out();
				break;
			}
		}
	}
	if(sum<0) {
		int cur=0;
		FOR(i,N) {
			cur+=A[i];
			if(cur==-1) {
				ll s=-sum;
				FOR(j,i+1) {
					X[j]-=s;
					sum-=s*A[j];
				}
				out();
				break;
			}
		}
		cur=0;
		for(i=N-1;i>=0;i--) {
			cur+=A[i];
			if(cur==1) {
				ll s=-sum;
				for(j=i;j<N;j++) {
					X[j]+=s;
					sum+=s*A[j];
				}
				out();
				break;
			}
		}
	}
	cout<<"No"<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
