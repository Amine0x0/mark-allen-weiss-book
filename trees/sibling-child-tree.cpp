#include <iostream>
#include <string>

typedef struct treenode{
    std::string content;
    treenode* firstChild;
    treenode* nextSibling;
} treenode;

void connector(treenode* root, treenode* next){
    if (!root || !next)
        return ;

    root->nextSibling = next;
}

treenode* builder(std::string content, treenode* sibling, treenode* child){
    treenode* current = new treenode;
    current->content = content;
    current->nextSibling = sibling;;
    current->firstChild = child;
    return current;
}

void walk(treenode* root){
    if (!root)
        return ;
    std::cout << root->content << std::endl;
    walk(root->firstChild);
    walk(root->nextSibling);
}

void makechild(treenode* node, treenode* child){
    if (node){
        node->firstChild = child;
    }
}

int main(){
    treenode* root = builder("/", nullptr, nullptr);
    treenode* folder1 = builder("usr/", nullptr, nullptr);
    treenode* folder2 = builder("bin/", nullptr, nullptr);
    treenode* folder3 = builder("tools/", nullptr, nullptr);
    
    makechild(folder1, builder("file.txt", nullptr, nullptr));
    makechild(folder2, builder("file2.txt", nullptr, nullptr));
    makechild(folder3, builder("file3.txt", nullptr, nullptr));
    root->firstChild = folder1; 
    connector(folder1, folder2);
    connector(folder2, folder3);
    walk(root);
    return (0);
}