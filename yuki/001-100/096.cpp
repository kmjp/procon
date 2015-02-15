#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

class UF {
	public:
	static const int ufmax=120200;
	int ufpar[ufmax],ufrank[ufmax],ufcnt[ufmax];
	UF() { init();}
	void init(){int i; FOR(i,ufmax) { ufpar[i]=i; ufrank[i]=0; ufcnt[i]=1; } }
	int find(int x) {	return (ufpar[x]==x)?(x):(ufpar[x] = find(ufpar[x]));}
	int operator[](int x) {return find(x);}
	int count(int x) {return ufcnt[find(x)];}
	void unite(int x,int y) {
		x = find(x); y = find(y);
		if(x==y) return;
		if(ufrank[x]<ufrank[y]) ufpar[x]=y, ufcnt[y]+=ufcnt[x];
		else {ufpar[y]=x; ufcnt[x]+=ufcnt[y]; if(ufrank[x]==ufrank[y]) ufrank[x]++;}
	}
};
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
int X[120001],Y[120001];
UF uf;
map<int,int> YS[20015];

vector<pair<int,int> > V[120001];

void solve() {
	int i,j,k,l,r,x,y,y2,x2;
	
	cin>>N;
	FOR(i,N) {
		cin>>X[i]>>Y[i], X[i]+=10001,Y[i]+=10001;
		YS[X[i]][Y[i]]=i;
	}
	
	FOR(x,20002) {
		ITR(it,YS[x]) {
			int cur=it->first;
			map<int,int>::iterator it2=it;
			for(it2++;it2!=YS[x].end();it2++) {
				if(it2->first-it->first>10) break;
				uf.unite(it->second,it2->second);
			}
			for(x2=x+1;x2<=x+10;x2++) {
				for(map<int,int>::iterator it2=YS[x2].lower_bound(it->first-10); it2!=YS[x2].end();it2++) {
					if(it2->first<it->first && (x2-x)*(x2-x)+(it->first-it2->first)*(it->first-it2->first)>100) continue;
					if((x2-x)*(x2-x)+(it->first-it2->first)*(it->first-it2->first)>100) break;
					uf.unite(it->second,it2->second);
				}
			}
		}
	}
	
	FOR(i,N) V[uf[i]].push_back(make_pair(X[i],Y[i]));
	
	double ma=1;
	FOR(i,N) if(V[i].size()) {
		if(V[i].size()==1) ma=max(ma,2.0);
		else if(V[i].size()==2) ma=max(ma,2+sqrt((V[i][0].first-V[i][1].first)*(V[i][0].first-V[i][1].first)+(V[i][0].second-V[i][1].second)*(V[i][0].second-V[i][1].second)));
		else {
			vector<int> ch=convex_hull(V[i]);
			FOR(x,ch.size()) for(y=x+1;y<ch.size();y++)
				ma=max(ma,2+sqrt((V[i][ch[x]].first-V[i][ch[y]].first)*(V[i][ch[x]].first-V[i][ch[y]].first)+(V[i][ch[x]].second-V[i][ch[y]].second)*(V[i][ch[x]].second-V[i][ch[y]].second)));
		}
	}
	_P("%.12lf\n",ma);
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}

