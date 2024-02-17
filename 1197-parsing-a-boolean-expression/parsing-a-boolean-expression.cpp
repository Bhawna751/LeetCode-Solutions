class Solution {
public:
    bool parseBoolExpr(string expression){
        auto it = expression.begin();
        return parse(it);
    }    
    bool parse(string :: iterator &it){
        switch(*(it++)){
            case 't': return true;
            case 'f': return false;
            case '|': return parse(it,false, [](bool init, bool val){return init || val;});
            case '&': return parse(it,true, [](bool init, bool val){return init && val;});
            case '!': return parse(it,false, [](bool init, bool val){return !val;}); 
        }
        return false;
    }
    bool parse(string::iterator &it,bool init,function <bool(bool,bool)>op){
        it++;
        while(true){
            auto b = parse(it);
            init = op(init,b);
            if (*it == ')') break;
            it++;
        }
        it++;
        return init;
    }
};