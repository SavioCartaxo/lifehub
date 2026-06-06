#include <iostream>
#include "models/TaskManager.hpp"
#include <cstdlib>
#include "database/Database.hpp"

lifehub::TaskManager* tm_ptr = nullptr;

int menu() {
    lifehub::TaskManager& tm = *tm_ptr;

    std::cout << "==================================================" << '\n';
    std::cout << "1 -              Adicionar Task                   " << '\n';
    std::cout << "2 -            Ver Tasks Existentes               " << '\n';
    std::cout << "3 -               Editar Tasks                    " << '\n';
    std::cout << "4 -               Remover Tasks                   " << '\n';
    std::cout << "0 -                    Sair                       " << '\n';
    std::cout << "==================================================" << '\n';

    std::string input;
    std::getline(std::cin >> std::ws, input);
    int option;
    if (input.size() == 1 && std::isdigit(input[0]) && std::stoi(input) < 5) {
        option = std::stoi(input);
    } else {
        option = 10;
    }

    switch (option) {
        case 1: {
            std::string title, activity_type;
            std::cout << "Title: ";
            std::getline(std::cin >> std::ws, title);
            std::cout << "Activity type: ";
            std::getline(std::cin >> std::ws, activity_type);
            tm.addTask(title, activity_type);
            std::cout << "Task adicionada!" << '\n';
            system("pause");
            return 1;
        }
        case 2: {
            std::vector<std::string> tasks = tm.listTasks();
            std::cout << '\n';
            for (const auto& task : tasks)
                std::cout << "- " << task << '\n';
            std::cout << '\n';
            system("pause");
            return 1;
        }
        case 3: {
            std::string title;
            std::cout << "Nome da task: ";
            std::getline(std::cin >> std::ws, title);
            int editOption;
            std::cout << '\n';
            std::cout << "1 - Alterar descricao" << '\n';
            std::cout << "2 - Finalizar task" << '\n';
            std::cout << "3 - Adicionar tempo" << '\n';
            std::cin >> editOption;
            switch (editOption) {
                case 1: {
                    std::string description;
                    std::cout << "Nova descricao: ";
                    std::getline(std::cin >> std::ws, description);
                    tm.setTaskDescription(title, description);
                    std::cout << "Descricao alterada!" << '\n';
                    break;
                }
                case 2: {
                    tm.finishTask(title);
                    std::cout << "Task finalizada!" << '\n';
                    break;
                }
                case 3: {
                    double time;
                    std::cout << "Tempo a adicionar: ";
                    std::cin >> time;
                    tm.increaseTimeTask(title, time);
                    std::cout << "Tempo adicionado!" << '\n';
                    break;
                }
                default:
                    std::cout << "Opcao invalida!" << '\n';
            }
            system("pause");
            return 1;
        }
        case 4: {
            std::string title;
            std::cout << "Nome da task: ";
            std::getline(std::cin >> std::ws, title);
            tm.removeTask(title);
            std::cout << "Task removida!" << '\n';
            system("pause");
            return 1;
        }
        case 0:
            return 0;
        default:
            std::cout << "Opcao invalida!" << '\n';
            system("pause");
            return 1;
    }
}

int main() {
    Database database;
    if (!database.open()) {
        std::cout << "Erro ao abrir banco\n";
        return 1;
    }
    lifehub::TaskManager tm(database);
    tm_ptr = &tm;

    while (menu()) {
        system("cls");
    }

    std::cout << "Adeus para sempre" << '\n';
    database.close();
    return 0;
}