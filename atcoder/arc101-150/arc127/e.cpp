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


int A,B;
int num[5050];
const ll mo=998244353;
vector<int> V;
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>A>>B;
	int cur=1;
	
	FOR(i,A+B) {
		cin>>x;
		if(x==1) {
			V.push_back(cur++);
		}
		else {
			V.pop_back();
		}
	}
	
	ll from[5050]={1};
	FORR(v,V) {
		ll to[5050]={};
		ll ret=0;
		FOR(i,v+1) {
			to[i]=ret;
			(ret+=from[i])%=mo;
		}
		swap(from,to);
	}
	ll ret=0;
	FOR(i,A+1) ret+=from[i];
	cout<<ret%mo<<endl;
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
