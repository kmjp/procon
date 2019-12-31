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

int N;
int S[102000],T[102000];
double un[102000],sc[102000];

vector<pair<int,int> > ev;
vector<int> keep;
int num;
double rat[102000],rat300[102000];

double dodo(int c) {
	double k=1;
	while(c%300 && c<keep.size()) k*=rat[c++];
	while(c<keep.size()) k*=rat300[c/300], c+=300;
	return k;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>S[i]>>T[i];
		ev.push_back(make_pair(S[i],i));
		ev.push_back(make_pair(T[i],i));
	}
	FOR(i,102000) rat300[i]=1;
	sort(ALL(ev));
	
	FOR(i,ev.size()) {
		x=ev[i].second;
		if(S[x]==ev[i].first) {
			num++;
		}
		else {
			vector<int>::iterator it=lower_bound(keep.begin(),keep.end(),S[x]);
			double k=dodo(it-keep.begin());
			un[x]=1-k;
			sc[x]=(1.0-un[x])*(num-1)/num;
			
			rat[keep.size()]=(num-1.0)/num;
			rat300[keep.size()/300]*=rat[keep.size()];
			keep.push_back(T[x]);
			
			num--;
		}
	}
	
	
	FOR(i,N) _P("%.12lf %.12lf\n",un[i],sc[i]);
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
