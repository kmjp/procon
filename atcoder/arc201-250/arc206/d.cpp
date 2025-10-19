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

int T,N,K;

int hoge(vector<int> V) {
	int mask;
	int N=V.size();
	int ma=0,mi=0;
	int i;
	FOR(mask,1<<N) if(__builtin_popcount(mask)>ma) {
		int pre=-1;
		FOR(i,N) if(mask&(1<<i)) {
			if(V[i]<pre) break;
			pre=V[i];
		}
		if(i==N) ma=__builtin_popcount(mask);
	}
	FOR(mask,1<<N) if(__builtin_popcount(mask)>mi) {
		int pre=100;
		FOR(i,N) if(mask&(1<<i)) {
			if(V[i]>pre) break;
			pre=V[i];
		}
		if(i==N) mi=__builtin_popcount(mask);
	}
	int ret1=0,ret2=0;
	FOR(mask,1<<N) if(__builtin_popcount(mask)==ma) {
		int pre=-1;
		FOR(i,N) if(mask&(1<<i)) {
			if(V[i]<pre) break;
			pre=V[i];
		}
		if(i==N) ret1|=mask;
	}
	FOR(mask,1<<N) if(__builtin_popcount(mask)==mi) {
		int pre=100;
		FOR(i,N) if(mask&(1<<i)) {
			if(V[i]>pre) break;
			pre=V[i];
		}
		if(i==N) ret2|=mask;
	}
	return ret1&ret2;
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	/*
	vector<int> V={1,2,3,4,5,6,7,8,9};
	do {
		cout<<__builtin_popcount(hoge(V))<<endl;
		if(__builtin_popcount(hoge(V))==0) {
			FORR(v,V) cout<<v<<" ";
			cout<<endl;
		}
	} while(next_permutation(ALL(V)));
	return ;
	*/
	
	cin>>T;
	while(T--) {
		cin>>N>>K;
		if(K>=2) {
			FOR(i,N-K) cout<<i+1<<" ";
			for(i=N;i>N-K;i--) cout<<i<<" ";
			cout<<endl;
		}
		else if(K==0) {
			if(N<=7) {
				cout<<-1<<endl;
			}
			else {
				cout<<"3 4 ";
				cout<<N<<" "<<N-1<<" "<<2<<" "<<1<<" ";
				for(i=5;i<=N-2;i++) cout<<i<<" ";
				cout<<endl;
			}
		}
		else if(K==1) {
			if(N==1) {
				cout<<1<<endl;
			}
			else if(N>=5) {
				for(i=2;i<=N-3;i++) cout<<i<<" ";
				cout<<N<<" "<<N-2<<" "<<1<<" "<<N-1<<endl;
			}
			else {
				cout<<-1<<endl;
			}
		}
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
