#include <cstdlib>
#include <cstring>
#include <memory>
#include <cstdio>
#include <iostream>
#include <cmath>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)

#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ZERO(a) memset(a,0,sizeof(a))
void _fill_int(int* p,int val,int rep) {int i;	FOR(i,rep) p[i]=val;}
#define MINUS(a) _fill_int((int*)a,-1,sizeof(a)/4)
//-------------------------------------------------------

int N;
int X[100001],Y[100001];
int HH[5001][5001];
int SQ[2000001];
int hoge[2001][2001];


ll veccross(pair<int,int> p1,pair<int,int> p2,pair<int,int> p3) {
	p3.first-=p1.first;p2.first-=p1.first;
	p3.second-=p1.second;p2.second-=p1.second;
	return p3.first*(ll)p2.second-p2.first*(ll)p3.second;
}

vector<int> convex_hull(vector< pair<int, int> >& vp) {
	vector<pair<pair<int, int>, int> > sorted;
	vector<int> res;
	int i,k=0,rb;
	
	if(vp.size()<=2) {
		if(vp.size()>=1) res.push_back(0);
		if(vp.size()>=2) res.push_back(1);
		return res;
	}
	
	FOR(i,vp.size()) sorted.push_back(make_pair(vp[i],i));
	sort(sorted.begin(),sorted.end());
	res.resize(vp.size()*2);
	/* bottom */
	FOR(i,vp.size()) {
		while(k>1 && veccross(vp[res[k-2]],vp[res[k-1]],sorted[i].first)<=0) k--;
		res[k++]=sorted[i].second;
	}
	/* top */
	for(rb=k, i=vp.size()-2;i>=0;i--) {
		while(k>rb && veccross(vp[res[k-2]],vp[res[k-1]],sorted[i].first)<=0) k--;
		res[k++]=sorted[i].second;
	}
	res.resize(k-1);
	return res;
}


void solve() {
	int f,i,j,k,l,x,y;
	
	cin>>N;
	
	FOR(x,5001) FOR(y,5001) HH[x][y]=-10000;
	for(i=1;i<=2000000;i++) {
		SQ[i]=SQ[i-1];
		if((SQ[i]+1)*(SQ[i]+1)<=i) SQ[i]++;
	}
	
	FOR(i,N) cin>>X[i]>>Y[i];
	vector<pair<int,int> > V;
	FOR(i,N) V.push_back(make_pair(X[i],Y[i]));
	vector<int> C=convex_hull(V);
	
	FOR(i,C.size()) {
		int cx=V[C[i]].first;
		int cy=V[C[i]].second;
		if(cx<-1000 || cx>1000) return;
		if(cy<-1000 || cy>1000) return;
		
		ll r=cx*cx+cy*cy;
		for(y=cy-(SQ[r]+1);y<=cy+(SQ[r]+1);y++) {
			if(r-(cy-y)*(cy-y)>=0) {
				x=SQ[r-(cy-y)*(cy-y)];
				HH[y+2500][cx-x+2500]=max(HH[y+2500][cx-x+2500],cx+x+2500);
			}
		}
	}
	
	ll ret=0;
	FOR(y,5001) {
		int prey=-5000,my=-5001;
		FOR(x,5001) {
			if(HH[y][x]>-10000) {
				if(x<=my) {
					ret+=x-prey;
					prey=x;
					my=max(my,HH[y][x]);
				}
				else {
					ret+=my-prey+1;
					prey=x;
					my=HH[y][x];
				}
			}
		}
		ret += my-prey+1;
	}
	cout << ret << endl;
}


int main(int argc,char** argv){
	string s;
	if(argc==1) ios::sync_with_stdio(false);
	for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
	for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
	solve();
	return 0;
}


