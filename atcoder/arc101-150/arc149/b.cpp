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
int A[303030];
int B[303030];
int R[303030];

vector<int> LIS(vector<int>& v) {
	int i,N=v.size();
	if(v.empty()) return {};
	vector<int> dp(N,1<<30),id(N);
	FOR(i,v.size()) {
		id[i] = lower_bound(dp.begin(),dp.end(),v[i]) - dp.begin();
		// id[i] = lower_bound(dp.begin(),dp.end(),v[i]+1) - dp.begin(); //‚±‚¤‚·‚é‚Æ“¯‚¶’l‚à‹–—e‚·‚é
		dp[id[i]] = v[i];
	}
	int nl = *max_element(id.begin(),id.end());
	vector<int> ret(nl+1);
	FOR(i,N) if(id[N-1-i] == nl) ret[nl--] = v[N-1-i];
	return ret;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>A[i];
		A[i]--;
	}
	FOR(i,N) {
		cin>>B[i];
		B[i]--;
	}
	int ma=0;
	FOR(i,2) {
		vector<int> R(N);
		FOR(j,N) R[A[j]]=B[j];
		ma=max(ma,N+(int)LIS(R).size());
		FOR(j,N) swap(A[j],B[j]);
	}
	cout<<ma<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
