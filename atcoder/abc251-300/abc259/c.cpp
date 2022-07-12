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


string S,T;
vector<pair<char,int>> X,Y;

vector<pair<char,int> > RLE(string S) {
	vector<pair<char,int> > V;
	FORR(r,S) {
		if(V.size() && V.back().first==r) V.back().second++;
		else V.push_back({r,1});
	}
	return V;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>S>>T;
	
	auto X=RLE(S);
	auto Y=RLE(T);
	
	int ok=1;
	if(X.size()!=Y.size()) {
		ok=0;
	}
	else {
		FOR(i,X.size()) {
			if(X[i].first!=Y[i].first) {
				ok=0;
			}
			if(X[i].second>Y[i].second) {
				ok=0;
			}
			if(X[i].second<Y[i].second&&X[i].second==1) {
				ok=0;
			}
			
		}
	}
	if(ok) {
		cout<<"Yes"<<endl;
	}
	else {
		cout<<"No"<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
