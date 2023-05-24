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

int N,Q;
set<pair<int,int>> S={{-2,-1},{1<<30,1+(1<<30)}};


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q;
	while(Q--) {
		cin>>i;
		/*
		FORR2(a,b,S) cout<<a<<":"<<b<<" ";
		cout<<endl;
		*/
		if(i==1||i==2) {
			int L,R;
			cin>>L>>R;
			if(i==1) {
				pair<int,int> P={L,R};
				auto it=S.lower_bound({L+1,0});
				it--;
				if(it->second>=L) {
					P.first=it->first;
					P.second=max(it->second,R);
					S.erase(it);
				}
				while(1) {
					it=S.lower_bound({L+1,0});
					if(it->first<=R) {
						P.second=max(P.second,it->second);
						S.erase(it);
					}
					else {
						break;
					}
				}
				S.insert(P);
			}
			else {
				while(1) {
					auto it=S.lower_bound({L,0});
					if(it->first>=R) break;
					if(it->second<=R) {
						S.erase(it);
					}
					else {
						auto p=*it;
						S.erase(it);
						S.insert({R,p.second});
					}
				}
				while(1) {
					auto it=S.lower_bound({R,0});
					it--;
					if(it->second>R) {
						auto p=*it;
						S.erase(it);
						S.insert({p.first,L});
						S.insert({R,p.second});
					}
					else if(it->second>L) {
						auto p=*it;
						S.erase(it);
						S.insert({p.first,L});
					}
					break;
				}
			}
			
		}
		else if(i==3) {
			cin>>x>>y;
			if(x>y) swap(x,y);
			auto it=S.lower_bound({x+1,0});
			it--;
			if(x==y||it->first<=x&&y<=it->second) {
				cout<<1<<endl;
			}
			else {
				cout<<0<<endl;
			}
		}
		else {
			cin>>x;
			auto it=S.lower_bound({x+1,0});
			it--;
			if(it->first<=x&&x<=it->second) {
				cout<<1+it->second-it->first<<endl;
			}
			else {
				cout<<1<<endl;
			}
			
		}
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
