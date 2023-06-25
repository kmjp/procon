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

int pre[101010];
vector<pair<int,int>> ev;
class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
		int i;
        FOR(i,n) pre[i]=-1;
        ev.clear();
        FORR(a,logs) {
			ev.push_back({a[1],a[0]-1});
		}
		sort(ALL(ev));
		reverse(ALL(ev));
		vector<int> Q=queries;
		map<int,int> M;
		set<pair<int,int>> S;
		sort(ALL(Q));
		
		int num=n;
		FORR(q,Q) {
			while(S.size()&&S.begin()->first<q) {
				num++;
				S.erase(S.begin());
			}
			while(ev.size()&&ev.back().first<=q) {
				int a=ev.back().first;
				int b=ev.back().second;
				ev.pop_back();
				if(S.count({pre[b],b})) {
					S.erase({pre[b],b});
				}
				else {
					num--;
				}
				pre[b]=a+x;
				S.insert({pre[b],b});
			}
			while(S.size()&&S.begin()->first<q) {
				num++;
				S.erase(S.begin());
			}
			M[q]=num;
		}
		FORR(q,queries) q=M[q];
		return queries;
			
    }
};
