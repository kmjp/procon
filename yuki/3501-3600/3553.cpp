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

int N,Q;
set<ll> S;

vector<int> A={1,5,7,11};
vector<int> B={1,11,19,29};

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q;
	FOR(i,N) {
		cin>>x;
		S.insert(x);
	}
	ll ret=0;
	FORR(a,S) {
		if(S.count(a*5)+S.count(a*7)+S.count(a*11)==3) ret++;
		if(S.count(a*11)+S.count(a*19)+S.count(a*29)==3) ret++;
	}
	while(Q--) {
		ll x,y;
		cin>>x>>y;
		if(x==1) {
			S.insert(y);
			FORR(a,A) if(y%a==0) {
				if(S.count(y/a*1)+S.count(y/a*5)+S.count(y/a*7)+S.count(y/a*11)==4) ret++;
			}
			FORR(a,B) if(y%a==0) {
				if(S.count(y/a*1)+S.count(y/a*11)+S.count(y/a*19)+S.count(y/a*29)==4) ret++;
			}
		}
		else {
			FORR(a,A) if(y%a==0) {
				if(S.count(y/a*1)+S.count(y/a*5)+S.count(y/a*7)+S.count(y/a*11)==4) ret--;
			}
			FORR(a,B) if(y%a==0) {
				if(S.count(y/a*1)+S.count(y/a*11)+S.count(y/a*19)+S.count(y/a*29)==4) ret--;
			}
			S.erase(y);
		}
		cout<<ret<<endl;
		
	}
	/*
	for(i=1;i<=1000;i++) S.insert(i);
	while(Q--) {
		cin>>x>>y;
		if(x==1) S.insert(y);
		else S.erase(y);
		
		FORR(a,S) if(a==1) FORR(b,S) FORR(c,S) FORR(d,S) {
			if(a<b&&b<c&&c<d) {
				int num=0;
				if((a+d)%(b+c)==0) num++;
				if((b+c)%(a+d)==0) num++;
				if((b+d)%(a+c)==0) num++;
				if((c+d)%(a+b)==0) num++;
				if(num>=4) {
					cout<<num<<" "<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
				}
			}
		}
		cout<<"!"<<endl;
	}
	*/
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
