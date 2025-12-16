#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------

set<pair<int,int>> S;
ll sum=0;
class CountIntervals {
public:
	
    CountIntervals() {
        S.clear();
        S.insert({-1,-1});
        S.insert({1<<30,1<<30});
        sum=0;
    }
    
    void add(int L, int R) {
		// R++; [3,5]‚È‚çR++,[3,5)‚È‚ç•s—v
		auto it=S.lower_bound({L,0});
		it--;
		if(it->second>=R) {
			return;
		}
		if(it->second>=L) {
			sum-=it->second-it->first;
			L=it->first;
			S.erase(it);
		}
		while(1) {
			auto it=S.lower_bound({L,0});
			if(it->first>=R) break;
			if(it->second>=R) {
				pair<int,int> a=*it;
				sum-=R-a.first;
				a.first=R;
				S.erase(it);
				S.insert(a);
				break;
			}
			sum-=it->second-it->first;
			S.erase(it);
		}
		S.insert({L,R});
		sum+=R-L;
        
    }
    
    int count() {
        return sum;
    }
};
int N,Q;
CountIntervals ci;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q;
	FOR(i,Q) {
		int L,R;
		cin>>L>>R;
		ci.add(L,R+1);
		cout<<N-ci.count()<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
