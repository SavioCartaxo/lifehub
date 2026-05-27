#include <iostream>
#include "models/TaskManager.hpp"


lifehub::TaskManager tm;

int menu() {
    std::cout << "==================================================" << '\n';
    std::cout << "1 -              Adicionar Task                   " << '\n';
    std::cout << "2 -            Ver Tasks Existentes               " << '\n';
    std::cout << "3 -               Editar Tasks                    " << '\n';
    std::cout << "4 -               Remover Tasks                   " << '\n';
    std::cout << "0 -                    Sair                       " << '\n';
    std::cout << "==================================================" << '\n';

    int option;
    std::cin >> option;

    switch (option) {

        case 1: {
            std::string title, activity_type;

            std::cout << "Title: ";
            std::cin >> title;

            std::cout << "Activity type: ";
            std::cin >> activity_type;

            tm.addTask(title, activity_type);

            std::cout << "Task adicionada!" << '\n';
            return 1;
        }

        case 2: {
            std::vector<std::string> tasks = tm.listTasks();

            for (const auto& task : tasks) {
                std::cout << "- " << task << '\n';
            }

            return 2;
        }

        case 3: {
            std::string title;

            std::cout << "Nome da task: ";
            std::cin >> title;

            int editOption;

            std::cout << "\n1 - Alterar descricao" << '\n';
            std::cout << "2 - Finalizar task" << '\n';
            std::cout << "3 - Adicionar tempo" << '\n';

            std::cin >> editOption;

            switch (editOption) {

                case 1: {
                    std::string description;

                    std::cout << "Nova descricao: ";
                    std::cin >> description;

                    tm.setTaskDescription(title, description);

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

                    break;
                }

                default:
                    std::cout << "Opcao invalida!" << '\n';
            }

            return 1;
        }

        case 4: {
            std::string title;

            std::cout << "Nome da task: ";
            std::cin >> title;

            tm.removeTask(title);

            std::cout << "Task removida!" << '\n';
            return 4;
        }

        case 0:
            return 0;

        default:
            std::cout << "Opcao invalida!" << '\n';
            return 1;
    }
}

int main() {

    while (menu())

    std::cout << "Adeus para sempre" << '\n';

    return 0;
}