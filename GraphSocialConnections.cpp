#include <iostream>
#include "graph.h"

int main() {

    setlocale(LC_ALL, "Russian");
    // Вектор для хранения данных о людях
    std::vector<Person> people;

    // Отображение: имя -> индекс
    std::unordered_map<std::string, int> nameToIndex;

    // Инициализация списка людей и создание отображения
    initializePeople(people, nameToIndex);

    // Объявляем граф и строим его с помощью функции buildGraph
    std::vector<std::vector<int>> graph;
    buildGraph(people, graph);

    // Выводим информацию о парах, которые знакомы через 2 или 3 рукопожатия
    std::cout << "Пары, знакомые через 1-3 рукопожатия:\n";

    // Перебираем все уникальные пары
    for (size_t i = 0; i < people.size(); ++i) {
        for (size_t j = i + 1; j < people.size(); ++j) {
            // Вычисляем расстояние между двумя людьми
            int dist = bfs(graph, people[i].index, people[j].index);

            // Если расстояние больше 1 и не равно -1, значит они знакомы через 2 или 3 рукопожатия
            if (dist > 1 && dist != -1 && dist <= 3) {
                std::cout << people[i].name << " - " << people[j].name << std::endl;
            }
        }
    }

    return 0;
}