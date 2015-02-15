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

string SS[500];
int mind[500];
int dif[500];
int Q;

pair<int,int> dodo(int cur,int y,int z) {
	int i;
	int mi=0,dif=0;
	for(i=y;i<z;i++) {
		if(SS[cur][i]=='(') dif++;
		else dif--, mi=max(mi,-dif);
	}
	return make_pair(mi,dif);
}

void rebuild2(int cur) {
	pair<int,int> p = dodo(cur,0,SS[cur].size());
	mind[cur]=p.first;
	dif[cur]=p.second;
}

void rebuild() {
	string s;
	int i;
	FOR(i,500) s+=SS[i];
	FOR(i,500) {
		if(s.size()<=i*500) SS[i]="";
		else if(s.size()>=(i+1)*500) SS[i]=s.substr(i*500,500);
		else SS[i]=s.substr(i*500);
		rebuild2(i);
	}
}


void solve() {
	int i,j,k,l,r,x,y,z; string s;

	cin>>Q>>SS[0];
	rebuild();
	int ad=0;
	while(Q--) {
		cin>>s>>y>>z;
		y--;
		if(s[0]=='(' || s[0]==')') {
			FOR(i,500) {
				if(y<=SS[i].size()) break;
				y-=SS[i].size();
			}
			SS[i].insert(y,s.c_str());
			if(++ad>=1000) rebuild(), ad=0;
			else rebuild2(i);
		}
		if(s[0]=='D') {
			FOR(i,500) {
				if(y<SS[i].size()) break;
				y-=SS[i].size();
			}
			SS[i].erase(SS[i].begin()+y);
			rebuild2(i);
		}
		if(s[0]=='Q') {
			int iy,iz;
			FOR(iy,500) {
				if(y<SS[iy].size()) break;
				y-=SS[iy].size();
			}
			FOR(iz,500) {
				if(z<=SS[iz].size()) break;
				z-=SS[iz].size();
			}
			
			if(iy==iz) {
				pair<int,int> p=dodo(iy,y,z);
				cout << p.first+(p.second+p.first) << endl;
			}
			else {
				int di=0,mi=0;
				pair<int,int> p = dodo(iy,y,SS[iy].size());
				mi=p.first;
				di=p.second+p.first;
				for(i=iy+1;i<iz;i++) {
					p=make_pair(mind[i],dif[i]);
					if(p.first>di) mi+=p.first-di, di+=p.second+(p.first-di);
					else di+=p.second;
				}
				p=dodo(iz,0,z);
				if(p.first>di) mi+=p.first-di, di+=p.second+(p.first-di);
				else di+=p.second;
				
				cout << mi+di << endl;
			}
			
		}
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
