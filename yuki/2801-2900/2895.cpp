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
ll A[60];
map<ll,int> D;
vector<pair<ll,vector<int>>> X;
void add(ll v,int cur) {
	set<int> Y={cur};
	FORR2(a,b,X) if((a^v)<v) {
		FORR(c,b) {
			if(Y.count(c)) Y.erase(c);
			else Y.insert(c);
		}
		v=a^v;
	}
	if(v==0) {
		cout<<Y.size()<<endl;
		FORR(a,Y) cout<<a+1<<" ";
		cout<<endl;
		exit(0);
		return;
	}
	else {
		vector<int> Z;
		FORR(a,Y) Z.push_back(a);
		X.push_back({v,Z});
	}
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>A[i];
		add(A[i],i);
	}
	
	cout<<-1<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
