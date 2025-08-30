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

int A[6];

map<pair<vector<int>,vector<int>>,double> memo2,memo3;


int result(vector<int> V) {
	
	map<int,int> M;
	int ret=0;
	int i;
	FOR(i,6) {
		M[A[i]]+=V[i];
		ret=max(ret,A[i]*M[A[i]]);
	}
	
	return ret;
}


double dfs3(vector<int> fix,vector<int> unfix) {
	if(memo3.count({fix,unfix})) return memo3[{fix,unfix}];
	int sum=0;
	int i;
	FORR(c,fix) sum+=c;
	FORR(c,unfix) sum+=c;
	double ret=0;
	if(sum==5) {
		FOR(i,6) fix[i]+=unfix[i];
		ret=result(fix);
	}
	else {
		FOR(i,6) {
			unfix[i]++;
			ret+=dfs3(fix,unfix);
			unfix[i]--;
		}
		ret/=6;
	}
	return memo3[{fix,unfix}]=ret;
}
double dfs2(vector<int> fix,vector<int> unfix) {
	if(memo2.count({fix,unfix})) return memo2[{fix,unfix}];
	int sum=0;
	int i;
	FORR(c,fix) sum+=c;
	FORR(c,unfix) sum+=c;
	double ret=0;
	if(sum==5) {
		vector<int> unfix2(6);
		int mask,i;
		double ma=0;
		FOR(mask,1<<6) {
			auto fix2=fix;
			FOR(i,6) if(mask&(1<<i)) fix2[i]+=unfix[i];
			ma=max(ma,dfs3(fix2,unfix2));
		}
		ret=ma;
	}
	else {
		FOR(i,6) {
			unfix[i]++;
			ret+=dfs2(fix,unfix);
			unfix[i]--;
		}
		ret/=6;
	}
	return memo2[{fix,unfix}]=ret;
}





double dfs(vector<int> C) {
	int sum=0;
	FORR(c,C) sum+=c;
	if(sum==5) {
		vector<int> unfix(6);
		int mask,i;
		double ma=0;
		FOR(mask,1<<6) {
			vector<int> fix(6);
			FOR(i,6) if(mask&(1<<i)) fix[i]=C[i];
			ma=max(ma,dfs2(fix,unfix));
		}
		return ma;
	}
	double ret=0;
	int i;
	FOR(i,6) {
		C[i]++;
		ret+=dfs(C);
		C[i]--;
	}
	return ret/6;
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	FOR(i,6) cin>>A[i];
	vector<int> C(6);
	double ret=dfs(C);
	_P("%.12lf\n",ret);
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
