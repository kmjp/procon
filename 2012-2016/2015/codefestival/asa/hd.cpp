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

int N,K;
ll X[101010],S[101010];
string D[101010];
pair<int,int> P[101010];

#include <limits>
template<class CC> int LIS_num(vector<CC>& v) {
	int i,N=v.size();
	vector<CC> dp(N,(numeric_limits<CC>::max)()),id(N);
	FOR(i,v.size()) dp[id[i]=lower_bound(dp.begin(),dp.end(),v[i]) - dp.begin()] = v[i];
	return *max_element(id.begin(),id.end())+1;
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	
	FOR(i,N) {
		cin>>X[i]>>S[i]>>D[i];
		P[i]={X[i],i};
	}
	sort(P,P+N);
	
	double L=0,R=1e10;
	FOR(i,100) {
		double M=(L+R)/2;
		vector<double> V;
		FOR(j,N) {
			x=P[j].second;
			if(D[x]=="R") V.push_back(X[x]+S[x]*M);
			else V.push_back(X[x]-S[x]*M);
		}
		
		if(LIS_num(V)>=N-K) L=M;
		else R=M;
	}
	
	if(L>1e9+10) {
		_P("Infinity\n");
	}
	else {
		_P("%.12lf\n",L);
	}
		
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
