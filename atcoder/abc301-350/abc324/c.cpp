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
string T,S;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	vector<int> R;
	cin>>N>>T;
	FOR(i,N) {
		cin>>S;
		if(S.size()==T.size()) {
			x=0;
			FOR(j,T.size()) if(S[j]!=T[j]) x++;
			if(x<=1) R.push_back(i+1);
		}
		else if(T.size()==S.size()+1) {
			x=0;
			FORR(c,T) if(x<S.size()&&c==S[x]) x++;
			if(x==S.size()) R.push_back(i+1);
		}
		else if(T.size()+1==S.size()) {
			x=0;
			FORR(c,S) if(x<T.size()&&c==T[x]) x++;
			if(x==T.size()) R.push_back(i+1);
		}
	}
	cout<<R.size()<<endl;
	FORR(c,R) cout<<c<<" ";
	cout<<endl;
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
