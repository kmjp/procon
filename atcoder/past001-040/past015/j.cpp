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
ll M;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	vector<pair<int,int>> V;
	cin>>N>>M;
	FOR(i,N) {
		cin>>j>>k>>x;
		if(x==0) {
			V.push_back({j,k-1});
		}
		else if(k==1) {
			V.push_back({j,1});
		}
		else {
			V.push_back({j*2,1});
			V.push_back({j,max(0,k-2)});
		}
	}
	sort(ALL(V));
	reverse(ALL(V));
	ll ret=0;
	FORR2(a,b,V) {
		ll x=min(M,(ll)b);
		M-=x;
		b-=x;
		ret+=1LL*a*b;
	}
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
