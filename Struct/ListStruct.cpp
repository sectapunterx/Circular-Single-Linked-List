#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

struct mobile{
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
};

struct List
{
    mobile *data;
    List *next;
};

//1,2,3,13,14,7,10,11
void isEmpty(List *head)
{
    if(head == nullptr)
    {
        cout << "List is empty" << endl;
    }
    else
    {
        cout << "List is not empty" << endl;
    }
}

void size(List* head)
{
    int count = 0;
    List *temp = head;
    while(temp != nullptr)
    {
        count++;
        temp = temp->next;
    }
    cout << "Size of list is " << count << endl;
}

void add_back(List** head)
{
    if(*head == nullptr)
    {
        *head = new List;
        (*head)->data = new mobile;
        cout << "Enter name: ";
        cin >> (*head)->data->name;
        cout << "Enter price: ";
        cin >> (*head)->data->price;
        cout << "Enter ram: ";
        cin >> (*head)->data->ram;
        cout << "Enter storage: ";
        cin >> (*head)->data->storage;
        cout << "Enter country: ";
        cin >> (*head)->data->country;
        cout << "Enter year: ";
        cin >> (*head)->data->year;
        cout << "Enter screen: ";
        cin >> (*head)->data->screen;
        cout << "Enter camera: ";
        cin >> (*head)->data->camera;
        cout << "Enter battery: ";
        cin >> (*head)->data->battery;
        cout << "Enter processor: ";
        cin >> (*head)->data->processor;
        (*head)->next = nullptr;
    }
    else
    {
        List* tmp = *head;
        while(tmp->next != nullptr)
        {
            tmp = tmp->next;
        }
        tmp->next = new List;
        tmp->next->data = new mobile;
        cout << "Enter name: ";
        cin >> tmp->next->data->name;
        cout << "Enter price: ";
        cin >> tmp->next->data->price;
        cout << "Enter ram: ";
        cin >> tmp->next->data->ram;
        cout << "Enter storage: ";
        cin >> tmp->next->data->storage;
        cout << "Enter country: ";
        cin >> tmp->next->data->country;
        cout << "Enter year: ";
        cin >> tmp->next->data->year;
        cout << "Enter screen: ";
        cin >> tmp->next->data->screen;
        cout << "Enter camera: ";
        cin >> tmp->next->data->camera;
        cout << "Enter battery: ";
        cin >> tmp->next->data->battery;
        cout << "Enter processor: ";
        cin >> tmp->next->data->processor;
        tmp->next->next = nullptr;
    }
}

void clear_all(List* head)
{
    List* tmp = head;
    while(tmp != nullptr)
    {
        List* tmp2 = tmp->next;
        delete tmp->data;
        delete tmp;
        tmp = tmp2;
    }
    head = nullptr;
}

List* move_forward(List* head) // for circular linked list
{
    List* tmp = head;
    while(tmp->next != nullptr)
    {
        tmp = tmp->next;
    }
    tmp->next = head;
    head = head->next;
    tmp->next->next = nullptr;
    return head;
}

void read_info(List* head)
{
    cout << "Name: " << head->data->name << endl;
    cout << "Price: " << head->data->price << endl;
    cout << "Ram: " << head->data->ram << endl;
    cout << "Storage: " << head->data->storage << endl;
    cout << "Country: " << head->data->country << endl;
    cout << "Year: " << head->data->year << endl;
    cout << "Screen: " << head->data->screen << endl;
    cout << "Camera: " << head->data->camera << endl;
    cout << "Battery: " << head->data->battery << endl;
    cout << "Processor: " << head->data->processor << endl;
}

void insert_back(List* head)
{
    List* tmp = head;
    while(tmp->next != nullptr)
    {
        tmp = tmp->next;
    }
    add_back(&tmp);
}

int main()
{
    List* head = nullptr;
    int choice;
    while(1) {
        cout << "Menu: " << endl;
        cout << "1. Check if the list is empty" << endl;
        cout << "2. Get the size of the list" << endl;
        cout << "3. Add an element to the back of the list" << endl;
        cout << "4. Clear the entire list" << endl;
        cout << "5. Move the head of the list forward" << endl;
        cout << "6. Read information of the head of the list" << endl;
        cout << "7. Insert an element at the back of the list" << endl;
        cout << "8. Quit" << endl;
        cout << "Enter your choice: " << endl;
        cin >> choice;
            switch (choice) {
                case 1:
                    isEmpty(head);
                    break;
                case 2:
                    size(head);
                    break;
                case 3:
                    add_back(&head);
                    break;
                case 4:
                    clear_all(head);
                    break;
                case 5:
                    head = move_forward(head);
                    break;
                case 6:
                    read_info(head);
                    break;
                case 7:
                    insert_back(head);
                    break;
                case 8:
                    return 0;
                    break;
                default:
                    cout << "Invalid choice" << endl;
                    break;
            }
    }
    return 0;
}
