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


int N,X;
vector<int> V;

void out() {
	FORR(v,V) cout<<v<<" ";
	cout<<endl;
	exit(0);
}

template<class CC> int LIS_num(vector<CC>& v) {
	int i,N=v.size()-1;
	vector<CC> dp(N,(numeric_limits<CC>::max)()),id(N);
	FOR(i,v.size()) dp[id[i]=lower_bound(dp.begin(),dp.end(),v[i]) - dp.begin()] = v[i];
	// FOR(i,v.size()) dp[id[i]=lower_bound(dp.begin(),dp.end(),v[i]) - dp.begin()] = v[i]-1; �������l�̘A����������ꍇ
	return *max_element(id.begin(),id.end())+1;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	/*
	vector<int> A;
	FOR(i,8) A.push_back(i+1);
	do {
		vector<int> B;
		FOR(i,A.size()-1) B.push_back(abs(A[i]-A[i+1]));
		x=LIS_num(B);
		if(x>=6) {
			cout<<x<<" ";
			FORR(a,A) cout<<a;
			cout<<endl;
		}
		
	} while(next_permutation(ALL(A)));
	return;
	*/
	
	
	cin>>N>>X;
	
	if(N%2==1&&X==(N+1)/2) {
		
		V.push_back(X);
		for(i=1;i<=N/2;i++) {
			V.push_back(X-i);
			V.push_back(X+i);
		}
		out();
	}
	if(N%2==0&&X==N/2) {
		
		for(i=1;i<=N/2;i++) {
			V.push_back(X-i+1);
			V.push_back(X+i);
		}
		out();
	}
	if(N%2==0&&X==N/2+1) {
		
		for(i=1;i<=N/2;i++) {
			V.push_back(X+i-1);
			V.push_back(X-i);
		}
		out();
	}
	vector<int> D;
	for(i=1;i<=N;i++) if(i!=X) D.push_back(i);
	V.push_back(X);
	for(int L=(D.size()-1)/2,R=L+1;L>=0;L--,R++) {
		V.push_back(D[L]);
		if(R<D.size()) V.push_back(D[R]);
	}
	
	
	out();
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
