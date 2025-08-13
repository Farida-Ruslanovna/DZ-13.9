#pragma once
#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <string>
#include <unordered_map>

// ��������� ��� �������� ���������� � ��������
struct Person {
    std::string name; // ��� ��������
    int index;        // ������ � �����
};

// ���������� ������� ������ ������������ ���������� ����� ����� ��������� ����� � ������� BFS
int bfs(const std::vector<std::vector<int>>& graph, int start, int end);

// ���������� ������� ��� ������������� ������ ����� � ����������� ���� � �������
void initializePeople(std::vector<Person>& people, std::unordered_map<std::string, int>& nameToIndex);

// ���������� ������� ��� ���������� ����� ������ ����� ������
void buildGraph(const std::vector<Person>& people, std::vector<std::vector<int>>& graph);

#endif // GRAPH_H
