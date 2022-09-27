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

string S;
vector<int> P[26];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>S;
	FOR(i,S.size()) P[S[i]-'a'].push_back(i);
	FOR(y,26) {
		FOR(x,26) {
			cin>>k;
			int ok=1;
			FORR(v,P[y]) {
				r=lower_bound(ALL(P[x]),v+1)-P[x].begin();
				if(r<P[x].size()&&P[x][r]-v<k) ok=0;
			}
			if(ok) cout<<"Y ";
			else cout<<"N ";
		}
		cout<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
