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
ll K;

int P[202020];
vector<int> ret[5][31];
ll ma[202020],mi[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	for(i=1;i<=200000;i++) {
		ma[i]=1LL*i*(i+1)*(2*i+1)/6;
		mi[i]=1LL*i*(i+1)*(i+2)/6;
	}
	
	if(K<mi[N]||K>ma[N]) {
		cout<<"No"<<endl;
		return;
	}
	
	for(i=1;i<=4;i++) {
		vector<int> V;
		FOR(j,i) V.push_back(j+1);
		do {
			int sum=0;
			FOR(j,i) {
				sum+=(j+1)*V[j];
			}
			ret[i][sum]=V;
		} while(next_permutation(ALL(V)));
	}
	
	if(N<=4) {
		if(ret[N][K].empty()) {
			cout<<"No"<<endl;
		}
		else {
			cout<<"Yes"<<endl;
			FOR(i,N) cout<<ret[N][K][i]<<" ";
			cout<<endl;
			FOR(i,N) cout<<i+1<<" ";
			cout<<endl;
		}
		return;
	}
	
	
	int L=1,R=N;
	for(i=N;i>=5;i--) {
		ll a=1LL*i*(i+1)/2;
		if(K-a>=mi[i-1]&&K-a<=ma[i-1]) {
			K-=a;
			P[N-i]=R--;
			continue;
		}
		a=1LL*i*i;
		assert(K-a>=mi[i-1]&&K-a<=ma[i-1]);
		K-=a;
		P[N-i]=L++;
	}
	FOR(i,4) P[N-4+i]=ret[4][K][i]+L-1;
	
	
	
	
	cout<<"Yes"<<endl;
	FOR(i,N) cout<<P[i]<<" ";
	cout<<endl;
	FOR(i,N) cout<<i+1<<" ";
	cout<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
