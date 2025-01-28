#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
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

class Solution {
public:
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
		vector<int> ret(numberOfUsers);
		vector<pair<int,int>> V;
		FORR(a,events) {
			pair<int,int> W;
			W.first=atoi(a[1].c_str());
			if(a[0]=="MESSAGE") {
				W.first*=2;
				W.first++;
				if(a[2]=="ALL") {
					FORR(b,ret) b++;
				}
				else if(a[2]=="HERE") {
					W.second=-1;
					V.push_back(W);
				}
				else {
					a[2]+=' ';
					int cur=0;
					FORR(c,a[2]) {
						if(c=='i'||c=='d') {
							cur=0;
						}
						else if(c==' ') {
							ret[cur]++;
							cur=0;
						}
						else {
							cur=cur*10+c-'0';
						}
					}
				}
			}
			else {
				W.first*=2;
				W.second=atoi(a[2].c_str());
				V.push_back(W);
			}
		}
		sort(ALL(V));
		int online[101]={};
		FORR(a,V) {
			if(a.second==-1) {
				int i;
				FOR(i,numberOfUsers) if(a.first>=online[i]) ret[i]++;
			}
			else {
				online[a.second]=a.first+120;
				cout<<a.second<<" "<<online[a.second]<<endl;
			}
		}
        return ret;
    }
};


