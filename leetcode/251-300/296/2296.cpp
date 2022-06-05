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


#include <ext/rope>
using namespace __gnu_cxx;

rope<char> S;
int cur;
class TextEditor {
public:
    TextEditor() {
        S="";
        cur=0;
    }
    
    void addText(string text) {
		crope c(text.c_str(),text.size());
        S.insert(cur,c);
        cur+=text.size();
    }
    
    int deleteText(int k) {
		k=min(k,cur);
		cur-=k;
		S.erase(cur,k);
        return k;
    }
    
    string cursorLeft(int k) {
		cur=max(cur-k,0);
		int a=max(cur-10,0);
        return S.substr(a,cur-a).c_str();
        
    }
    
    string cursorRight(int k) {
		cur=min(cur+k,(int)S.size());
		int a=max(cur-10,0);
        return S.substr(a,cur-a).c_str();
        
    }
};

/**
 * Your TextEditor object will be instantiated and called as such:
 * TextEditor* obj = new TextEditor();
 * obj->addText(text);
 * int param_2 = obj->deleteText(k);
 * string param_3 = obj->cursorLeft(k);
 * string param_4 = obj->cursorRight(k);
 */
 
 