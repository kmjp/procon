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

int N,K;

vector<int> A,B;
int C[202020];

using VT = vector<int>;

vector<int> Zalgo(VT s) {
	vector<int> v(1,s.size());
	for(int i=1,l=-1,r=-1;i<s.size();i++) {
		if(i<=r && v[i-l]<r-i+1) v.push_back(v[i-l]);
		else {
			l=i; r=(i>r)?i:(r+1);
			while(r<s.size() && s[r-i]==s[r]) r++;
			v.push_back((r--)-l);
		}
	}
	v.push_back(0);
	return v;
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	A.resize(N);
	B.resize(N);
	FOR(i,N) {
		cin>>A[i];
		C[A[i]]++;
	}
	FOR(i,N) {
		cin>>B[i];
		C[B[i]]--;
	}
	FOR(i,N) if(A[i]!=B[i]) break;
	if(i==N) {
		cout<<"Yes"<<endl;
		return;
	}
	FOR(i,202020) if(C[i]) {
		cout<<"No"<<endl;
		return;
	}
	if(K>N) {
		cout<<"No"<<endl;
	}
	else if(K==N) {
		FOR(i,N) if(A[i]!=B[N-1-i]) break;
		if(i==N) {
			cout<<"Yes"<<endl;
		}
		else {
			cout<<"No"<<endl;
		}
	}
	else if(K==N-1) {
		FOR(i,2) {
			reverse(ALL(A));
			vector<int> D;
			FOR(j,N) D.push_back(A[j]);
			FOR(j,N) D.push_back(B[j]);
			FOR(j,N) D.push_back(B[j]);
			auto v=Zalgo(D);
			FOR(j,N) if(v[j+N]>=N) {
				cout<<"Yes"<<endl;
				return;
			}
		}
		
		cout<<"No"<<endl;
	}
	else {
		cout<<"Yes"<<endl;
		
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
