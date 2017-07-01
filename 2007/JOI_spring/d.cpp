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

#include <limits>
template<class CC> int LIS_num(vector<CC>& v) {
	int i,N=v.size();
	vector<CC> dp(N,(numeric_limits<CC>::max)()),id(N);
	FOR(i,v.size()) dp[id[i]=lower_bound(dp.begin(),dp.end(),v[i]) - dp.begin()] = v[i];
	return *max_element(id.begin(),id.end())+1;
}

int N;
vector<int> A;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>x;
		A.push_back(x);
	}
	cout<<LIS_num(A)<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
