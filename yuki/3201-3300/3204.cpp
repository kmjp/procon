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

int T;
map<vector<int>,vector<int>> M;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	for(i=1;i*i<=1000000000;i++) {
		string a=to_string(i*i);
		vector<int> C(9);
		FORR(c,a) if(c>'0') C[c-'1']++;
		M[C].push_back(i*i);
	}
	cin>>T;
	while(T--) {
		cin>>s;
		sort(ALL(s));
		vector<int> C(9);
		FORR(c,s) if(c>'0') C[c-'1']++;
		int ret=1<<30;
		
		FORR(v,M[C]) {
			string t=to_string(v);
			if(t.size()>s.size()) break;
			while(t.size()<s.size()) t+="0";
			sort(ALL(t));
			if(s==t) {
				ret=v;
				break;
			}
		}
		
		if(ret>=1<<30) ret=-1;
		cout<<ret<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
