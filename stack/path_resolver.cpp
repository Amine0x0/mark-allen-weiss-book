#include <iostream>
#include <stack>
#include <vector>
#include <sstream>

std::stack<std::string> st; 
std::vector<std::string> array;

void splitme(const std::string& in, char delim){
    std::stringstream input(in);
    std::string buffer;
    while (getline(input, buffer, delim)){
        if (buffer.empty())
            continue;
        array.push_back(buffer);
    }
}

void show(){
    for (const auto& x: array)
        std::cout << x << std::endl;
}

bool resolver(const std::string& input){
    splitme(input, '/');
    for (const auto& x: array){
        if (x == ".") {
            continue; 
        }
        if (x == "..") {
            if (!st.empty()) {
                st.pop();
            }
            continue;
        }
        st.push(x);   
    }
    return true;
}

int main(){
    std::string path = "/home////amine/.././../Desktop/Project1/dbg";
    // splitme(path, '/');
    // show();
    
    array.clear(); 
    resolver(path);
    std::string result = "";
    std::vector<std::string> final_path;
    while (!st.empty()) {
        final_path.insert(final_path.begin(), st.top());
        st.pop();
    }
    for (const auto& dir : final_path) {
        result += "/" + dir;
    }
    std::cout << (result.empty() ? "/" : result) << std::endl;

    return 0;
}