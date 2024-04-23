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
string S;
const ll mo=998244353;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K>>S;
	
	if(count(ALL(S),'L')>count(ALL(S),'R')) {
		reverse(ALL(S));
		FORR(c,S) c='L'+'R'-c;
	}
	
	
	if(count(ALL(S),'L')==count(ALL(S),'R')) {
		int cur=0,num=0;
		FORR(c,S) {
			if(c=='L') {
				cur--;
				if(cur>=0) num++;
			}
			else {
				cur++;
				if(cur>0) num++;
			}
		}
		cout<<1LL*num*K%mo<<endl;
		return;
	}
	
	ll ret=0;
	x=N+5;
	int step=0;
	FOR(i,N) {
		if(S[i]=='L') step--;
		else step++;
		if(step>=1) x=min(x,i);
	}
	ll ma=1LL*step*K;
	int cur=0;
	FOR(i,N) {
		if(S[i]=='L') {
			cur--;
			if(i>=x) {
				ret+=K;
			}
			else {
				ret+=K-1;
			}
		}
		else {
			cur++;
			if(cur>ma) {
				ret+=2*K;
			}
			else {
				ll dif=ma+1-cur;
				dif=(dif+step-1)/step;
				if(dif<K) ret+=2*(K-dif);
			}
		}
	}
	cout<<ret%mo<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
