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

class Solution {
public:
    int getNumberOfBacklogOrders(vector<vector<int>>& orders) {
		map<int,int> buy;
		map<int,int> sell;
		FORR(o,orders) {
			int num=o[1];
			if(o[2]==0) {
				while(num&&sell.size()&&sell.begin()->first<=o[0]) {
					int v=min(num,sell.begin()->second);
					num-=v;
					sell.begin()->second-=v;
					if(sell.begin()->second==0) sell.erase(sell.begin()->first);
				}
				if(num) buy[o[0]]+=num;
			}
			else {
				while(num&&buy.size()&&buy.rbegin()->first>=o[0]) {
					int v=min(num,buy.rbegin()->second);
					num-=v;
					buy.rbegin()->second-=v;
					if(buy.rbegin()->second==0) buy.erase(buy.rbegin()->first);
				}
				if(num) sell[o[0]]+=num;
				
			}
			/*
			cout<<"#"<<endl;
			FORR(b,buy) {
				cout<<"b "<<b.first<<" "<<b.second<<endl;
			}
			FORR(b,sell) {
				cout<<"s "<<b.first<<" "<<b.second<<endl;
			}
			*/
		}
		ll ret=0;
		FORR(b,buy) {
			ret+=b.second;
		}
		FORR(b,sell) {
			ret+=b.second;
		}
        return ret%1000000007;
    }
};
