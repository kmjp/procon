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
ll M;
ll A[202020],B[202020];
ll D[202020],C[202020];
int Q;
ll X;
__int128 get(int id,ll v) {
	if(id<0||id>=N) return 1LL<<60;
	__int128 num=0;
	if(v>=A[id]) {
		if(B[id]==0) num=M;
		else num=min(M,(v-A[id])/B[id]+1);
	}
	
	__int128 pre=(__int128)A[id]*num+(__int128)B[id]*num*(num-1)/2;
	__int128 suf=(__int128)A[id]*M+(__int128)B[id]*M*(M-1)/2-pre;
	__int128 ret=(2*num-M)*v-pre+suf;
	return ret;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,N) {
		cin>>A[i]>>B[i];
	}
	cin>>Q>>X;
	vector<pair<ll,int>> V;
	FOR(i,N) {
		cin>>C[i];
		
		if(i==0) {
			V.push_back({0,0});
		}
		else {
			while(V.size()) {
				int pre=V.back().second;
				ll cur=1LL<<60;
				for(j=59;j>=0;j--) if(get(i,cur-(1LL<<j))<get(pre,cur-(1LL<<j))) cur-=(1LL<<j);
				if(V.back().first<cur) {
					V.push_back({cur,i});
					break;
				}
				V.pop_back();
			}
		}
	}
	
	
	while(Q--) {
		x=lower_bound(ALL(V),make_pair(X+1,0))-V.begin()-1;
		cout<<V[x].second+1<<" ";
		
		X+=C[V[x].second];
		
	}
	cout<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
