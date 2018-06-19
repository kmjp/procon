#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N;
ll A[303030];
ll X[303030];
ll Y[303030];
ll D[303030];

ll dist(int a,int b) {
	ll x=abs(A[b]-X[a]);
	ll y=abs(Y[a]);
	return x*x*x+y*y*y;
}

ll cost(int prev,int now) {
	return D[prev]+dist(prev+1,now);
}

int hoge(int L,int R) {
	// cost(L,m) >= cost(R,m)となる最小のm
	int TL=1, TR=N+1;
	while(TR-TL>1) {
		int TM=(TR+TL)/2;
		((cost(L,TM) >= cost(R,TM))?TR:TL)=TM;
	}
	return TR;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>A[i+1];
	FOR(i,N) cin>>X[i+1];
	FOR(i,N) cin>>Y[i+1];
	
	deque<pair<int,int>> Q;
	Q.push_back({0,1});
	
	for(int now=1;now<=N;now++) {
		int pre=Q.back().first;
		
		
		if(cost(pre,now) >= cost(now-1,now)) {
			//最新の値が最適
			D[now]=cost(now-1,now);
			Q.clear();
			Q.push_back({now-1,now+1});
		}
		else {
			//現状の最適値
			D[now]=cost(pre,now);
			//最新のケースの方がいい場合、それを先頭に追加していく
			while(cost(now-1,Q[0].second)<=cost(Q[0].first,Q[0].second)) Q.pop_front();
			//これまでの範囲でコストが反転する場所
			int h=hoge(Q[0].first,now-1);
			//hからコストが反転する
			if(h<=N) Q.push_front({now-1,h});
			//反転開始するなら末尾を外す
			if(Q.size()>=2 && Q[Q.size()-2].second==now+1) Q.pop_back();
			//そうでないなら延長
			else Q.back().second++;
		}
	}
	
	cout<<D[N]<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
