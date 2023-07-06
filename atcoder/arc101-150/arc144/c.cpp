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

int N,K;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	
	vector<int> V;
	/*
	FOR(i,N) V.push_back(i);
	do {
		FOR(i,N) if(abs(V[i]-i)<K) break;
		if(i==N) {
			FORR(v,V) cout<<v+1<<" ";
			cout<<endl;
			break;
		}
	} while(next_permutation(ALL(V)));
	*/
	V.clear();
	if(2*K>N) {
		cout<<-1<<endl;
		return;
	}
	int did=0;
	while(N-did>=4*K) {
		FOR(i,K) V.push_back(did+K+1+i);
		FOR(i,K) V.push_back(did+1+i);
		did+=2*K;
	}
	
	if(N-did<=3*K) {
		FOR(i,N-did) {
			if(i+K<N-did) V.push_back(did+1+i+K);
			else V.push_back(did+1+(i+K)%(N-did));
		}
	}
	else {
		set<int> S;
		FOR(i,N-did) {
			S.insert(did+1+i);
		}
		FOR(i,N-did-2*K) {
			if(i<K) {
				V.push_back(did+1+i+K);
			}
			else {
				V.push_back(did+1+i-K);
			}
			S.erase(V.back());
		}
		did=N-2*K;
		FOR(i,K) {
			V.push_back(did+1+i+K);
			S.erase(V.back());
		}
		FORR(s,S) V.push_back(s);
	}
	
	
	FORR(v,V) cout<<v<<" ";
	cout<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
