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

ll H,W;
int N;
map<int,vector<int>> V;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	cin>>N;
	FOR(i,N) {
		cin>>y>>x;
		V[y].push_back(x-1);
	}
	W--;
	ll ret=0;
	vector<ll> X;
	ll sum=0;
	FORR2(a,b,V) {
		vector<int> C=b;
		sort(ALL(C));
		ret+=C.back()*2;
		
		ll mi=min(1LL*C.back(),W-C[0])*2;
		FOR(i,C.size()-1) mi=min(mi,(W-(C[i+1]-C[i]))*2);
		X.push_back(mi);
		sum+=mi;
	}
	//1‰ñˆÈã‰¡’f
	sort(ALL(X));
	while(X.size()>=2) {
		sum+=2*W;
		sum-=X.back();
		X.pop_back();
		sum-=X.back();
		X.pop_back();
		ret=min(ret,sum);
	}
	
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
