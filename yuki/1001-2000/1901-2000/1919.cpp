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
vector<ll> A,B,MA,MB,M1A,M1B;
const ll mo=1000000007;
const ll M=1000000000;

ll hoge(vector<ll> A,vector<ll> B) {
	vector<ll> X,Y;
	int i;
	FOR(i,A.size()) {
		X.push_back(A[i]+B[i]);
		Y.push_back(A[i]-B[i]);
	}
	sort(ALL(X));
	sort(ALL(Y));
	ll ret=0;
	int num=0;
	ll sum=0;
	FORR(x,X) {
		x=(x%mo+mo)%mo;
		(ret+=num*x-sum)%=mo;
		(sum+=x)%=mo;
		num++;
	}
	num=sum=0;
	FORR(x,Y) {
		x=(x%mo+mo)%mo;
		(ret+=num*x-sum)%=mo;
		(sum+=x)%=mo;
		num++;
	}
	return (ret%mo+mo)%mo;
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>x;
		MA.push_back(M*x);
		M1A.push_back((M+1)*x);
	}
	FOR(i,N) {
		cin>>x;
		MB.push_back(M*x);
		M1B.push_back((M+1)*x);
	}
	cout<<(hoge(M1A,M1B)-hoge(MA,M1B)+mo)%mo<<" "<<(hoge(M1A,M1B)-hoge(M1A,MB)+mo)%mo<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
