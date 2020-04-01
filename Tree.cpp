#include <iostream>
#include <string>
#include "Tree.h"
#include <queue>

using namespace std;

//конструктор, с самого начала нет корня и узлов (*root = NULL, nodes_count = 0)
Tree::Tree() {
    root = NULL;
    nodes_count = 0;
}

//количество узлов
int Tree::get_nodes_count() {
    return nodes_count;
}

//вывод дерева, если есть корень идем в рекурсию, если нет выводим сообщение, что ничего нет
void Tree::show() {
    if (root) show_rec(root, 0, '*');
    else cout << "Ничего нет" << endl;
}

//реккурентная часть вывода
//выводи дерево в виде списка
//"*" - это корень
//"-" - левое поддерево
//"+" - правое поддерево
//узлы ниже по уровню depth имеют больше пробелов: так получается свертывающиеся список
void Tree::show_rec(Node* root, int depth, char dir) {

    int n;
    if (!root) return;
    for (n = 0; n < depth; n++) cout << ' ';
    cout << dir << root->value << root->color << endl;
    show_rec(root->left, depth + 2, '-');
    show_rec(root->right, depth + 2, '+');
}

//вставка, создаем узел и указатель на него
//инициализируем ему значение, левый и правый черные нулевые листья, красный цвет
//если нет корня вставляем по алгоритму вставки корня
//если есть - по общему алгоритму
//балансируем
void Tree::insert(int value) {
    Node *n = new Node;
    nodes_count++;

    n->value = value;
    n->left = n->right = NULL;
    n->color = "red";

    if (root == NULL) insert_root(n);
    else insert_node(n, root);

    balance_insert(n);
}

//вставленный узел становится корнем, цвет корня всегда черный
void Tree::insert_root(Node* n) {
    root = n;
    root->color = "black";
}

//если вставляемое значение меньше(больше) корня и у корня нет левого(правого) потомка, инициализуем корню указатель на его левого потомка
//у вставляемого узла делаем указатель на родителя, а именно на корень
//если вставляемое значение меньше(больше) корня и левый(правый) потомок есть, то реккурсивно проходимся по дереву
void Tree::insert_node(Node* n, Node* root) {
    if (n->value < root->value && root->left == NULL) { root->left = n; n->parent = root; return; }
    if (n->value > root->value&& root->right == NULL) { root->right = n; n->parent = root; return; }
    if (n->value < root->value && root->left != NULL) insert_node(n, root->left);
    if (n->value > root->value && root->right != NULL) insert_node(n, root->right);
}

//балансировка дерева после вставки
//если у узла нет родителя (это корень), или родитель черный, балансировка не нужна
//если дядя существует проверяем его цвет, если нет, то дядя - это черный нулевой элемент
//если и дядя и родитель красные просто перекрашиваем
//если нет, что проверяем в одну линию ли они выстроены, метод line()
void Tree::balance_insert(Node* n) {
    if (!n->parent || n->parent->color == "black") return;
    if (n->uncle()) {
        if (n->parent->color == "red" && n->uncle()->color == "red") repainting(n);
        if (n->parent->color == "red" && n->uncle()->color == "black") line(n);
    }
    if (!n->uncle()) {
        line(n);
    }
  
}

//случай балансировки  1: родитель и дядя красные, 
//перекрашиваем родителя и дядю в черный, а дедушку в красный (или черный, если корень)
void Tree::repainting(Node* n) {
    n->parent->color = "black";
    n->uncle()->color = "black";
    if (n->grandparent() == root) n->grandparent()->color = "black";
    else n->grandparent()->color = "red";
   
}

//случай балансировки 3:  родитель красный, дядя черный, дед, родитель и сын не находятся на одной "линии"(сначала проверяем), 
//если не на одной линии
//делаем поворот, чтобы выровнять, а потом второй поворот в методе rotate
//если на одной сразу делаем второй поворот в методе rotate()
//pivot - вспомогательный указатель, указывает на родителя вставленного узла
//n становится корнем поддерева, меняя их местами мы одновременно делаем указатели влево или вправо и делаем указатели 
//на родителей, чтобы была двухсторонний связный список
//правой ветке pivot причисляем NULL, ибо его правый указатель указывает на n, которого уже там нет
//также все работает наоборот
void Tree::line(Node* n) {
    if (n == n->parent->right && n->parent == n->grandparent()->left) {
        Node* pivot = n->parent;
        pivot->parent->left = n;
        n->parent = pivot->parent;
        n->left = pivot;
        pivot->parent = n;
        pivot->right = NULL;
        rotate(n->left);
        return;
    }
    if (n == n->parent->left && n->parent == n->grandparent()->right) {
        Node* pivot = n->parent;
        pivot->parent->right = n;
        n->parent = pivot->parent;
        n->right = pivot;
        pivot->parent = n;
        pivot->left = NULL;
        rotate(n->right);
        return;
    }
    else {
        rotate(n);
        return;
    }
}

//случай балансировки 2: родитель красный, дядя черный, дед, родитель и сын находятся на одной "линии", 
//делаем один поворот, при этом родитель перекрашивается в черный, а дедушка в красный
void Tree::rotate(Node* n) {
    n->parent->color = "black";
    n->grandparent()->color = "red";
    if (n == n->parent->left && n->parent == n->grandparent()->left) rotate_right(n->grandparent());
    if (n == n->parent->right && n->parent == n->grandparent()->right) rotate_left(n->grandparent());
}

//поворот влево
//снова делаем вспомогательный указатель
//если у pivot есть дедушка, значит нужно связать наше поддерево с этим дедушкой
//если его нет то pivot при повороте станет вершиной, а значит и корнем
//дальше принцип похож с предыдущими поворотами
void Tree::rotate_left(Node* n) {
    Node* pivot = n->right;
    if (pivot->grandparent()) {
        pivot->grandparent()->right = pivot;
        pivot->parent = pivot->grandparent();
    }
    else {
        root = pivot;
        root->parent = NULL;
    }
    pivot->left = n;
    n->parent = pivot;
    n->right = NULL;
}

//поворот вправо
//то же самое просто наоборот
void Tree::rotate_right(Node*n) {
    Node* pivot = n->left;
    if (pivot->grandparent()) {
        pivot->grandparent()->right = pivot;
        pivot->parent = pivot->grandparent();
    }
    else root = pivot;
    pivot->right = n;
    n->parent = pivot;
    n->left = NULL;
}

//находим дедушку - родителя родителя, если он существует конечно
Tree::Node* Tree::Node::grandparent() {
    if (parent->parent) return parent->parent;
    else return NULL;
}

//находим дядю
//если нет дедушки, нет и дяди
Tree::Node* Tree::Node::uncle() {
    if (!grandparent()) return NULL;
    if (grandparent()->left == parent) return grandparent()->right;
    else return grandparent()->left;
}

//поиск узла
Tree::Node* Tree::search(int value) {
    return search_rec(value, root);
}

//реккурентная часть
Tree::Node* Tree::search_rec(int value, Node* root) {
    if (value == root->value) return root;
    if (value < root->value) return search_rec(value, root->left);
    if (value > root->value) return search_rec(value, root->right);
    if (root->value == NULL) cout << "Такого узла нет" << endl;
}

//Сначала находим старый узел, который будем удалять, потом - новый узел, макс элемент в левом поддереве
//Если у вершины нет детей, то изменяем указатель на неё у родителя на nil.
//Если у неё только один ребёнок, то делаем у родителя ссылку на него вместо этой вершины.
//Если же имеются оба ребёнка, то находим максимальный элемент в левом поддереве, заменяем им удаляемую вершину
void Tree::remove(int value) {
    Node* old_node = search(value);
    Node* new_node = max_left(old_node);
    if (old_node == new_node) {
        if (old_node == old_node->parent->left) {
            old_node->parent->left = NULL;
        }
        if (old_node == old_node->parent->right) {
            old_node->parent->right = NULL;
        }
        delete old_node;
        nodes_count--;
        return;
    }
    if (new_node->left) {
        new_node->parent->right = new_node->left;
        new_node->left->parent = new_node->parent;
    }
    if (new_node->right) {
        new_node->parent->right = new_node->right;
        new_node->right->parent = new_node->parent;
    }

    if (old_node->parent) {
        new_node->parent = old_node->parent;
        if (old_node->parent->right == old_node) old_node->parent->right = new_node;
        if (old_node->parent->left == old_node) old_node->parent->left = new_node;
    }
    if (old_node->left && old_node->left != new_node) {
        new_node->left = old_node->left;
        new_node->left->parent = new_node;
    }
    if (old_node->right) {
        new_node->right = old_node->right;
        new_node->right->parent = new_node;
    }
    if (old_node == root) {
        root = new_node;
        root->parent = NULL;
    }
    
    delete old_node;
    nodes_count--;
    if(new_node->color == "red" && new_node->parent->color == "red") balance_insert(new_node);
}


Tree::Node* Tree::max_left(Node* root) {
    if (!root->left) return root;
    else {
        return max_left_rec(root->left);
    }
}

Tree::Node* Tree::max_left_rec(Node* root) {
    if (root->right) {
        max_left_rec(root->right);
    }
    else return root;
}

void Tree::balance_remove(Node*) {


}

