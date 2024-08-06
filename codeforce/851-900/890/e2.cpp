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
vector<int> E[1010101];
int P[1050501];
int C[1010101];

unordered_map<int,int> M;

template <int len = 64>
ll hoge(vector<int>& V) {
	if(V.size()<=1) return 0;
	ll sum=0;
	int i;
	
	int mv=0;
	
	M.clear();
	FORR(v,V) {
		mv=max(mv,v);
		sum+=v;
		M[v]++;
	}
	if(mv*2>=sum) {
		return 1LL*mv*(sum-mv);
	}
	
	if(sum+1>len) return hoge<min(1<<21,len*2)>(V);
	
	bitset<len> B;
	B[0]=1;
	ll ma=0;
	FORR2(a,b,M) {
		int x=1;
		b++;
		while(x*2<=b) {
			B|=B<<(x*a);
			x*=2;
		}
		B|=B<<((b-x)*a);
	}
	
	FOR(i,sum+1) if(B[i]) ma=max(ma,1LL*i*(sum-i));
	
	return ma;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	for(i=1;i<N;i++) {
		cin>>P[i];
		//P[i]=1+rand()%i;
		P[i]--;
		E[P[i]].push_back(i);
	}
	
	ll ret=0;
	for(i=N-1;i>=0;i--) {
		C[i]=1;
		vector<int> V;
		FORR(e,E[i]) {
			C[i]+=C[e];
			V.push_back(C[e]);
		}
		ret+=hoge(V);
	}
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
