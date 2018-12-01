
#ifndef FILEUTILS_H
#define FILEUTILS_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>

using namespace std;

class FileUtils {
public:
    static void readIntegerInstance(vector<int> &instance, string name);
    static void readGraphInstance(vector<vector<int>>& graph, string name);

private:
    static int euclideanDist(pair<int,int> p1, pair<int,int> p2);
};


#endif //TRABALHO_APA_FILEUTILS_H
