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


ll N;
int S;
int vis[51];
vector<int> create_factorial(int len, ll id) {
	vector<int> ret,cand;
	vector<ll> fact(1,1);
	int i;
	FOR(i,len) {
		cand.push_back(i);
		fact.push_back(fact.back()*(i+1));
	}
	
	FOR(i,len) {
		int num=id/fact[len-1-i];
		id%=fact[len-1-i];
		ret.push_back(cand[num]);
		cand.erase(cand.begin()+num);
	}
	return ret;
}

ll factorial_number(vector<int> V) {
	int len=V.size();
	vector<ll> fact(1,1);
	vector<int> vis(len,1);
	int i,j;
	FOR(i,len) fact.push_back(fact.back()*(i+1));
	
	ll ret=0;
	FOR(i,len) {
		int num=0;
		FOR(j,V[i]) num+=vis[j];
		vis[V[i]]=0;
		ret+=num*fact[len-1-i];
		
	}
	return ret;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>S;
	auto a=create_factorial(S,N);
	auto b=a;
	
	FOR(i,S) b[a[i]]=i;
	cout<<factorial_number(b)<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
