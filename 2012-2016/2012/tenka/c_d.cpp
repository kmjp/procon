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

int H,W;
map<vector<int>,int> from[1024][2];
map<vector<int>,int> to[1024][2];
string S;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	
	from[0][0][{}]=0;
	FOR(y,H) {
		cin>>S;
		FOR(x,W) {
			FOR(i,1024) to[i][0].clear(), to[i][1].clear();
			FOR(i,1024) FOR(j,2) FORR(f,from[i][j]) {
				if(j&&i) continue;
				if(S[x]=='.') {
					//open
					int nm=i;
					if(nm&(1<<x)) nm^=1<<x;
					if(x&&(nm&(1<<(x-1)))) nm^=1<<(x-1);
					
					vector<int> NM;
					int orm=1<<x;
					FORR(n,f.first) {
						int nm=n;
						if(x&&(n&(1<<(x-1)))) nm|=1<<x;
						if(nm&(1<<x)) {
							orm|=nm;
						}
						else {
							NM.push_back(nm);
						}
					}
					NM.push_back(orm);
					sort(ALL(NM));
					to[nm][j][NM]=max(to[nm][j][NM],f.second);
					
				}
				if(S[x]=='#' || S[x]=='.') {
					// close
					vector<int> NM;
					if((i&(1<<x))==0) {
						int add=0;
						int sc=S[x]=='.';
						FORR(m,f.first) {
							if(m&(1<<x)) {
								if(m==(1<<x)) {
									add++;
								}
								else {
									NM.push_back(m^(1<<x));
								}
							}
							else {
								NM.push_back(m);
							}
						}
						sort(ALL(NM));
						if(j+add<2) to[i][j+add][NM]=max(to[i][j+add][NM],f.second+sc);
					}
				}
				if(S[x]=='H') {
					// home
					vector<int> NM;
					if((i&(1<<x))==0) {
						int add=0;
						int ng=1<<x;
						FORR(m,f.first) {
							if(m&(1<<x)) ng=0;
							if(x&&(m&(1<<(x-1)))) ng=0;
							if(m&(1<<x)) {
								if(m==(1<<x)) {
									add++;
								}
								else {
									NM.push_back(m^(1<<x));
								}
							}
							else {
								NM.push_back(m);
							}
						}
						sort(ALL(NM));
						if(j+add<2) to[i|ng][j+add][NM]=max(to[i|ng][j+add][NM],f.second);
					}
				}
			}
			swap(from,to);
			/*
			cout<<y<<" "<<x<<endl;
			FOR(i,1024) FOR(j,2) FORR(f,from[i][j]) {
				cout<<" "<<i<<" "<<j<<" "<<" ";
				FORR(m,f.first) cout<<"["<<m<<"] ";
				cout<<f.second<<endl;
			}
			*/
			
		}
	}
	
	int ma=-1;
	FORR(f,from[0][0]) if(f.first.size()==1) ma=max(ma,f.second);
	FORR(f,from[0][1]) if(f.first.empty()) ma=max(ma,f.second);
	cout<<ma<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
