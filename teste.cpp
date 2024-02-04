// main.cpp

#include "Loader.h"
#include <iostream>

int main() {
    Loader::Build([](Loader& props) {
        props.Files({
            {"file1", "/dirA"},
            {"file2", "/dirB"},
            {"file3", "/DirC"}
        });
        props.Events([](Loader::Events& events) {
        
            events.onJob = []() {
                std::cout << "Lendo dados de progresso dos downloads ......\n";
            };
            events.onErrors = []() {
                std::cerr << "Erros que serão disparados cado aconteçam falhas no processo de Download\n";
            };
        });
    }).Download();

    return 0;
}
