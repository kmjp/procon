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
vector<string> S[10];
string R;
void update(string a,string b,string c) {
	string d=a+b+c;
	if(d.size()>R.size()) R=d;
	if(d.size()==R.size()&&d>R) R=d;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>s;
		S[s.size()].push_back(s);
	}
	FOR(i,9) {
		sort(ALL(S[i]));
		reverse(ALL(S[i]));
	}
	
	FOR(x,9) if(S[x].size()>=3) update(S[x][0],S[x][1],S[x][2]);
	FOR(x,9) FOR(y,9) if(x!=y&&S[x].size()>=1&&S[y].size()>=2) {
		update(S[x][0],S[y][0],S[y][1]);
		update(S[y][0],S[x][0],S[y][1]);
		update(S[y][0],S[y][1],S[x][0]);
	}
	FOR(x,9) FOR(y,9) FOR(k,9) {
		if(x==y||y==k||x==k) continue;
		if(S[x].empty()) continue;
		if(S[y].empty()) continue;
		if(S[k].empty()) continue;
		update(S[x][0],S[y][0],S[k][0]);
	}
	cout<<R<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
