//
// Created by davim on 15/01/2022.
// research about asynotic complexity of std::map find, resource used in my code
// https://stackoverflow.com/questions/70604357/stdmap-with-stdvector-as-key-complexity-of-lookup-function
//

#include "core.h"
namespace core {
    std::string remove_multiple_chars(const std::string& in){
        std::string out = in;
        const char *p_s = out.c_str();
        std::map<char,int> m;
        int i=0;
        while (i<out.length()) { //N
            if (m.find(p_s[i])!=m.end()){ // (log(N))
                out.erase(i,1);
            }
            else{
                m.insert(std::pair<char, int>(p_s[i],1)); // 1
                i++;
            }
        }
        return out;
    }
};