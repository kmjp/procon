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


unordered_map<int,int> user[505050];
set<pair<int,int>> bid[505050];

class AuctionSystem {
public:
    AuctionSystem() {
		int i;
		FOR(i,50101) {
			user[i].clear();
			bid[i].clear();
		}
        
    }
    
    void addBid(int userId, int itemId, int bidAmount) {
		if(user[userId].count(itemId)) {
			updateBid(userId, itemId, bidAmount);
			return;
		}
        user[userId][itemId]=bidAmount;
        bid[itemId].insert({bidAmount,userId});
    }
    
    void updateBid(int userId, int itemId, int newAmount) {
		bid[itemId].erase({user[userId][itemId],userId});
        user[userId][itemId]=newAmount;
        bid[itemId].insert({newAmount,userId});
        
    }
    
    void removeBid(int userId, int itemId) {
		bid[itemId].erase({user[userId][itemId],userId});
		user[userId].erase(itemId);
    }
    
    int getHighestBidder(int itemId) {
		if(bid[itemId].empty()) return -1;
        return bid[itemId].rbegin()->second;
    }
};

/**
 * Your AuctionSystem object will be instantiated and called as such:
 * AuctionSystem* obj = new AuctionSystem();
 * obj->addBid(userId,itemId,bidAmount);
 * obj->updateBid(userId,itemId,newAmount);
 * obj->removeBid(userId,itemId);
 * int param_4 = obj->getHighestBidder(itemId);
 */
 
 
 