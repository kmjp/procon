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


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	double phi=(1+sqrt(5))/2;
	ll A=N/(1+phi),B=N-A;
	
	for(i=-3000;i<=3000;i++) {
		ll X=A+i;
		ll Y=B-i;
		if(X<0||Y<0) continue;
		vector<int> V;
		V.push_back(3);
		while(X && V.size()<=130) {
			if(X>=Y) {
				V.push_back(3);
				X-=Y;
			}
			else if(X<Y) {
				V.push_back(4);
				Y-=X;
			}
		}
		if(Y+V.size()>130) continue;
		FOR(i,Y) V.push_back(2);
		reverse(ALL(V));
		cout<<V.size()<<endl;
		FORR(v,V) cout<<v<<endl;
		return;
	}
	assert(0);
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
