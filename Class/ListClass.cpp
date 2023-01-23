#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

class Mobile
{
private:
    string name;
    string price;
    string ram;
    string storage;
    string country;
    string year;
    string screen;
    string camera;
    string battery;
    string processor;

public:
    Mobile()
    {
        cout << "Введите имя: ";
        cin >> this->name;
        cout << "Введите цену: ";
        cin >> this->price;
        cout << "Введите объем ОЗУ: ";
        cin >> this->ram;
        cout << "Введите объем памяти: ";
        cin >> this->storage;
        cout << "Введите страну производителя: ";
        cin >> this->country;
        cout << "Введите год выпуска: ";
        cin >> this->year;
        cout << "Введите тип экрана: ";
        cin >> this->screen;
        cout << "Введите разрешение камеры: ";
        cin >> this->camera;
        cout << "Введите объем батареи: ";
        cin >> this->battery;
        cout << "Введите процессор: ";
        cin >> this->processor;
    }
    Mobile(string name, string price, string ram, string storage, string country, string year, string screen, string camera, string battery, string processor)
    {
        this->name = name;
        this->price = price;
        this->ram = ram;
        this->storage = storage;
        this->country = country;
        this->year = year;
        this->screen = screen;
        this->camera = camera;
        this->battery = battery;
        this->processor = processor;
    }
    void setName(string name)
    {
        this->name = name;
    }
    void setPrice(string price)
    {
        this->price = price;
    }
    void setRam(string ram)
    {
        this->ram = ram;
    }
    void setStorage(string storage)
    {
        this->storage = storage;
    }
    void setCountry(string country)
    {
        this->country = country;
    }
    void setYear(string year)
    {
        this->year = year;
    }
    void setScreen(string screen)
    {
        this->screen = screen;
    }
    void setCamera(string camera)
    {
        this->camera = camera;
    }
    void setBattery(string battery)
    {
        this->battery = battery;
    }
    void setProcessor(string processor)
    {
        this->processor = processor;
    }

    string getName()
    {
        return this->name;
    }
    string getPrice()
    {
        return this->price;
    }
    string getRam()
    {
        return this->ram;
    }
    string getStorage()
    {
        return this->storage;
    }
    string getCountry()
    {
        return this->country;
    }
    string getYear()
    {
        return this->year;
    }
    string getScreen()
    {
        return this->screen;
    }
    string getCamera()
    {
        return this->camera;
    }
    string getBattery()
    {
        return this->battery;
    }
    string getProcessor()
    {
        return this->processor;
    }
};

class List
{
private:
    Mobile* data;
    List* next;
public:
    List()
    {
        this->data = nullptr;
        this->next = nullptr;
    }
    ~List()
    {
        cout << "Удаление элемента с адресом " << this << endl;
        delete this->data;
        delete this;
    }
    void setData()
    {
        this->data = new Mobile;
    }
    void setNext(List *next)
    {
        this->next = next;
    }

    Mobile* getData()
    {
        return this->data;
    }
    List* getNext()
    {
        return this->next;
    }
};

class MobileList
{
private:
    List *head;
    List* now;
public:
    MobileList()
    {
        head = nullptr;
        now = head;
    }

    void isEmpty()
    {
        if (head == nullptr)
        {
            cout << "Список пуст" << endl;
        }
        else
        {
            cout << "Список не пуст" << endl;
        }
    }

    int size() {
        int count = 0;
        List* temp = head;
        if(head == nullptr)
        {
            cout << "Список пуст" << endl;
            return 0;
        }
        else
        {
            count++;
            while (temp->getNext() != head)
            {
                count++;
                temp = temp->getNext();
            }
            cout << "Размер списка: " << count << endl;
            return count;
        }
    }

    void addBack() {
        List* newNode = new List;
        newNode->setData();
        if (head == nullptr) {
            // If the list is empty, the new node is the head and the tail.
            newNode->setNext(newNode);
            head = newNode;
        } else {
            // Otherwise, insert the new node at the end of the list.
            newNode->setNext(head);
            List* temp = head;
            while (temp->getNext() != head) {
                temp = temp->getNext();
            }
            temp->setNext(newNode);
        }
        // Reset the now pointer to the head of the list.
        now = head;
    }


    void clearAll()
    {
        if (head == nullptr)
        {
            cout << "Список пуст" << endl;
        }
        else
        {
            List* temp = head;
            while (temp->getNext() != head)
            {
                temp = temp->getNext();
            }
            temp->setNext(nullptr);
            while (head != nullptr)
            {
                temp = head;
                head = head->getNext();
                delete temp;
            }
            cout << "Список очищен" << endl;
        }
    }

    void moveForward() // for circular linked list
    {
        List *temp = this->now;
        if (temp == nullptr)
        {
            cout << "Список пуст" << endl;
        }
        else
        {
            cout << "Предыдущий элемент: " << temp << " Текущий элемент: " << temp->getNext() << endl;
            this->now = temp->getNext();

        }
    }

    void readInfo()
    {
            cout << "Название: " << this->now->getData()->getName() << endl;
            cout << "Цена: " << this->now->getData()->getPrice() << endl;
            cout << "Объем ОЗУ: " << this->now->getData()->getRam() << endl;
            cout << "Объем памяти: " << this->now->getData()->getStorage() << endl;
            cout << "Страна производителя: " << this->now->getData()->getCountry() << endl;
            cout << "Год выпуска: " << this->now->getData()->getYear() << endl;
            cout << "Тип экрана: " << this->now->getData()->getScreen() << endl;
            cout << "Разрешение камеры (МП): " << this->now->getData()->getCamera() << endl;
            cout << "Объем батареи: " << this->now->getData()->getBattery() << endl;
            cout << "Процессор: " << this->now->getData()->getProcessor() << endl;
    }

    void insertAfterCurrent() {

        List *newNode = new List;
        if(head == nullptr)
        {
            newNode->setNext(newNode);
            head = newNode;
            this->now = head;
            cout << "Список пуст, добавлен первый элемент" << endl;
        }
        else
        {
            newNode->setNext(this->now->getNext());
            this->now->setNext(newNode);
            this->now = newNode;
            cout << "Элемент добавлен и вы переместились к нему. Его адрес: " << this->now << endl;
        }
        newNode->setData();
    }

    void printAll() {
        List *temp = head;
        if (head == nullptr) {
            cout << "Список пуст" << endl;
        } else {
            while (temp->getNext() != head) {
                cout << "Название: " << temp->getData()->getName() << endl;
                temp = temp->getNext();
            }
            cout << "Название: " << temp->getData()->getName() << endl;
        }
    }
};

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    MobileList list;
    while(true)
    {
        int choice;
        cout << "Меню: " << endl;
        cout << "1. Проверить, пуст ли список" << endl;
        cout << "2. Получить размер списка" << endl;
        cout << "3. Добавить элемент в конец списка" << endl;
        cout << "4. Очистить весь список" << endl;
        cout << "5. Переместиться вперед" << endl;
        cout << "6. Считать информацию об элементе списка" << endl;
        cout << "7. Вставить элемент после текущего" << endl;
        cout << "8. Выйти" << endl;
        cout << "9. Вывести весь список (для проверки)" << endl;
        cout << "Введите свой выбор: " << endl;
        cin >> choice;

        if(choice == 1)
        {
            list.isEmpty();
        }
        if(choice == 2)
        {
            list.size();
        }
        if(choice == 3)
        {
            list.addBack();
        }
        if(choice == 4)
        {
            list.clearAll();
        }
        if(choice == 5)
        {
            list.moveForward();
        }
        if(choice == 6)
        {
            list.readInfo();
        }
        if(choice == 7)
        {
            list.insertAfterCurrent();
        }
        if(choice == 8)
        {
            break;
        }
        if(choice == 9)
        {
            list.printAll();
        }
    }
}


