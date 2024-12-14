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
int A[202020];

unordered_map<int,int> M[30];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	
	sort(A,A+N);
	ll ret=0;
	FOR(i,N) {
		ll cnt[28]={};
		int cur=0;
		int f=0;
		cnt[0]=i;
		FOR(j,26) {
			if(f==0) {
				cur|=A[i]&(1<<j);
			}
			else {
				cur|=(A[i]&(1<<j))^(1<<j);
			}
			if(A[i]&(1<<j)) f=1;
			cnt[j+1]=M[j][cur];
		}
		
		cur=f=0;
		FOR(j,26) {
			if(j) {
				cur|=A[i]&(1<<(j-1));
			}
			x=cnt[j]-cnt[j+1];
			if(cur==0) ret+=1LL*x*(A[i]>>j);
			else ret+=1LL*x*((A[i]>>j)+1);
		}
		FOR(j,26) {
			M[j][A[i]&((1<<(j+1))-1)]++;
		}
		ll a=A[i];
		while(a%2==0) a/=2;
		ret+=a;
	}
	FOR(j,30) M[j].clear();
	reverse(A,A+N);
	FOR(i,N) {
		ll cnt[28]={};
		int cur=0;
		int f=0;
		cnt[0]=i;
		FOR(j,26) {
			if(f==0) {
				cur|=A[i]&(1<<j);
			}
			else {
				cur|=(A[i]&(1<<j))^(1<<j);
			}
			if(A[i]&(1<<j)) f=1;
			cnt[j+1]=M[j][cur];
		}
		
		cur=f=0;
		FOR(j,26) {
			x=cnt[j]-cnt[j+1];
			ret+=1LL*x*(A[i]>>j);
		}
		FOR(j,26) {
			M[j][A[i]&((1<<(j+1))-1)]++;
		}
	}
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
