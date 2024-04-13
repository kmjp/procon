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

int N,Q;
ll A[101010];
int P[101010];
int D[101010];
unordered_map<int,ll> memo[101010];
vector<int> X,Y;
vector<ll> V;
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	scanf("%d%d",&N,&Q);
	FOR(i,N) {
		scanf("%d",&x);
		A[i]=x;
	}
	FOR(i,N-1) {
		scanf("%d",&x);
		P[i+1]=x-1;
		D[i+1]=D[x-1]+1;
	}
	memo[0][0]=1LL*A[0]*A[0];
	
	while(Q--) {
		scanf("%d%d",&x,&y);
		x--,y--;
		if(x>y) swap(x,y);
		X={x};
		Y={y};
		V.clear();
		
		ll ret=0;
		while((D[x]&15)||memo[x].count(y)==0) {
			V.push_back(1LL*A[x]*A[y]);
			x=P[x];
			y=P[y];
			if(x>y) swap(x,y);
			X.push_back(x);
			Y.push_back(y);
		}
		V.push_back(memo[x][y]);
		ll sum=0;
		while(V.size()) {
			x=X.back();
			y=Y.back();
			sum+=V.back();
			if((D[x]&15)==0) memo[x][y]=sum;
			X.pop_back();
			Y.pop_back();
			V.pop_back();
		}
		cout<<sum<<"\n";
	}
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
