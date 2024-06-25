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
ll H[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	vector<pair<ll,int>> V;
	V.push_back({1<<30,0});
	ll sum=0;
	FOR(i,N) {
		cin>>x;
		while(V.back().first<=x) {
			y=V.size();
			sum-=1LL*V[y-1].first*(V[y-1].second-V[y-2].second);
			V.pop_back();
		}
		V.push_back({x,i+1});
		y=V.size();
		sum+=1LL*V[y-1].first*(V[y-1].second-V[y-2].second);
		cout<<sum+1<<" ";
		
	}
	cout<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
