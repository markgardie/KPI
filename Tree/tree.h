#pragma once
#include <iostream>
#include <string>

using namespace std;

class Tree {
private:
    class Node {
    public:
        Node* parent; //указатель на родителя                                                   
        int value;    //значение         
        bool color; //цвет, "red" - true, "black" - false
        Node* left; //указатель на левого потомка
        Node* right; //указатель на правого потомка
        Node* grandparent(); //метод ищет и возвращает указатель на деда 
        Node* uncle(); //метод ищет и возвращает указатель на дядю
    };
    Node* root; //указатель на корень
    int nodes_count; //количество узлов дерева
    void show_rec(Node*, int, char); //реккурентная часть вывода
    void insert_root(Node*); //вставка корня, при условии, что его нет 
    void insert_node(Node*, Node*); //вставка при всех других условиях
    void balance_insert(Node*); //балансировка дерева после вставки
    void balance_remove(Node*); //балансировка дерева после удаления
    void repainting(Node*); //случай балансировки  1: родитель и дядя красные, перекрашиваем родителя и дядю в черный, а дедушку в красный (или черный, если корень)
    void rotate(Node*); //случай балансировки 2: родитель красный, дядя черный, дед, родитель и сын находятся на одной "линии", делаем один поворот
    void line(Node*); //случай балансировки 3:  родитель красный, дядя черный, дед, родитель и сын не находятся на одной "линии", делаем поворот, чтобы выровнять, а потом второй поворот в методе rotate
    void rotate_left(Node*); //поворот влево
    void rotate_right(Node*); //поворот вправо
    Node* max_left(Node*); //находит максимальный элемент в левом поддереве
    Node* max_left_rec(Node*); //реккурентная часть поиска максимального элемента
    Node* search_rec(int, Node*); //реккурентная часть поиска
    

public:
    Tree(); //конструктор, с самого начала нет корня и узлов (*root = NULL, nodes_count = 0)
    ~Tree();
    int get_nodes_count(); //количество узлов
    void show(); //вывод дерева
    void insert(int); //вставка
    void remove(int); //удаление узла
    Node* search(int); //поиск и возврат узла
    
};
