#pragma once
#include <string>
#include <vector>
class Scanner {
public:
    Scanner(std::string input){
        
        for(int i=0;i<input.length();i++){
            std::string tmp= "";
            int tokenLen=0;
            isToken(input,i,tokenLen,tmp);
            if(tokenLen != 0){
                t.push_back(tmp);
            }
        }
        
        std::string tmp_double = "";
        for(int i=0;i<=input.length();i++){
            if(isNumber(input[i])){
                tmp_double+=input[i];
            }else{
                if(tmp_double != ""){
                    d.push_back(std::stod(tmp_double));
                    tmp_double="";
                }
            }
        }
    }

    std::string next() {
        if (t_isDone())
            throw "error";

        std::string result =t[t_pos];
        t_pos++;
        return result;
    }

    double nextDouble() {
        if (d_isDone())
            throw "error";

        double result=d[d_pos];
        d_pos++;   
        return result;
    }

    bool isDone() {
        return (d_pos ==d.size() && t_pos == t.size());
    }

private:
    const std::vector<std::string> tokenList = {"Circle", "Rectangle", "Triangle", "CompoundShape", "(", ")", "[", "]", "{", "}", ","};
    std::vector<std::string> t;
    std::vector<double> d;
    int t_pos = 0;
    int d_pos = 0;

    void isToken(std::string input,int pos,int &n,std::string &s){
        for(auto token: tokenList) {
            if(input.compare(pos, token.length(), token) == 0) {
                n=token.length();
                s=token;
                break;
            }
        }
    }
    
    bool isNumber(char s){
        if(((s <= '9' && s >= '0') )|| s == '.')
            return true;
        else
            return false;
    }

    bool d_isDone(){
        return d_pos == d.size();
    }

    bool t_isDone(){
        return t_pos == t.size();
    }

    void skipWhiteSpace() {}
};