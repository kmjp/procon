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

double d1,d2;
int X1,Y1,X2,Y2;
int N;
int XX[202020],YY[202020];

vector<int> LIS(vector<int>& v) {
	int i,N=v.size();
	vector<int> dp(N,1<<30),id(N);
	FOR(i,v.size()) {
		id[i] = lower_bound(dp.begin(),dp.end(),v[i]) - dp.begin();
		dp[id[i]] = v[i];
	}
	int nl = *max_element(id.begin(),id.end());
	vector<int> ret(nl+1);
	FOR(i,N) if(id[N-1-i] == nl) ret[nl--] = v[N-1-i];
	return ret;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	double PI=atan(1)*4;
	d1=20-20*PI/4;
	d2=20*PI/2-20;
	
	cin>>X1>>Y1>>X2>>Y2;
	cin>>N;
	FOR(i,N) {
		cin>>XX[i]>>YY[i];
		if(XX[i]<min(X1,X2) || XX[i]>max(X1,X2) || YY[i]<min(Y1,Y2) || YY[i]>max(Y1,Y2)) i--,N--;
	}
	
	X2-=X1;
	Y2-=Y1;
	vector<pair<int,int>> V;
	FOR(i,N) {
		XX[i]-=X1;
		if(X2<0) XX[i]=-XX[i];
		YY[i]-=Y1;
		if(Y2<0) YY[i]=-YY[i];
		V.push_back({XX[i],YY[i]});
	}
	if(X2<0) X2=-X2;
	if(Y2<0) Y2=-Y2;
	
	double ret=100.0*(X2+Y2);
	if(N) {
		vector<int> V2;
		
		sort(ALL(V));
		FORR(v,V) V2.push_back(v.second);
		auto V3=LIS(V2);
		
		if(V3.size()==min(X2,Y2)+1) {
			ret+=d2-d1*(V3.size()-1);
		}
		else {
			ret-=d1*V3.size();
		}
	}
	_P("%.12lf\n",ret);
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
