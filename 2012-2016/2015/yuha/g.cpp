#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------


int inside(double x,double y,vector<pair<ll,ll> >& V) {
	int num=0,n=V.size(),i;
	// ‰E‚ÉL‚Î‚µ‚Ä‰½‰ñãŒü‚«E‰ºŒü‚«‚ÆŒð·‚·‚é‚©H
	// 0-out 1-in 2-border
	FOR(i,n) if(x==V[i].first && y==V[i].second) return 2; // on point
	FOR(i,n) { // on border
		double dx=V[(i+1)%n].first-V[i].first,dy=V[(i+1)%n].second-V[i].second;
		double dx2=x-V[i].first,dy2=y-V[i].second;
		if(fabs(dx*dy2-dx2*dy)>=1e-9) continue;
		if(dx!=0) {
			if(dx2/dx>=0 && dx2/dx<=1) return 1;
		}
		else if(dy2/dy>=0 && dy2/dy<=1) return 1;
	}
	
	FOR(i,n) { //cross border?
		ll x1=V[i].first,y1=V[i].second;
		ll x2=V[(i+1)%n].first,y2=V[(i+1)%n].second;
		if(y1==y2) continue;
		if(y1==y) {
			if(x1>=x && y2<y) num++; // down
		}
		else if(y2==y) {
			if(x2>=x && y1<y) num--; // up
		}
		else if(y1>y && y2<y) { //down
			double xx=x1+(x2-x1)*(double)(y-y1)/(y2-y1);
			if(xx>=x) num++;
		}
		else if(y1<y && y2>y) { //up
			double xx=x1+(x2-x1)*(double)(y-y1)/(y2-y1);
			if(xx>=x) num--;
		}
	}
	return num!=0;
}

int N,M;
string S[5050];
int X[5050],Y[5050],used[5050];
map<string,int> MM;
vector<pair<ll,ll> > P;


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>S[i]>>X[i]>>Y[i];
		MM[S[i]]=i;
	}
	
	cin>>M;
	FOR(i,M) {
		cin>>s;
		used[MM[s]]=1;
		P.push_back({X[MM[s]],Y[MM[s]]});
	}
	set<pair<int,string> > SS;
	FOR(i,N) if(used[i]==0) {
		if(inside(X[i],Y[i],P)) SS.insert({X[i],S[i]});
	}
	FORR(r,SS) cout<<r.second<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
