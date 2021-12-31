//Nombres 1: Josue Gabriel Sumare Uscca++
//Nombres 2:Freddy Leonel Humpiri Valdivia+
//Nombres 3:MIGUEL ANGEL DEZA CUELA
//Fecha:18/10/2021
#include"BinaryTree.h"
#include"SimpleLinkedList.h"
#include <iostream>
#include <fstream>
#include <conio.h>
#include"AVL.h"
#include <ctime>
#include <chrono>
#include <vector>
#include <algorithm> 

using namespace std;

int main()
{

    string ubicacion_input ="ENTRADA.TXT";
    string palabra;
    ifstream input(ubicacion_input.c_str());
    SimpleLinkedList<string>my_linked_list;
    BinaryTree<string>tree;
    AVL<string>arbolAVL;

/*=============================== Tiempo en arbol alv ============================*/

    auto start_avl = chrono::high_resolution_clock::now(); //registra el inicio
    while(!input.eof()) {
        input >> palabra;
        arbolAVL.insertar(palabra);
    }
    input.close();
    auto end_avl = chrono::high_resolution_clock::now(); //registra el fin

    chrono::duration<float,milli> duracion_insercion_avl = end_avl-start_avl; //tiempo de duracion entre  start_avl y end_avl
    cout<<"En tiempo de insercion en el AVL es de "<<duracion_insercion_avl.count()<<" microsegundos.\n";

/*=============================== Tiempo en linked list ============================*/

    auto start_av2l = chrono::high_resolution_clock::now(); //registra el inicio
    while(!input.eof()) {
        input >> palabra;
        my_linked_list.pushFront(palabra);
    }
    input.close();
    auto end_av2l = chrono::high_resolution_clock::now(); //registra el fin

    chrono::duration<float,milli> duracion_insercion_ll = end_av2l-start_av2l;
    cout<<"En tiempo de insercion en la lista enlazada es de "<<duracion_insercion_ll.count()<<" microsegundos.\n";

/*=============================== Tiempo en binary tree  ============================*/

    auto start_tree = chrono::high_resolution_clock::now(); //registra el inicio
    while(!input.eof()) {
        input >> palabra;
        tree.insert(palabra);
    }
    input.close();
    auto end_tree = chrono::high_resolution_clock::now(); //registra el fin
    chrono::duration<float,milli> duracion_insercion_tree = end_tree-start_tree;
    cout<<"En tiempo de insercion en arbol es de "<<duracion_insercion_tree.count()<<" microsegundos.\n";

/*==============Prueba de busqueda========================*/

    int n = 10;     //numero de elementos a buscar
    vector<int> array;
    srand(9);
    for(int x=0;x<n;x++)
        array.push_back(rand() % 466550);

    sort(array.begin(), array.end());

    int cont=466550;

    std::ifstream myfile("ENTRADA.txt");
    if (myfile.is_open()){
        std::string string;
        while (!array.empty() && cont>-1){ 
            cont--;
            myfile >> string;
            if(cont==array.back()){
                cout<<"\n\nBuscando "<<string<<endl;
                //busqueda en binary tree
                tree.findRecursive(string);
                //cout<<"Busqueda finalizada en binary tree\n";
                //buscqueda en linked list
                my_linked_list.findRecursive(string);
                //cout<<"Busqueda finalizada en linked list\n";
                //busqueda en avl tree
                arbolAVL.buscar(string,arbolAVL.obtenerRaiz());
                //cout<<"Busqueda finalizada en avl tree";

                array.pop_back();
            }
        }
        std::cout<<std::endl;
    }
    else std::cout<<"El archivo no puede abrirse";
    return 0;
}
