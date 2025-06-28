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

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	/*
	vector<int> A,B,C;
	cin>>N;
	FOR(i,N) A.push_back(i);
	FOR(i,N) B.push_back(i);
	do {
		C.clear();
		FOR(i,N) C.push_back(A[i]+B[i]);
		sort(ALL(C));
		FOR(i,N-1) if(C[i+1]!=C[i]+1) break;
		if(i==N-1) {
			FOR(i,N) cout<<A[i];
			cout<<endl;
			FOR(i,N) cout<<B[i];
			cout<<endl;
			int sum=3*(N*(N-1))/2/N;
			FOR(i,N) cout<<(sum-A[i]-B[i]);
			cout<<endl;
			
			break;
		}
	} while(next_permutation(ALL(B)));
	cout<<endl;
	*/
	
	cin>>T;
	while(T--) {
		cin>>N>>K;
		
		if(N==1) {
			if(K==1) {
				cout<<"YES"<<endl;
				cout<<1<<endl;
			}
			else {
				cout<<"NO"<<endl;
			}
			continue;
		}
		if(K==1) {
			cout<<"NO"<<endl;
			continue;
		}
		ll sum=1;
		for(i=1;i<=N;i++) sum=min(sum*i,(ll)K+6);
		
		if(K%2==0) {
			if(sum<K) {
				cout<<"NO"<<endl;
				continue;
			}
			vector<int> V;
			FOR(i,N) V.push_back(i+1);
			cout<<"YES"<<endl;
			while(K) {
				K-=2;
				FORR(v,V) cout<<v<<" ";
				cout<<endl;
				FORR(v,V) cout<<N+1-v<<" ";
				cout<<endl;
				
				
				next_permutation(ALL(V));
			}
		}
		else {
			if(N%2==0) {
				cout<<"NO"<<endl;
				continue;
			}
			if(3+(sum-6)<K) {
				cout<<"NO"<<endl;
				continue;
			}
			vector<int> A,B,C;
			FOR(i,N) A.push_back(i+1);
			B=A;
			rotate(B.begin(),B.begin()+N/2+1,B.end());
			ll sum=1LL*N*(N+1)/2*3/N;
			FOR(i,N) C.push_back(sum-A[i]-B[i]);
			
			vector<int> D,E;
			FOR(i,N) {
				D.push_back(i+1);
				E.push_back(N+1-D[i]);
			}
			cout<<"YES"<<endl;
			FORR(v,A) cout<<v<<" ";
			cout<<endl;
			FORR(v,B) cout<<v<<" ";
			cout<<endl;
			FORR(v,C) cout<<v<<" ";
			cout<<endl;
			K-=3;
			while(K) {
				if(A!=D&&B!=D&&C!=D&&A!=E&&B!=E&&C!=E) {
					K-=2;
					FORR(v,D) cout<<v<<" ";
					cout<<endl;
					FORR(v,E) cout<<v<<" ";
					cout<<endl;
				}
				
				next_permutation(ALL(D));
				FOR(i,N) E[i]=N+1-D[i];
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
