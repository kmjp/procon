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
int P[33];
map<vector<int>, ll> memo;
const ll mo=1000000007;

vector<int> myslice(vector<int>& V,int a,int b) {
	return vector<int>(V.begin()+a,V.begin()+b);
}

ll hoge(vector<int> P) {
	if(P.size()<=1) return 1;
	//ˆ³k
	vector<int> Q=P;
	sort(ALL(Q));
	FORR(p,P) p=lower_bound(ALL(Q),p)-Q.begin();
	if(memo.count(P)) return memo[P];
	
	
	ll ret=0;
	int N=P.size();
	vector<ll> Xpat(N),Ypat(N);
	vector<int> R(N);
	int i,j,k;

	FOR(i,N) R[P[i]]=i;

	for(i=1;i<N;i++) {
		Xpat[i]=hoge(myslice(P,0,i));
		for(j=1;j<i;j++) Xpat[i]+=mo-Xpat[j]*hoge(myslice(P,j,i))%mo;
		int mi=*min_element(P.begin()+i,P.end());
		for(j=1;j<=mi;j++) {
			vector<int> W;
			FOR(k,i) if(P[k]>=j) W.push_back(P[k]);
			Xpat[i]+=mo-Ypat[j]*hoge(W);
		}
		Xpat[i]%=mo;
		ret+=Xpat[i]*hoge(myslice(P,i,N))%mo;
		
		Ypat[i]=hoge(myslice(R,0,i));
		
		for(j=1;j<i;j++) Ypat[i]+=mo-Ypat[j]*hoge(myslice(R,j,i))%mo;
		mi=*min_element(R.begin()+i,R.end());
		for(j=1;j<=mi;j++) {
			vector<int> W;
			FOR(k,i) if(R[k]>=j) W.push_back(R[k]);
			Ypat[i]+=mo-Xpat[j]*hoge(W);
		}
		Ypat[i]%=mo;
		ret+=Ypat[i]*hoge(myslice(R,i,N))%mo;
		
	}
	
	return memo[P]=ret%mo;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	vector<int> P(N);
	FOR(i,N) cin>>P[i];
	cout<<hoge(P)<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
