#include <iostream>
#include <string>
using namespace std;

template <class T>
class List{
      class Node{
      public:
          Node *pNext;
          T data;

          explicit Node(T data = T(), Node *pNext = nullptr){
              this->pNext = pNext;
              this->data  = data;
          }
      };
    Node *head;
    int size;
public:
    List();
    ~List();
    void push_front(T data);
    void push_back(T data);
    T pop_front();
    T pop_back();
    void insert(T data, int index);
    T removeAt(int index);
    void clear();
    int getSize();
    T& operator[](int index);
};

template<class T>
List<T>::List() {
    head = nullptr;
    size = 0;
}

template<class T>
List<T>::~List() {
    clear();
}

template<class T>
void List<T>::push_front(T data) {
    /*Создаем новую ноду с данными data и указателем, который соответсвовал первой ноде
     * Теперь присваиваем head эту ноду, и она становится первой в списке*/
    head = new Node(data, head);
    size++;
}

template<class T>
void List<T>::push_back(T data) {
    /*Если лист пустой создаем ноду, иначе двигаемся по указателю, пока он не станет пустым и добавляем ноду*/
    if (head == nullptr){
        head = new Node(data);
    }
    else{
        Node *current = this->head;
        while(current->pNext != nullptr){
            current = current->pNext;
        }
        current->pNext = new Node(data);

    }
    size++;
}

template<class T>
T List<T>::pop_front() {
    /*Создаем временную ноду, которой присваиваем поля head
     * Присваиваем head поля следующей ноды
     * Удаляем временную ноду, тем самым удаляем первноначальный head*/
    T firstData = head->data;
    Node *tmp = head;
    head = head->pNext;
    delete tmp;
    size--;
    return firstData;
}

template<class T>
T List<T>::pop_back() {
    /*Создаем временную ноду, которой присваиваем поля head
     * Присваиваем временной ноде поля следующих, пока не дойдем до предпоследней
     * Сохраняем ее data в переменную и присваиваем ей нулевой указатель*/
    T lastData;
    Node *previous = head;
    for (int i = 0; i < size - 1; ++i) {
        previous = previous->pNext;
    }
    lastData = previous->data;
    previous = nullptr;
    size--;
    return lastData;
}

template<class T>
void List<T>::insert(T data, int index) {
    if (index == 0){
        push_front(data);
    }
    else if (index == size){
        push_back(data);
    }
    else {
        /*Создаем временную ноду, которой присваиваем поля head
         * Присваиваем временной ноде поля следующих, пока не дойдем до предпредпоследней по индексу
         * Создаем новую ноду, которой присваиваем data и указатель предпоследней по индексу ноду
         * Предпоследней по индексу ноде присваиваем указатель на новую ноду*/
        Node *previous = head;
        for (int i = 0; i < index - 2; ++i) {
            previous = previous->pNext;
        }
        Node *newNode = new Node(data, previous->pNext);
        previous->pNext = newNode;

        size++;
    }
}

template<class T>
T List<T>::removeAt(int index) {
    T delData;
    if (index == 0){
        delData = pop_front();
    }
    else if (index == size){
        delData = pop_back();
    }
    else {
        Node *previous = head;
        for (int i = 0; i < index - 1; ++i) {
            previous = previous->pNext;
        }
        Node *toDelete = previous->pNext;
        previous->pNext = toDelete->pNext;
        delData = toDelete->data;
        delete toDelete;
        size--;
    }
    return delData;
}

template<class T>
int List<T>::getSize() {
    return size;
}

template<class T>
T &List<T>::operator[](const int index) {
    Node *current = this->head;
    int count = 0;
    bool countNotEqualIndex = true;

    while (current != nullptr && countNotEqualIndex){
        if(count == index){
            countNotEqualIndex = false;
        }
        else {
            current = current->pNext;
            count++;
        }
    }
    return current->data;
}

template<class T>
void List<T>::clear() {
    while (size){
        pop_front();
    }
}

int main(){
    List<string> lst;
    lst.push_back("first");
    lst.push_back("second");
    lst.push_back("third");

/*   for (int i = 0; i < lst.getSize(); ++i) {
        cout << "Data in " << i << " node: " << lst[i] << endl;

    }
    cout << "Size: " << lst.getSize() << endl << endl;

    cout << "pop_front" << endl;
    lst.pop_front();

    for (int i = 0; i < lst.getSize(); ++i) {
        cout << "Data in " << i << " node: " << lst[i] << endl;

    }
    cout << "Size: " << lst.getSize() << endl << endl;

    cout << "push_front" << endl;
    lst.push_front("fourth");
    for (int i = 0; i < lst.getSize(); ++i) {
        cout << "Data in " << i << " node: " << lst[i] << endl;

    }
    cout << "Size: " << lst.getSize() << endl << endl;

    cout << "pop_back" << endl;
    lst.pop_back();
    for (int i = 0; i < lst.getSize(); ++i) {
        cout << "Data in " << i << " node: " << lst[i] << endl;

    }
    cout << "Size: " << lst.getSize() << endl << endl;

    cout << "insert" << endl;
    lst.insert("fifth", 1);
    for (int i = 0; i < lst.getSize(); ++i) {
        cout << "Data in " << i << " node: " << lst[i] << endl;

    }
    cout << "Size: " << lst.getSize() << endl << endl;

    cout << "removeAt" << endl;
    lst.removeAt(1);
    for (int i = 0; i < lst.getSize(); ++i) {
        cout << "Data in " << i << " node: " << lst[i] << endl;

    }
    cout << "Size: " << lst.getSize() << endl << endl;*/

    cout << "insert" << endl;
    lst.insert("fifth", 1);
    for (int i = 0; i < lst.getSize(); ++i) {
        cout << "Data in " << i << " node: " << lst[i] << endl;

    }
    cout << "Size: " << lst.getSize() << endl << endl;
    return 0;
}