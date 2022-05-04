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
int T[202020],Y[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	
	T[0]=1;
	FOR(i,N) {
		cin>>T[i+1]>>Y[i+1];
	}
	N++;
	multiset<ll> I,O;
	ll sum=0;
	ll ma=-1LL<<60;
	
	for(i=N-1;i>=0;i--) {
		if(T[i]==2) {
			if(Y[i]>=0) {
				sum+=Y[i];
			}
			else {
				I.insert(Y[i]);
				if(I.size()>K) {
					sum+=*I.rbegin();
					I.erase(I.find(*I.rbegin()));
				}
			}
		}
		else {
			ma=max(ma,Y[i]+sum);
			K--;
			if(K<0) break;
			if(I.size()>K) {
				sum+=*I.rbegin();
				I.erase(I.find(*I.rbegin()));
			}
			
		}
	}
	cout<<ma<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
