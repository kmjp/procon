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



class EventManager {
public:
	map<int,int> M;
	set<pair<int,int>> V;
    EventManager(vector<vector<int>>& events) {
		M.clear();
		V.clear();
		FORR(e,events) {
			M[e[0]]=e[1];
			V.insert({-e[1],e[0]});
		}
    }
    
    void updatePriority(int eventId, int newPriority) {
		V.erase({-M[eventId],eventId});
		M[eventId]=newPriority;
		V.insert({-M[eventId],eventId});
        
    }
    
    int pollHighest() {
		if(V.empty()) return -1;
		int x=V.begin()->second;
		V.erase(V.begin());
		M.erase(x);
		return x;
        
    }
};

/**
 * Your EventManager object will be instantiated and called as such:
 * EventManager* obj = new EventManager(events);
 * obj->updatePriority(eventId,newPriority);
 * int param_2 = obj->pollHighest();
 */
 