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

ll A,B,C,D;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>A>>B>>C>>D;
	if(A==C&&B==D) {
		cout<<0<<endl;
		return;
	}
	if(A==0&&B==0) {
		cout<<-1<<endl;
		return;
	}
	if(C==0&&D==0) {
		cout<<-1<<endl;
		return;
	}
	ll g1=__gcd(abs(A),abs(B));
	ll g2=__gcd(abs(C),abs(D));
	if(g1!=g2) {
		cout<<-1<<endl;
		return;
	}
	vector<pair<int,int>> V,W;
	while(abs(A)&&abs(B)) {
		if(abs(A)>abs(B)) {
			V.push_back({1,-A/B});
			A-=A/B*B;
		}
		else {
			V.push_back({2,-B/A});
			B-=B/A*A;
		}
	}
	if(A==0) {
		if(B>0) {
			V.push_back({1,1});
			V.push_back({2,-1});
		}
		else {
			V.push_back({1,-1});
			V.push_back({2,1});
		}
	}
	else if(A<0) {
		V.push_back({2,-1});
		V.push_back({1,2});
		V.push_back({2,-1});
	}
	while(abs(C)&&abs(D)) {
		if(abs(C)>abs(D)) {
			W.push_back({1,C/D});
			C-=C/D*D;
		}
		else {
			W.push_back({2,D/C});
			D-=D/C*C;
		}
	}
	if(C==0) {
		if(D>0) {
			W.push_back({1,-1});
			W.push_back({2,1});
		}
		else {
			W.push_back({1,1});
			W.push_back({2,-1});
		}
	}
	else if(C<0) {
		W.push_back({2,1});
		W.push_back({1,-2});
		W.push_back({2,1});
	}
	
	while(W.size()) V.push_back(W.back()),W.pop_back();
	cout<<V.size()<<endl;
	FORR2(a,b,V) cout<<a<<" "<<b<<endl;

	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
