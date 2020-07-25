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

int N;
int X[202020],Y[202020];
string U[202020];

vector<pair<int,int>> LR[402020],UD[402020],RU[402020],LD[402020],LU[402020],RD[402020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	int ret=1<<30;
	cin>>N;
	FOR(i,N) {
		cin>>X[i]>>Y[i]>>U[i];
		
		if(U[i]=="L" || U[i]=="R") LR[Y[i]].push_back({X[i],i});
		if(U[i]=="U" || U[i]=="D") UD[X[i]].push_back({Y[i],i});
		if(U[i]=="L" || U[i]=="D") LD[X[i]+Y[i]].push_back({Y[i],i});
		if(U[i]=="R" || U[i]=="U") RU[X[i]+Y[i]].push_back({Y[i],i});
		if(U[i]=="L" || U[i]=="U") LU[Y[i]-X[i]+200000].push_back({X[i],i});
		if(U[i]=="R" || U[i]=="D") RD[Y[i]-X[i]+200000].push_back({X[i],i});
		
	}
	
	FOR(i,400001) {
		sort(ALL(LR[i]));
		sort(ALL(UD[i]));
		sort(ALL(LD[i]));
		sort(ALL(RU[i]));
		sort(ALL(LU[i]));
		sort(ALL(RD[i]));
		FOR(j,(int)LR[i].size()-1) if(U[LR[i][j].second]=="R"&&U[LR[i][j+1].second]=="L") ret=min(ret,(LR[i][j+1].first-LR[i][j].first)*5);
		FOR(j,(int)UD[i].size()-1) if(U[UD[i][j].second]=="U"&&U[UD[i][j+1].second]=="D") ret=min(ret,(UD[i][j+1].first-UD[i][j].first)*5);
		FOR(j,(int)LD[i].size()-1) if(U[LD[i][j].second]=="L"&&U[LD[i][j+1].second]=="D") ret=min(ret,(LD[i][j+1].first-LD[i][j].first)*10);
		FOR(j,(int)RU[i].size()-1) if(U[RU[i][j].second]=="U"&&U[RU[i][j+1].second]=="R") ret=min(ret,(RU[i][j+1].first-RU[i][j].first)*10);
		FOR(j,(int)LU[i].size()-1) if(U[LU[i][j].second]=="U"&&U[LU[i][j+1].second]=="L") ret=min(ret,(LU[i][j+1].first-LU[i][j].first)*10);
		FOR(j,(int)RD[i].size()-1) if(U[RD[i][j].second]=="R"&&U[RD[i][j+1].second]=="D") ret=min(ret,(RD[i][j+1].first-RD[i][j].first)*10);
		
	}
	
	
	
	if(ret==1<<30) {
		cout<<"SAFE"<<endl;
	}
	else {
		cout<<ret<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
