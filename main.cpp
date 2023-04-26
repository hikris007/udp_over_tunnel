#include <iostream>
#include <vector>


int main() {
    std::cout << "Hello, World!" << std::endl;
    std::vector<int> list;
    list.push_back(1);
    list.push_back(2);
    std::vector<int>::iterator iterator = list.begin();
    std::cout << (iterator == list.end()) << " " << (*iterator++) << std::endl;
    std::cout << (iterator == list.end()) << " " << (*iterator) << std::endl;

    for(auto iii = list.begin();iii != list.end();iii++){
        std::cout << *iii << std::endl;
    }
    return 0;
}
