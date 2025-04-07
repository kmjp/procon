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

class Router {
public:
	int L;
	deque<array<int,3>> D;
	set<array<int,3>> S;
	map<int,deque<int>> M;
    Router(int memoryLimit) {
        L=memoryLimit;
        D.clear();
        S.clear();
        M.clear();
    }
    
    bool addPacket(int source, int destination, int timestamp) {
        if(S.count({source, destination, timestamp})) return 0;
        if(D.size()==L) {
			auto a=D[0];
			S.erase(a);
			M[a[1]].pop_front();
			D.pop_front();
		}
		D.push_back({source, destination, timestamp});
		S.insert(D.back());
		M[destination].push_back(timestamp);
        
        return 1;
    }
    
    vector<int> forwardPacket() {
        if(D.size()) {
			auto a=D[0];
			S.erase(a);
			M[a[1]].pop_front();
			D.pop_front();
			return {a[0],a[1],a[2]};
		}
		else {
			return {};
		}
    }
    
    int getCount(int destination, int startTime, int endTime) {
       	int x=lower_bound(ALL(M[destination]),endTime+1)-lower_bound(ALL(M[destination]),startTime);
       	return x;
    }
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */
 
 
 