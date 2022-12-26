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

int N,K,L;
int A[5525];
int dp[5525][5525];

template<class V,int MA> class BIT_2d {
public:
	V val[1<<MA][1<<MA];
	BIT_2d(){ZERO(val);};
	V total(int x,int y) {
		V s=0;
		for(int i=x+1;i>0;i-=i&-i) for(int j=y+1;j>0;j-=j&-j) s+=val[i-1][j-1];
		return s;
	}
	void update(int x,int y,V v) {
		for(int i=x+1;i<=1<<MA;i+=i&-i) for(int j=y+1;j<=1<<MA;j+=j&-j) val[i-1][j-1]+=v;
	}
};
BIT_2d<int,12> bit;

int R[5525];
int ret[2525][2525];
vector<pair<int,int>> cand[2525];

int get(int L,int R) {
	return bit.total(R+1,R+1)-bit.total(R+1,L)-bit.total(L,R+1)+bit.total(L,L);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K>>L;
	FOR(i,N) cin>>A[i];
	
	MINUS(dp);
	FOR(x,N) {
		R[x]=N;
		multiset<int> S;
		for(y=x;y<N;y++) {
			S.insert(A[y]);
			if(S.size()>K) S.erase(S.find(*S.rbegin()));
			if(S.size()==K) {
				dp[x][y]=*S.rbegin();
				cand[dp[x][y]].push_back({x,y});
			}
		}
	}
	for(x=1;x<=N;x++) {
		FORR2(l,r,cand[x]) bit.update(l+1,r+1,1);
		FOR(i,N) {
			while(get(i,R[i]-1)>=L) {
				R[i]--;
				ret[i][R[i]]=x;
			}
		}
	}
	/*
	FOR(x,N) {
		for(y=x;y<N;y++) cout<<ret[x][y]<<" ";
		cout<<endl;
	}
	*/
	int Q;
	cin>>Q;
	while(Q--) {
		cin>>x>>y;
		cout<<ret[x-1][y-1]<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
