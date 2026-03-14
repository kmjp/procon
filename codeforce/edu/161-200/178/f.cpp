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

vector<pair<string,int>> pat;
vector<int> ret;

int T;
ll N;

pair<string,int> num(string a) {
	int i;
	FOR(i,a.size()) if(a[i]!='0') {
		swap(a[i],a[0]);
		break;
	}
	int cur=atoi(a.c_str());
	string b=to_string(cur)+to_string(cur+1);
	sort(ALL(b));
	return {b,cur};
}

void dfs(string cur,int part) {
	if(*max_element(ALL(cur))>'0') {
		pat.push_back(num(cur));
	}
	if(cur.size()<9) {
		if(part) {
			dfs(cur+'9',1);
		}
		else {
			int i;
			FOR(i,10) {
				dfs(cur+(char)('0'+i),(char)('0'+i)<cur.back());
			}
		}
	}
		
	
	
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	FOR(i,10) {
		dfs(string(1,'0'+i),0);
	}
	
	sort(ALL(pat));
	FOR(i,pat.size()) {
		if(i==0||pat[i].first!=pat[i-1].first) ret.push_back(pat[i].second);
	}
	sort(ALL(ret));
	
	cin>>T;
	while(T--) {
		cin>>N;
		cout<<lower_bound(ALL(ret),N+1)-ret.begin()<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
