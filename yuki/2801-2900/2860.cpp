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

int T,N,K,X;
ll H[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>K>>X;
		int mi=1<<30;
		FOR(i,N) {
			cin>>H[i];
		}
		FOR(i,N-1) {
			H[i]=H[i+1]-H[i];
			if(H[i]%X) break;
			H[i]/=X;
		}
		if(i<N-1) {
			cout<<"No"<<endl;
			continue;
		}
		FOR(i,K) {
			if(i==N-1) continue;
			ll sum=0;
			for(j=i;j<N-1;j+=K) sum+=H[j];
			if(i==K-1) {
				if((N-1)%K==i) continue;
				if(sum>=0) H[i]-=sum;
			}
			else if((N-1)%K==i) {
				if(sum<=0) H[j-K]-=sum;
			}
			sum=0;
			for(j=i;j<N-1;j+=K) {
				sum+=H[j];
				if(sum>0) break;
			}
			if(sum!=0) break;
		}
		if(i==K) {
			cout<<"Yes"<<endl;
		}
		else {
			cout<<"No"<<endl;
		}
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
