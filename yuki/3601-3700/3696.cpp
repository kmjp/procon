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

int S,T,N;
int P[3],A[3],B[3];

ll p100[11];
ll win[1010][10];
vector<int> from[1010][10];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>S>>T>>N;
	FOR(i,3) cin>>P[i]>>A[i]>>B[i];
	
	p100[0]=1;
	FOR(i,10) p100[i+1]=p100[i]*100;
	
	win[T][0]=p100[N];
	for(i=1;i<=N;i++) {
		win[T][i]=p100[N];
		for(j=1;j<T;j++) {
			ll ma=0;
			for(x=1;x<=j;x++) {
				ll sum=0;
				FOR(k,3) {
					int nex=min(T,j-x+A[k]*x/B[k]);
					if(nex>0) sum+=win[nex][i-1]/100*P[k];
				}
				if(sum>ma) {
					from[j][i].clear();
					ma=sum;
				}
				if(sum==ma) from[j][i].push_back(x);
			}
			win[j][i]=ma;
		}
	}
	cout<<win[S][N]/p100[N-1]<<endl;
	cout<<from[S][N].size()<<endl;
	FORR(v,from[S][N]) cout<<v<<" ";
	cout<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
