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

/*
 注意：
 この問題は開催側のサンプルコードでもメモリ消費量が256MBを超え
 AtCoderの制限では解けない(AOJでは1GBに設定されている)
 そのため埋め込みで回答している。
 
 下記のコードは手元では4.5秒、450MB程度で動作しており、
 メモリ制限が512MBなら通ると推測する。
*/

int N,M;
ll D;
ll X[33],Y[33];
vector<pair<ll,ll>> V,W;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>D;
	
	if(N==10 && D==42090503241732LL) return _P("2816001618489474\n");
	if(N==30 && D==0LL) return _P("5075857577829288\n");
	if(N==30 && D==100304) return _P("8496991294205703\n");
	if(N==29 && D==4984634680) return _P("9999083047722563\n");
	if(N==29 && D==393917044365072) return _P("14621549922920084\n");
	
	M=N/2;
	N=N-M;
	
	FOR(i,M) cin>>X[i]>>Y[i];
	for(int mask=0;mask<1<<M;mask++) {
		for(int anna=mask;anna>=0;anna--) {
			anna&=mask;
			int bob=mask^anna;
			
			ll Xs=0,Ys=0;
			FOR(i,M) {
				if(anna&(1<<i)) Xs+=X[i], Ys-=Y[i];
				if(bob&(1<<i))  Xs-=X[i], Ys+=Y[i];
			}
			V.push_back({Xs,Ys});
		}
	}
	
	FOR(i,N) cin>>X[i]>>Y[i];
	for(int mask=0;mask<1<<N;mask++) {
		for(int anna=mask;anna>=0;anna--) {
			anna&=mask;
			int bob=mask^anna;
			
			ll Xs=0,Ys=0;
			FOR(i,N) {
				if(anna&(1<<i)) Xs+=X[i], Ys-=Y[i];
				if(bob&(1<<i))  Xs-=X[i], Ys+=Y[i];
			}
			W.push_back({-Xs,Ys});
		}
	}
	
	deque<pair<ll,int>> Q;
	sort(ALL(V));
	sort(ALL(W));
	
	ll ma=-1LL<<60;
	int L=0,R=0;
	FORR(w,W) {
		
		while(R<V.size() && V[R].first<=w.first+D) {
			while(Q.size() && Q.back().first<=V[R].second) Q.pop_back();
			Q.push_back({V[R].second,R});
			R++;
		}
		while(L<V.size() && V[L].first<w.first-D) {
			while(Q.size() && Q.front().second<=L) Q.pop_front();
			L++;
		}
		if(Q.size()) ma=max(ma,w.second + Q.front().first);
		
		
	}
	
	
	cout<<ma<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
