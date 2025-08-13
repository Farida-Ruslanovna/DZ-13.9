#pragma once
#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <string>
#include <unordered_map>

// Структура для хранения информации о человеке
struct Person {
    std::string name; // Имя человека
    int index;        // Индекс в графе
};

// Объявление функции поиска минимального расстояния между двумя вершинами графа с помощью BFS
int bfs(const std::vector<std::vector<int>>& graph, int start, int end);

// Объявление функции для инициализации списка людей и отображения имен в индексы
void initializePeople(std::vector<Person>& people, std::unordered_map<std::string, int>& nameToIndex);

// Объявление функции для построения графа связей между людьми
void buildGraph(const std::vector<Person>& people, std::vector<std::vector<int>>& graph);

#endif // GRAPH_H
