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

int T,M,K;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	/*
	map<int,int> ok;
	int N;
	int mask;
	cin>>N;
	FOR(mask,1<<N) {
		set<int> S;
		FOR(x,N) if(mask&(1<<x)) {
			FOR(y,N) if(mask&(1<<y)) {
				S.insert((x+y)%N);
			}
		}
		if(ok.count(S.size())==0) ok[S.size()]=mask;
	}
	FORR2(a,mask,ok) if(a&&N%a&&a%2==0) {
		cout<<a<<" ";
		FOR(i,N) if(mask&(1<<i)) cout<<i<<" ";
		cout<<endl;
	}
	return;
	
	*/
	cin>>T;
	while(T--) {
		cin>>M>>K;
		
		if(K%2==1) {
			cout<<"Yes"<<endl;
			cout<<K/2+1<<endl;
			FOR(i,K/2+1) cout<<i<<" ";
			cout<<endl;
			continue;
		}
		if(M%K==0) {
			cout<<"Yes"<<endl;
			cout<<K<<endl;
			FOR(i,K) cout<<i*(M/K)<<" ";
			cout<<endl;
			continue;
		}
		if(K>=6) {
			cout<<"Yes"<<endl;
			cout<<K/2<<endl;
			FOR(i,K/2-1) cout<<i<<" ";
			cout<<K/2<<endl;
			continue;
		}
		cout<<"No"<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
