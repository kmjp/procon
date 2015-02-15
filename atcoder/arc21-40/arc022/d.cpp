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
#include <complex>

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

int N;
vector<pair<int,int> > V;
vector<pair<int,int> > cond[500002];


void solve() {
	int f,i,j,k,l;
	ll x,y;
	
	cin>>N;
	
	FOR(i,N) {
		cin>>x>>y;
		V.push_back(make_pair(x,y));
	}
	vector<int> C=convex_hull(V);
	vector<complex<double> > CC;
	
	FOR(i,C.size()) {
		int cx1=V[C[i]].first;
		int cy1=V[C[i]].second;
		int cx2=V[C[(i+1)%C.size()]].first;
		int cy2=V[C[(i+1)%C.size()]].second;
		complex<double> c1(cx1,cy1), c2(cx2,cy2);
		
		complex<double> v1=c2-c1,v2=-c1,v3;
		double ab=abs(v1);
		v1.real()/=ab;
		v1.imag()/=ab;
		double dot=v1.real()*v2.real()+v1.imag()*v2.imag();
		v3=v2-dot*v1;
		if(v1.real()*v2.imag()-v2.real()*v1.imag()>0) v3=-v3;
		v2=dot*v1-v3+c1;
		CC.push_back(v2);
	}
	
	FOR(i,C.size()) {
		ll cx1=V[C[i]].first;
		ll cy1=V[C[i]].second;
		complex<double> c(cx1,cy1);
		complex<double> p1=CC[(i+C.size()-1)%C.size()]-c;
		complex<double> p2=CC[i]-c;
		
		ll r=cx1*cx1+cy1*cy1;
		if(p1==p2) {
			for(y=-sqrt(r)-1;y<=sqrt(r)+1;y++) if(r-y*y>=0) {
				x=sqrt(r-y*y);
				if((x+1)*(x+1)+y*y<=r) x++;
				cond[250000+cy1+y].push_back(make_pair(cx1-x,1000000+i));
				cond[250000+cy1+y].push_back(make_pair(cx1+x+1,i));
			}
		}
		else if(p1.real()<=0 && p2.real()<=0) {
			if(p1.imag()<=p2.imag()) {
				for(y=ceil(p1.imag());y<=p2.imag();y++) if(r-y*y>=0) {
					x=sqrt(r-y*y);
					if((x+1)*(x+1)+y*y<=r) x++;
					cond[250000+cy1+y].push_back(make_pair(cx1-x,1000000+i));
					if(x==0) cond[250000+cy1+y].push_back(make_pair(cx1+x+1,0+i));
				}
			}
			else {
				for(y=-sqrt(r)-1;y<=sqrt(r)+1;y++) if(r-y*y>=0) {
					x=sqrt(r-y*y);
					if((x+1)*(x+1)+y*y<=r) x++;
					cond[250000+cy1+y].push_back(make_pair(cx1+x+1,i));
					if(y>=p2.imag() || y<=p1.imag())
						cond[250000+cy1+y].push_back(make_pair(cx1-x,1000000+i));
				}
			}
		}
		else if(p1.real()>0 && p2.real()<0) {
			for(y=floor(p1.imag());y>=-sqrt(r)-1;y--) if(r-y*y>=0) {
				x=sqrt(r-y*y);
				if((x+1)*(x+1)+y*y<=r) x++;
				cond[250000+cy1+y].push_back(make_pair(cx1+x+1,i));
			}
			for(y=-sqrt(r)-1;y<=p2.imag();y++) if(r-y*y>=0) {
				x=sqrt(r-y*y);
				if((x+1)*(x+1)+y*y<=r) x++;
				cond[250000+cy1+y].push_back(make_pair(cx1-x,1000000+i));
			}
		}
		else if(p1.real()<0 && p2.real()>0) {
			for(y=ceil(p1.imag());y<=sqrt(r)+1;y++) if(r-y*y>=0) {
				x=sqrt(r-y*y);
				if((x+1)*(x+1)+y*y<=r) x++;
				cond[250000+cy1+y].push_back(make_pair(cx1-x,1000000+i));
			}
			for(y=sqrt(r)+1;y>=p2.imag();y--) if(r-y*y>=0) {
				x=sqrt(r-y*y);
				if((x+1)*(x+1)+y*y<=r) x++;
				cond[250000+cy1+y].push_back(make_pair(cx1+x+1,i));
			}
		}
		else if(p1.real()>0 && p2.real()>0) {
			if(p1.imag()>p2.imag()) {
				for(y=floor(p1.imag());y>=p2.imag();y--) if(r-y*y>=0) {
					x=sqrt(r-y*y);
					if((x+1)*(x+1)+y*y<=r) x++;
					cond[250000+cy1+y].push_back(make_pair(cx1+x+1,i));
				}
			}
			else {
				for(y=-sqrt(r)-1;y<=sqrt(r)+1;y++) if(r-y*y>=0) {
					x=sqrt(r-y*y);
					if((x+1)*(x+1)+y*y<=r) x++;
					cond[250000+cy1+y].push_back(make_pair(cx1-x,1000000+i));
					if(y<=p2.imag() || y>=p1.imag())
						cond[250000+cy1+y].push_back(make_pair(cx1+x+1,i));
				}
			}
		}
	}
	
	ll ret=0;
	FOR(i,500001) if(!cond[i].empty()) {
		sort(cond[i].begin(),cond[i].end());
		int pre=-1000000,st=0;
		FOR(j,cond[i].size()) {
			if(j>0 && (cond[i][j].first==cond[i][j-1].first) && (cond[i][j].second/1000000==cond[i][j-1].second/1000000)) continue;
			if(cond[i][j].second>=1000000) {
				if(st==0) pre=cond[i][j].first;
				st++;
			}
			else {
				if(--st==0) ret+=cond[i][j].first-pre;
			}
		}
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


