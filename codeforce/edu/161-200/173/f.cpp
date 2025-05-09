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

int N,Q;
int A[101010];
const ll mo=998244353;

int S[101010][51];

pair<int,ll> add(pair<int,ll> a,pair<int,ll> b) {
	if(a.first<b.first) return a;
	if(a.first>b.first) return b;
	return {a.first,(a.second+b.second)%mo};
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	
	cin>>N>>Q;
	FOR(i,N) {
		cin>>A[i];
		FOR(j,51) S[i+1][j]=S[i][j];
		S[i+1][A[i]]++;
	}
	while(Q--) {
		int L,R;
		cin>>L>>R;
		L--;
		
		pair<int,ll> from[64],to[64];
		FOR(i,64) from[i]={1<<20,0};
		FOR(i,51) {
			x=S[R][i]-S[L][i];
			if(i==0&&x) {
				from[0]=add(from[0],{1,x});
			}
			else if(x>=2) {
				from[0]=add(from[0],{2,1LL*x*(x-1)/2});
			}
			else if(x) {
				FOR(j,64) to[j]=from[j];
				FOR(j,64) to[j^i]=add(to[j^i],{from[j].first+1,from[j].second});
				to[i]=add(to[i],{1,1});
				swap(from,to);
			}
		}
		if(from[0].first>=1<<20) {
			cout<<-1<<endl;
		}
		else {
			cout<<R-L-from[0].first<<" "<<from[0].second%mo<<endl;
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
