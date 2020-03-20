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

int H,W,N;
int Y[101010],X[101010];
map<int,vector<int>> R,C;
vector<int> Rs,Cs;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W>>N;
	FOR(i,N) {
		cin>>Y[i]>>X[i];
		Y[i]--;
		X[i]--;
	}
	ll ma=0;
	FOR(i,4) {
		R.clear();
		C.clear();
		Rs.clear();
		Cs.clear();
		FOR(j,N) {
			R[Y[j]].push_back(X[j]);
			Rs.push_back(Y[j]);
			C[X[j]].push_back(Y[j]);
			Cs.push_back(X[j]);
		}
		sort(ALL(Rs));
		sort(ALL(Cs));
		Rs.erase(unique(ALL(Rs)),Rs.end());
		Cs.erase(unique(ALL(Cs)),Cs.end());
		
		FORR(r,R) {
			sort(ALL(r.second));
			x=r.second[0]-1;
			if(x>=0) ma=max(ma,(ll)(x-(lower_bound(ALL(Cs),x)-Cs.begin())));
		}
		FORR(r,C) {
			sort(ALL(r.second));
			y=r.second[0]-1;
			if(y>=0) ma=max(ma,(ll)(y-(lower_bound(ALL(Rs),y)-Rs.begin())));
		}
		
		set<int> ok;
		for(j=Rs.size()-1;j>=0;j--) {
			y=Rs[j];
			
			x=*min_element(ALL(R[y]));
			auto it=ok.lower_bound(x);
			if(it!=ok.begin()) {
				it--;
				x=*it;
				ma=max(ma,(ll)(y-(lower_bound(ALL(Rs),y)-Rs.begin())+x-(lower_bound(ALL(Cs),x)-Cs.begin())));
			}
			
			FORR(x,R[y]) if(C[x][0]==y) ok.insert(x);
		}
		
		
		FOR(j,N) Y[j]=H-1-Y[j];
		if(i%2==1) {
			FOR(j,N) X[j]=W-1-X[j];
		}
	}
	ma+=(H-Rs.size())*(W-Cs.size());
	
	cout<<ma<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
