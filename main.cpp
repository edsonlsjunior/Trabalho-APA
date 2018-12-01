#include <iostream>
#include <iomanip>
#include "Sort.cpp"
#include "MSTree.h"
#include "Rod.h"
#include "FileUtils.h"

using namespace std;


unsigned int numberOfExecutions = 30;

string incrementalPath = "insert-instances/";
string divConqPath = "merge-instances/";
string dynamicPath = "rod-instances/";
string greedyPath = "graph-instances/";

void incrementalModule(string& instancePath);
void DivConqModule(string &instancePath);
void dynamicPModule(string &instancePath);
void greedyModule(string &instancePath);

void instanceListReader(string& instanceList, int chosen);

int main()
{
    int chosen = 5;
    string instancePath;

    do
    {
        if (chosen >= 0 && chosen < 5)
            instanceListReader(instancePath, chosen);

        else if (chosen == 5)
        {
            cout << "Digite o path da lista de instancias: ";
            cin >> instancePath;
        }
        else
            cout << "Opcao invalida!\n";


        cout << "\nDigite o paradigma a ser utilizado\n";
        cout << "1 - Incremental\n";
        cout << "2 - Divisao e conquista\n";
        cout << "3 - Programacao dinamica\n";
        cout << "4 - Algoritmo guloso\n";
        cout << "5 - Mudar path da lista de instancias\n";
        cout << "0 - Sair\n";
        cin >> chosen;
    }while (chosen != 0);
    return 0;
}

void instanceListReader(string& instanceList, int chosen)
{
    string instance;
    ifstream inputList;
    inputList.open(instanceList);

    if (inputList.is_open())
    {
        while (inputList >> instance)
        {
            cout << "Executando a instancia "<< instance << endl;
            if (chosen == 1)
                incrementalModule(instance);
            else
            if (chosen == 2)
                DivConqModule(instance);
            else
            if (chosen == 3)
                dynamicPModule(instance);
            else
            if (chosen == 4)
                greedyModule(instance);
        }
    }
    else
        cout << "Falha na leitura da lista de instancias!\n";
}

void incrementalModule (string& instancePath)
{
    ofstream output;
    output.open("incrementalOutput.csv", ofstream::app);

    vector<int> instance, copy;
    FileUtils::readIntegerInstance(instance, incrementalPath + instancePath);

    time_t begin;
    double end;

    output << instancePath;
    for (int i = 0; i < numberOfExecutions; ++i)
    {
        copy = instance;

        begin = clock();
        Sort::insertionSort(copy);
        end = (double) (clock() - begin)/CLOCKS_PER_SEC;

        output << setprecision(12) << ";" << end << ";\n";
    }
    output.close();
}

void DivConqModule(string &instancePath)
{
    ofstream output;
    output.open("divideOutput.csv", ofstream::app);

    vector<int> instance, copy;
    FileUtils::readIntegerInstance(instance, divConqPath + instancePath);

    time_t begin;
    double end;

    output << instancePath;
    for (int i = 0; i < numberOfExecutions; ++i)
    {
        copy = instance;

        begin = clock();
        Sort::mergeSort(copy);
        end = (double) (clock() - begin)/CLOCKS_PER_SEC;

        output << setprecision(12)<< ";" << end << ";\n";
    }
    output.close();
}

void dynamicPModule(string &instancePath)
{
    ofstream output;
    output.open("dynamicOutput.csv", ofstream::app);

    vector<int> instance, copy;
    FileUtils::readIntegerInstance(instance, dynamicPath + instancePath);

    time_t begin;
    double end;

    output << instancePath;
    for (int i = 0; i < numberOfExecutions; ++i)
    {
        copy = instance;

        begin = clock();
        Rod::cuttingRod(copy);
        end = (double) (clock() - begin)/CLOCKS_PER_SEC;

        output << setprecision(12) << ";" << end << ";\n";
    }
    output.close();
}

void greedyModule(string &instancePath)
{
    ofstream output;
    output.open("greedyOutput.csv", ofstream::app);

    vector<vector<int>> graph, copy;
    FileUtils::readGraphInstance(graph, greedyPath + instancePath);

    time_t begin;
    double end;

    output << instancePath;
    for (int i = 0; i < numberOfExecutions; ++i)
    {
        copy = graph;

        begin = clock();
        MSTree::primMST(copy);
        end = (double) (clock() - begin)/CLOCKS_PER_SEC;

        output << setprecision(12) << ";" << end << ";\n";
    }
    output.close();
}
