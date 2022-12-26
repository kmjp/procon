#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N;
ll X[2001],Y[2001];
int dead[2001];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>X[i]>>Y[i];
	vector<pair<ll,pair<int,int>>> V;
	FOR(y,N) FOR(x,y) {
		ll d=(X[x]-X[y])*(X[x]-X[y])+(Y[y]-Y[x])*(Y[y]-Y[x]);
		V.push_back({d,{x,y}});
	}
	
	int num=0;
	sort(ALL(V));
	FORR(v,V) {
		x=v.second.first;
		y=v.second.second;
		if(dead[x]+dead[y]==0) {
			if(x==0) {
				num++;
				dead[y]=1;
			}
			else {
				dead[x]=dead[y]=1;
			}
		}
	}
	cout<<num<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
