#include "graph.h"
#include <queue>

// Реализация функции поиска расстояния между двумя вершинами графа методом BFS
int bfs(const std::vector<std::vector<int>>& graph, int start, int end) {
    // Если начальная и конечная вершина совпадают
    if (start == end) return 0;

    // Вектор для хранения расстояний до каждой вершины, изначально -1 (не посещена)
    std::vector<int> distance(graph.size(), -1);
    std::queue<int> q;

    // Устанавливаем расстояние до стартовой вершины равным 0 и добавляем ее в очередь
    distance[start] = 0;
    q.push(start);

    // Пока очередь не пуста, обрабатываем вершины
    while (!q.empty()) {
        int current = q.front();
        q.pop();

        // Проходим по всем соседям текущей вершины
        for (int neighbor : graph[current]) {
            // Если сосед еще не посещен
            if (distance[neighbor] == -1) {
                // Устанавливаем расстояние
                distance[neighbor] = distance[current] + 1;

                // Если достигнута конечная вершина, возвращаем расстояние
                if (neighbor == end)
                    return distance[neighbor];

                // Добавляем соседа в очередь для дальнейшей обработки
                q.push(neighbor);
            }
        }
    }

    // Если путь не найден, возвращаем -1
    return -1;
}

// Инициализация списка людей и создание отображения имен в индексы
void initializePeople(std::vector<Person>& people, std::unordered_map<std::string, int>& nameToIndex) {
    // Добавляем людей в список
    people.push_back({ "Олег", 0 });
    people.push_back({ "Женя", 1 });
    people.push_back({ "Ирина", 2 });
    people.push_back({ "Максим", 3 });
    people.push_back({ "Света", 4 });
    people.push_back({ "Алексей", 5 });

    // Создаем отображение: имя -> индекс
    for (const auto& p : people) {
        nameToIndex[p.name] = p.index;
    }
}

// Построение графа связей между людьми
void buildGraph(const std::vector<Person>& people, std::vector<std::vector<int>>& graph) {
    int n = people.size();
    graph.resize(n); // выделение памяти для графа

    // Добавление связей (ребер) между людьми
    // Олег — Женя
    graph[0].push_back(1);
    graph[1].push_back(0);
    // Женя — Ирина
    graph[1].push_back(2);
    graph[2].push_back(1);
    // Ирина — Максим
    graph[2].push_back(3);
    graph[3].push_back(2);
    // Максим — Света
    graph[3].push_back(4);
    graph[4].push_back(3);
    // Света — Алексей
    graph[4].push_back(5);
    graph[5].push_back(4);
}