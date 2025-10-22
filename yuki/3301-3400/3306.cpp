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

int H,W;
ll A[3030][3030];


template<class V> pair<ll, vector<int>> Hungarian(vector<vector<V>>& A) {
	const int MV=1510;
	int match[MV+1], vis[MV+1];
	
	int N=A.size();
	assert(A[0].size()==N && MV>=2*N);
	int y,x,i,j;
	vector<V> R(N),C(N,0);
	FOR(y,N) R[y]=*max_element(ALL(A[y]));
	
	MINUS(match);
	while(1) {
		retry:
		FOR(y,N) if(match[y]==-1) break;
		if(y==N) break;
		
		int tar=y;
		
		MINUS(vis);
		queue<int> Q;
		vector<int> S,T;
		Q.push(tar);
		
		FOR(y,N) T.push_back(y);
		ret2:
		while(Q.size()) {
			y=Q.front();
			Q.pop();
			if(vis[y]==-1) S.push_back(y);
			vis[y]=0;
			vector<int> T2;
			FORR(x,T) {
				if(A[y][x]==R[y]+C[x]) {
					vis[N+x]=y;
					if(match[N+x]==-1) { //Œð‘ã˜H‚ð’£‚é
						int cur=N+x;
						while(1) {
							int nex=match[y];
							match[cur]=y;
							match[y]=cur;
							if(y==tar) goto retry;
							cur=nex;
							y=vis[cur];
						}
					}
					Q.push(match[N+x]);
				}
				else T2.push_back(x);
			}
			swap(T,T2);
		}
		//Œð‘ã˜H‚ª–³‚¢
		V dif=numeric_limits<V>::max();
		int ty=-1,tx=-1;
		FORR(y,S) FORR(x,T) if(R[y]+C[x]-A[y][x]<dif) {
			dif=R[y]+C[x]-A[y][x];
			ty=y,tx=x;
		}
		FOR(i,N) if(vis[i]>=0) R[i]-=dif;
		FOR(i,N) if(vis[i+N]>=0) C[i]+=dif;
		Q.push(ty);
		goto ret2;
	}
	
	vector<int> P;
	ll ret=0;
	FOR(y,N) P.push_back(match[y]-N), ret+=A[y][match[y]-N];
	return {ret,P};
	
}



void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	FOR(y,H) FOR(x,W) cin>>A[y][x];
	
	
	if(W==1) {
		ll ret=0;
		FOR(i,H/2) ret+=A[H-1-i][0]-A[i][0];
		cout<<ret<<endl;
		return;
	}
	
	vector<vector<ll>> B;
	B.resize(H/2);
	FORR(b,B) b.resize(H/2);
	
	FOR(i,H/2) FOR(j,H/2) {
		FOR(x,W) B[i][j]=max(B[i][j],A[H-1-j][x]-A[i][x]);
	}
	cout<<Hungarian(B).first<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
