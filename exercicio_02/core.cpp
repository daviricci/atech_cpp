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
        //N
        while (i<out.length()) { //1
            if (m.find(p_s[i])!=m.end()){ // (log(i)), i<K, K é a quantindade de caracteres não repetidos da string
                out.erase(i,1);// 1
            }
            else{
                m.insert(std::pair<char, int>(p_s[i],1)); // 1
                i++;
            }
        }
        return out;
    }
    /*
     * Para determinação da complexidade assintótica, foi considerado
     * a complexidade assintótica do método find da classe std::map,
     * uma vez que esse recurso foi utilizado.
     * A função foi feita de tal forma que uma única varredura pela
     * string fosse o suficiente para encontrar todos os caracteres duplicados.
     * Para isso foi utilizado a estrutura std::map para armazenar novos
     * caracteres encontrados e para verificar a ocorrência de repetições.
     * Caso algum caractere já tiver sido armazenado na estrutura std::map,
     * onde isso é verificado pela função find da classe std::map, esse é
     * removido da string analisada.
     * Ao chegar no último caractere da string, ter-se-á obtido uma string
     * sem caracteres repetidos.
     * Assim temos:
     * N -> número de caracteres totais da string
     * K -> número de caracteres não repetidos da string
     * W -> número de execuções por iteração
     * onde K<=W
     * Portanto a complexidade assintótica pode ser estimada da seguinte forma:
     *
     * W
     *           +
     * W + log(1) // existe um caractere na estrutura que se busca se o caractere analisado já foi ou não encontrado
     *           +
     * W + log(2) // existem dois caracteres na estrutura que se busca se o caractere analisado já foi ou não encontrado
     *            +
     * .
     * .
     * .
     *            +
     * W + log(K) // existem K caracteres na estrutura que se busca se o caractere analisado já foi ou não encontrado
     *            +
     * W + log(K)
     * .
     * .
     * .
     *            +
     * W + log(K)
     *
     * Assim podemos dizer que a complexidade assintótica sera de O(N*log(N)).
     * */
};