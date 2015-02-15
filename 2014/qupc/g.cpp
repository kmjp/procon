#include <cstdlib>
#include <cstring>
#include <memory>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
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
#define FILL_INT(a,val) _fill_int((int*)a,val,sizeof(a)/4)
#define MINUS(a) _fill_int((int*)a,-1,sizeof(a)/4)
ll GETi() { ll i;scanf("%lld",&i); return i;}
//-------------------------------------------------------

int N,M;
vector<pair<int,int> > V;
int CX[101],CY[101],CR[101],BX[101],BY[101],BW[101],BH[101];

int danger(int cir,int rec) {
	int cx=CX[cir],cy=CY[cir],cr=CR[cir];
	int bl=BX[rec],br=BX[rec]+BW[rec],bt=BY[rec],bb=BY[rec]+BH[rec];
	
	// circle in rect
	if(bl<=cx && cx<=br && bt<=cy && cy<=bb) return 1;
	// vertex in circle
	if((cx-bl)*(cx-bl)+(cy-bt)*(cy-bt) <= cr*cr) return 1;
	if((cx-bl)*(cx-bl)+(cy-bb)*(cy-bb) <= cr*cr) return 1;
	if((cx-br)*(cx-br)+(cy-bt)*(cy-bt) <= cr*cr) return 1;
	if((cx-br)*(cx-br)+(cy-bb)*(cy-bb) <= cr*cr) return 1;
	
	// cross twice
	if(bt<=cy && cy<=bb) {
		if(abs(cx-bl)<=cr || abs(cx-br)<=cr) return 1;
	}
	if(bl<=cx && cx<=br) {
		if(abs(cy-bt)<=cr || abs(cy-bb)<=cr) return 1;
	}
	return 0;
	
}

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
	
	cin>>N>>M;
	FOR(i,N) cin>>CX[i]>>CY[i]>>CR[i];
	FOR(i,M) cin>>BX[i]>>BY[i]>>BW[i]>>BH[i];
	FOR(i,M) {
		int dan=0;
		FOR(j,N) dan |= danger(j,i);
		if(dan) {
			V.push_back(make_pair(BX[i],BY[i]));
			V.push_back(make_pair(BX[i]+BW[i],BY[i]));
			V.push_back(make_pair(BX[i],BY[i]+BH[i]));
			V.push_back(make_pair(BX[i]+BW[i],BY[i]+BH[i]));
		}
	}
	
	if(V.size()==0) return _P("0\n");
	double ret=0;
	vector<int> VV=convex_hull(V);
	VV.push_back(VV[0]);
	FOR(i,VV.size()-1) {
		double dx=V[VV[i+1]].first-V[VV[i]].first,dy=V[VV[i+1]].second-V[VV[i]].second;
		ret += sqrt(dx*dx+dy*dy);
	}
	_P("%.12lf\n",ret);
}


int main(int argc,char** argv){
	string s;
	if(argc==1) ios::sync_with_stdio(false);
	for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
	for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
	solve();
	return 0;
}


