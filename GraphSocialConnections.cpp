#include <iostream>
#include "graph.h"

int main() {

    setlocale(LC_ALL, "Russian");
    // ������ ��� �������� ������ � �����
    std::vector<Person> people;

    // �����������: ��� -> ������
    std::unordered_map<std::string, int> nameToIndex;

    // ������������� ������ ����� � �������� �����������
    initializePeople(people, nameToIndex);

    // ��������� ���� � ������ ��� � ������� ������� buildGraph
    std::vector<std::vector<int>> graph;
    buildGraph(people, graph);

    // ������� ���������� � �����, ������� ������� ����� 2 ��� 3 �����������
    std::cout << "����, �������� ����� 1-3 �����������:\n";

    // ���������� ��� ���������� ����
    for (size_t i = 0; i < people.size(); ++i) {
        for (size_t j = i + 1; j < people.size(); ++j) {
            // ��������� ���������� ����� ����� ������
            int dist = bfs(graph, people[i].index, people[j].index);

            // ���� ���������� ������ 1 � �� ����� -1, ������ ��� ������� ����� 2 ��� 3 �����������
            if (dist > 1 && dist != -1 && dist <= 3) {
                std::cout << people[i].name << " - " << people[j].name << std::endl;
            }
        }
    }

    return 0;
}