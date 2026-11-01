#include <iostream>
#include <stack>

const std::string op_symbols = "{([";
const std::string cl_symbols = "])}";

typedef struct{
    typedef enum{
        OPENING,
        CLOSING,
        NONE,
    } symbol_type;

    bool is_symbol;
    symbol_type type;
}   t_symbol;

t_symbol isSymbol(char c){
    t_symbol symbol;
    for (auto x: op_symbols){
        if (x == c){
            symbol.is_symbol = true;
            symbol.type = symbol.OPENING;
            return symbol;
        }
    }

    for (auto x: cl_symbols){
        if (x == c){
            symbol.is_symbol = true;
            symbol.type = symbol.CLOSING;
            return symbol;
        }
    }

    symbol.is_symbol = false;
    symbol.type = symbol.NONE;
    return symbol;
}

bool balance(std::string& str){
    std::stack<char> s;

    for (auto x: str){
        t_symbol symbol = isSymbol(x);
        if (symbol.is_symbol){
            switch (symbol.type)
            {
                case symbol.OPENING:
                    s.push(x);
                    break;
                case symbol.CLOSING:
                    if (s.empty())
                        throw std::runtime_error("compiler error");
                    s.pop();
                    break;
                default:
                    throw std::runtime_error("undefined");
                    break;
            }
        }
        continue;
    }
    if (!s.empty())
        throw std::runtime_error("compiler error");
    return true;    
};

int main(){
    std::string in = "int main(){}[][][]()";
    try {
        balance(in);
        std::cout << "success" << std::endl;
    }
    catch(std::runtime_error& e){
        std::cerr << e.what() << std::endl;
    }
    return (EXIT_SUCCESS);
}