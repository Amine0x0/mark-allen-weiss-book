#include <iostream>
#include <queue>

typedef struct node{
    std::string content;
    node* left;
    node* right;

}   node;

node* builder(std::string content){
    node* current = new node;
    current->content = content;
    current->left = nullptr;
    current->right = nullptr;
    return current;
}

void walk(node* root){
    if (!root)
        return ;
    
    std::cout << root->content << std::endl;
    walk(root->left);
    walk(root->right);
}

void seeder(node* root, std::queue<std::string>& content){
    if (content.empty())
        return;
    root->content = content.front();
    content.pop();
    if (!root->left){
        root->left = builder(content.front());
        seeder(root->left, content);
    }
    if (!root->right){
        root->right = builder(content.front());
        seeder(root->right, content);
    }
}

#include <deque>

std::queue<std::string> words(std::deque<std::string>{
    "apple", "bravo", "cyber", "delta", "echo", "falcon", "ghost", "helix",
    "index", "junction", "kernel", "logic", "matrix", "nexus", "omega", "pixel",
    "quantum", "router", "socket", "thread", "ultra", "vector", "widget", "xenic",
    "yield", "zone", "binary", "cache", "daemon", "engine", "firewall", "gateway",
    "hash", "interrupt", "jitter", "lock", "memory", "node", "packet", "query",
    "runtime", "stack", "token", "utility", "virtual", "window", "xenon", "yawn",
    "zero", "buffer", "compiler", "driver", "epoch", "format", "global", "heap",
    "instance", "journal", "key", "layout", "module", "network", "offset", "pointer"
});
int limit = words.size();

int main(){
    node* root = builder("god");
    seeder(root, words);
    walk(root);
}