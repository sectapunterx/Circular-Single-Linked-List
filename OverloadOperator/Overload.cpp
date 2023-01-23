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

    bool operator > (Mobile &asd)
    {
        return (this->price > asd.price);
    }
    bool operator < (Mobile &asd)
    {
        return (this->price < asd.price);
    }
    bool operator == (Mobile &asd)
    {
        return (this->price == asd.price);
    }
    bool operator != (Mobile &asd)
    {
        return (this->price != asd.price);
    }
    bool operator >= (Mobile &asd)
    {
        return (this->price >= asd.price);
    }
    bool operator <= (Mobile &asd)
    {
        return (this->price <= asd.price);
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

    bool operator >(MobileList &list)
    {
        return (this->size() > list.size());
    }
    bool operator <(MobileList &list)
    {
        return (this->size() < list.size());
    }
    bool operator >=(MobileList &list)
    {
        return (this->size() >= list.size());
    }
    bool operator <=(MobileList &list)
    {
        return (this->size() <= list.size());
    }
    bool operator ==(MobileList &list)
    {
        return (this->size() == list.size());
    }
    bool operator !=(MobileList &list)
    {
        return (this->size() != list.size());
    }
    friend ostream& operator <<(ostream &out, MobileList* list)
    {
        out << "Название: " << list->now->getData()->getName() << endl;
        out << "Цена: " << list->now->getData()->getPrice() << endl;
        out << "Объем ОЗУ: " << list->now->getData()->getRam() << endl;
        out << "Объем памяти: " << list->now->getData()->getStorage() << endl;
        out << "Страна производителя: " << list->now->getData()->getCountry() << endl;
        out << "Год выпуска: " << list->now->getData()->getYear() << endl;
        out << "Тип экрана: " << list->now->getData()->getScreen() << endl;
        out << "Разрешение камеры (МП): " << list->now->getData()->getCamera() << endl;
        out << "Объем батареи: " << list->now->getData()->getBattery() << endl;
        out << "Процессор: " << list->now->getData()->getProcessor() << endl;
        return out;
    }

    void enterData(string& name, string& price)
    {
        List* temp = this->now;
        temp->getData()->setName(name);
        temp->getData()->setPrice(price);
        if (head == nullptr)
        {
            head = temp;
            head->setNext(head);
        }
        else
        {
            List* temp2 = head;
            while (temp2->getNext() != head)
            {
                temp2 = temp2->getNext();
            }
            temp2->setNext(temp);
            temp->setNext(head);
        }
    }
    void enterData(string& ram, string& storage, string& country){
        List* temp = this->now;
        temp->getData()->setRam(ram);
        temp->getData()->setStorage(storage);
        temp->getData()->setCountry(country);
        if (head == nullptr)
        {
            head = temp;
            head->setNext(head);
        }
        else
        {
            List* temp2 = head;
            while (temp2->getNext() != head)
            {
                temp2 = temp2->getNext();
            }
            temp2->setNext(temp);
            temp->setNext(head);
        }

    }
    void enterData(string& year, string& screen, string& camera, string& battery){
        List* temp = this->now;
        temp->getData()->setYear(year);
        temp->getData()->setScreen(screen);
        temp->getData()->setCamera(camera);
        temp->getData()->setBattery(battery);
        if (head == nullptr)
        {
            head = temp;
            head->setNext(head);
        }
        else
        {
            List* temp2 = head;
            while (temp2->getNext() != head)
            {
                temp2 = temp2->getNext();
            }
            temp2->setNext(temp);
            temp->setNext(head);
        }
    }

    void enterData(string& processor)
    {
        List* temp = this->now;
        temp->getData()->setProcessor(processor);
        if (head == nullptr)
        {
            head = temp;
            head->setNext(head);
        }
        else
        {
            temp->setNext(head);
            List* temp2 = head;
            while (temp2->getNext() != head)
            {
                temp2 = temp2->getNext();
            }
            temp2->setNext(temp);
        }
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
        cout << this << endl;
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

};

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    MobileList list;
    MobileList list1;
    while(true)
    {
        cout << "1. Заполнить список номер 1" << endl;
        cout << "2. Заполнить список номер 2" << endl;
        cout << "3. Сравнить списки" << endl;
        cout << "4. Выход с программы" << endl;
        int choicee;
        cin >> choicee;

        switch (choicee) {
            case 1:
                int choice;
                cout << "Меню: " << endl;
                cout << "1. Проверить, пуст ли список" << endl;
                cout << "2. Получить размер списка" << endl;
                cout << "3. Добавить элемент после текущего" << endl;
                cout << "4. Очистить весь список" << endl;
                cout << "5. Переместиться вперед" << endl;
                cout << "6. Считать информацию об элементе списка" << endl;
                cout << "7. Вставить элемент в конец списка" << endl;
                cout << "8. Изменить значение элемента" << endl;
                cout << "9. Выйти" << endl;
                cout << "Введите свой выбор: " << endl;
                cin >> choice;

                switch (choice) {
                    case 1:
                        list.isEmpty();
                        break;
                    case 2:
                        list.size();
                        break;
                    case 3:
                        list.addBack();
                        break;
                    case 4:
                        list.clearAll();
                        break;
                    case 5:
                        list.moveForward();
                        break;
                    case 6:
                        list.readInfo();
                        break;
                    case 7:
                        list.insertAfterCurrent();
                        break;
                    case 8:
                        cout << "1. Изменить имя, цену " << endl;
                        cout << "2. Изменить объем ОЗУ, объем памяти, страну" << endl;
                        cout << "3. Изменить год, экран, камеру, батарею" << endl;
                        cout << "4. Изменить процессор" << endl;
                        int choice1;
                        cin >> choice1;
                        switch (choice1) {
                            case 1: {
                                cout << "Введите имя: " << endl;
                                string name;
                                cin >> name;
                                cout << "Введите цену: " << endl;
                                string price;
                                cin >> price;
                                list.enterData(name, price);
                                break;
                            }
                            case 2: {
                                cout << "Введите объем ОЗУ: " << endl;
                                string RAM;
                                cin >> RAM;
                                cout << "Введите объем памяти: " << endl;
                                string memory;
                                cin >> memory;
                                cout << "Введите страну: " << endl;
                                string country;
                                cin >> country;
                                list.enterData(RAM, memory, country);
                                break;
                            }
                            case 3: {
                                cout << "Введите год: " << endl;
                                string year;
                                cin >> year;
                                cout << "Введите экран: " << endl;
                                string screen;
                                cin >> screen;
                                cout << "Введите камеру: " << endl;
                                string camera;
                                cin >> camera;
                                cout << "Введите батарею: " << endl;
                                string battery;
                                cin >> battery;
                                list.enterData(year, screen, camera, battery);
                                break;
                            }
                            case 4: {
                                cout << "Введите процессор: " << endl;
                                string processor;
                                cin >> processor;
                                list.enterData(processor);
                                break;
                            }
                            default:
                                cout << "Неправильный выбор." << endl;
                                break;
                        }
                    case 9:
                        break;
                    default:
                        cout << "Неправильный выбор. Попробуйте снова." << endl;
                        break;
                }
                break;
            case 2:
                int choice2;
                cout << "Меню: " << endl;
                cout << "1. Проверить, пуст ли список" << endl;
                cout << "2. Получить размер списка" << endl;
                cout << "3. Добавить элемент после текущего" << endl;
                cout << "4. Очистить весь список" << endl;
                cout << "5. Переместиться вперед" << endl;
                cout << "6. Считать информацию об элементе списка" << endl;
                cout << "7. Вставить элемент в конец списка" << endl;
                cout << "8. Изменить значение элемента" << endl;
                cout << "9. Выйти" << endl;
                cout << "Введите свой выбор: " << endl;
                cin >> choice2;

                switch (choice2) {
                    case 1:
                        list1.isEmpty();
                        break;
                    case 2:
                        list1.size();
                        break;
                    case 3:
                        list1.addBack();
                        break;
                    case 4:
                        list1.clearAll();
                        break;
                    case 5:
                        list1.moveForward();
                        break;
                    case 6:
                        list1.readInfo();
                        break;
                    case 7:
                        list1.insertAfterCurrent();
                        break;
                    case 8:
                        cout << "1. Изменить имя, цену " << endl;
                        cout << "2. Изменить объем ОЗУ, объем памяти, страну" << endl;
                        cout << "3. Изменить год, экран, камеру, батарею" << endl;
                        cout << "4. Изменить процессор" << endl;
                        int choice1;
                        cin >> choice1;
                        switch (choice1) {
                            case 1: {
                                cout << "Введите имя: " << endl;
                                string name;
                                cin >> name;
                                cout << "Введите цену: " << endl;
                                string price;
                                cin >> price;
                                list.enterData(name, price);
                                break;
                            }
                            case 2: {
                                cout << "Введите объем ОЗУ: " << endl;
                                string RAM;
                                cin >> RAM;
                                cout << "Введите объем памяти: " << endl;
                                string memory;
                                cin >> memory;
                                cout << "Введите страну: " << endl;
                                string country;
                                cin >> country;
                                list.enterData(RAM, memory, country);
                                break;
                            }
                            case 3: {
                                cout << "Введите год: " << endl;
                                string year;
                                cin >> year;
                                cout << "Введите экран: " << endl;
                                string screen;
                                cin >> screen;
                                cout << "Введите камеру: " << endl;
                                string camera;
                                cin >> camera;
                                cout << "Введите батарею: " << endl;
                                string battery;
                                cin >> battery;
                                list.enterData(year, screen, camera, battery);
                                break;
                            }
                            case 4: {
                                cout << "Введите процессор: " << endl;
                                string processor;
                                cin >> processor;
                                list.enterData(processor);
                                break;
                            }
                            default:
                                cout << "Неправильный выбор." << endl;
                                break;
                        }
                    case 9:
                        break;
                    default:
                        cout << "Invalid choice. Please try again." << endl;
                        break;
                }
                break;
            case 3:
                cout << "Сравнение списков по размеру: " << endl;
                if(list == list1)
                {
                    cout << "Списки равны" << endl;
                }
                else
                {
                    cout << "Списки не равны" << endl;
                }
                if(list >= list1)
                {
                    cout << "Список номер 1 больше или равен 2" << endl;
                }
                else
                {
                    cout << "Список номер 2 больше или равен 1" << endl;
                }
                break;
        }
    }

}



