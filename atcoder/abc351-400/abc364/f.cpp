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
vector<pair<int,pair<int,int>>> V;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q;
	FOR(i,Q) {
		cin>>x>>y>>k;
		V.push_back({k,{x-1,y-1}});
	}
	set<int> S;
	FOR(i,N) S.insert(i);
	ll ret=0;
	sort(ALL(V));
	FORR2(k,a,V) {
		int L=a.first,R=a.second;
		while(1) {
			auto it1=prev(S.lower_bound(L+1));
			auto it2=prev(S.lower_bound(R+1));
			
			ret+=k;
			if(it1==it2) break;
			it1++;
			S.erase(it1);
		}
	}
	if(S.size()>1) {
		cout<<-1<<endl;
	}
	else {
		cout<<ret<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
