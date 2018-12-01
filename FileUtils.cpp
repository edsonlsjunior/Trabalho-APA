#include "FileUtils.h"

void FileUtils::readIntegerInstance(vector<int> &instance, string name)
{
    ifstream input;
    input.open(name);
    unsigned long size;

    if (input.is_open())
    {
        input >> size >> size;

        instance.clear();
        instance.resize(size);

        for (int i = 0; i < size; ++i)
        {
            input >> instance[i];
        }
    }
    else
        cout << "falha na leitura da instancia: " << name << endl;
}

void FileUtils::readGraphInstance(vector<vector<int>> &graph, string name)
{
    ifstream input;
    input.open(name);
    unsigned long size;

    vector<pair<int, int>> coord;

    int x, y;

    if (input.is_open())
    {
        input >> size;

        graph.clear();
        graph.resize(size);
        for (int i = 0; i < size; ++i)
        {
            graph[i].clear();
            graph[i].resize(size);
        }

        for (int i = 0; i < size; ++i)
        {
            input >> x >> y;
            coord.emplace_back(x, y);
        }

        for (int i = 0; i < size; ++i)
            for (int j = 0; j < size; ++j)
                graph [i][j] = euclideanDist(coord[i], coord[j]);
        cout << "li\n";
    }
    else
        cout << "falha na leitura da instancia: " << name << endl;
}

int FileUtils::euclideanDist(pair<int, int> p1, pair<int, int> p2)
{
    return (int)sqrt((p1.first*p1.first - p2.first*p2.first)+(p1.second*p1.second - p2.second*p2.second));
}