#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

int num1;

struct SubList {
    std::string value;
    SubList* next;
};

struct MainList {
    MainList* nextMain;
    SubList* firstSub;
    std::string value;
} *HeadMain;

int check_num()
{
    int num;

    while (!(std::cin >> num))
    {
        std::cin.clear();
        while (std::cin.get() != '\n');
        std::cout << "Повторите ввод" << std::endl;
    }
    return (num);
}

inline void initList() {
    HeadMain = new (MainList);
    HeadMain->nextMain = NULL;
    HeadMain->firstSub = NULL;
    num1 = 0;
}

bool isMainListEmpty()
{
    if (HeadMain->nextMain == NULL) 
        return 1;
    else
        return 0;
}

bool isSubListEmpty(SubList* firstSub)
{
    if (firstSub->next == NULL) 
        return 1;
    else
        return 0;
}

void showList()
{
    cout << "\nСостояние списка: ";
    if (!isMainListEmpty()) 
    {
        MainList* MainCurrent = HeadMain->nextMain;
        while (MainCurrent != NULL) {
            std::cout << "Содержимое элемента " << MainCurrent->value << " основного списка:" << std::endl;
            int i = 1;
            if (!isSubListEmpty(MainCurrent->firstSub)) {
                SubList* SubCurrent = MainCurrent->firstSub->next;
                while (SubCurrent != NULL) {
                    cout << "   " << i << ") " << SubCurrent->value << std::endl;
                    SubCurrent = SubCurrent->next;
                    i++;
                }
            }
            else std::cout << "   " << "<Пусто>\n";
            MainCurrent = MainCurrent->nextMain;
        }
    }
    else
        cout << "Главный список пуст" << std::endl;
}

void pushInMain()
{
    string _value;
    MainList* Current = nullptr;
    MainList* Temp = new (MainList);
    Temp->firstSub = new (SubList);
    int choice = -1;
    while ((choice != 1) && (choice != 2))
    {
        cout << "\nКуда добавить элемент-список?\n 1 - Перед заданным элементом\n2 - После заданного элемента\nВведите номер команды: ";
        choice = check_num();
        int i = -1;
        if (choice == 1)
        {
            if (!isMainListEmpty())
            {
                MainList* Pred = HeadMain;
                while (i == -1)
                {
                    Current = HeadMain->nextMain;
                    cout << "\n Введите значение элемента, перед которым вы хотите добавить новый элемент: ";
                    cin.clear();
                    std::cin >> _value;
                    while (Current != NULL) 
                    {
                        if (Current->value == _value)
                            break;
                        Current = Current->nextMain;
                        Pred = Pred->nextMain;
                    }
                    if (Current != NULL)
                        i++;
                    else 
                        cout << " Строка " << _value << " не найдена. Попробуйте ввести другое значение" << std::endl;
                }
                Temp->nextMain = Current;
                Temp->firstSub->next = NULL;
                Pred->nextMain = Temp;
            }
            else 
            {
                cout << "\nСписок пуст" << std::endl;
                choice = -1;
            }
        }
        else if (choice == 2) {
            if (!isMainListEmpty()) {
                while (i == -1) {
                    Current = HeadMain->nextMain;
                    cout << "\n Введите значение элемента, ПОСЛЕ КОТОРОГО вы хотите добавить новый элемент: ";
                    cin.clear();
                    std::cin >> _value;
                    while ((Current != NULL) && (Current->value != _value))
                        Current = Current->nextMain;
                    if (Current != NULL)
                        i++;
                    else
                        cout << " Строка " << _value << " не найдена. Попробуйте ввести другое значение" << std::endl;
                }
                Temp->nextMain = Current->nextMain;
                Temp->firstSub->next = NULL;
                Current->nextMain = Temp;
            }
            else
            {
                Temp->nextMain = NULL;
                Temp->firstSub->next = NULL;
                HeadMain->nextMain = Temp;
            }
        }
        else
        {
            cout << "\nПовторите ввод" << std::endl;
            choice = -1;
        }
    }
    cout << "\n Введите название элемента главного списка: ";
    cin.clear();
    std::cin >> _value;
    Temp->value = _value;
    num1++;
    cout << "\n Элемент успешно добавлен в базовый список!" << std::endl;
}

void pushInSub()
{
    if (!isMainListEmpty()) {
        string _value;
        MainList* CurrentMain = nullptr;
        int i = -1;
        while (i == -1) {
            CurrentMain = HeadMain->nextMain;
            cout << "\n Введите название заголовка связанного списка, в который хотите добавить новый элемент: ";
            cin.clear();
            std::cin >> _value;
            while ((CurrentMain != NULL) && (CurrentMain->value != _value))
                CurrentMain = CurrentMain->nextMain;
            if (CurrentMain != NULL)
                i++;
            else
                cout << " Строка " << _value << " не найдена. Попробуйте ввести другое значение" << std::endl;
        }
        SubList* Head = CurrentMain->firstSub;
        SubList* CurrentSub = nullptr;
        SubList* Temp = new (SubList);
        int choice = -1;
        while ((choice != 1) && (choice != 2)) {
            cout << "\n Куда добавить элемент?\n 1 - Перед заданным элементом\n 2 - После заданного элемента\n Введите номер команды: ";
            choice = check_num();
            if (choice == 1)
            {
                if (!isSubListEmpty(Head))
                {
                    SubList* Pred = Head;
                    i = -1;
                    while (i == -1)
                    {
                        CurrentSub = Head->next;
                        cout << "\n Введите значение элемента, перед которым вы хотите добавить новый элемент: ";
                        cin.clear();
                        std::cin >> _value;
                        while (CurrentSub != NULL)
                        {
                            if (CurrentSub->value == _value)
                                break;
                            CurrentSub = CurrentSub->next;
                            Pred = Pred->next;
                        }
                        if (CurrentSub != NULL)
                            i++;
                        else 
                            cout << " Строка " << _value << " не найдена. Попробуйте ввести другое значение" << std::endl;
                    }
                    Temp->next = CurrentSub;
                    Pred->next = Temp;
                }
                else
                {
                    cout << "\nСписок пуст" << std::endl;
                    choice = -1;
                }
            }
            else if (choice == 2) 
            {
                if (!isSubListEmpty(CurrentMain->firstSub)) 
                {
                    i = -1;
                    while (i == -1)
                    {
                        CurrentSub = Head->next;
                        cout << "\n Введите значение элемента, после которого вы хотите добавить новый элемент: ";
                        cin.clear();
                        std::cin >> _value;
                        while ((CurrentSub != NULL) && (CurrentSub->value != _value))
                            CurrentSub = CurrentSub->next;
                        if (CurrentSub != NULL)
                            i++;
                        else
                            cout << " Строка " << _value << " не найдена. Попробуйте ввести другое значение" << std::endl;
                    }
                    Temp->next = CurrentSub->next;
                    CurrentSub->next = Temp; 
                }
                else
                {
                    Temp->next = NULL;
                    Head->next = Temp;
                }
            }
            else
            {
                cout << "\nПовторите ввод" << std::endl;
                choice = -1;
            }
        }
        cout << "\n Введите добавляемую строку: ";
        cin.clear();
        std::cin >> _value;
        cout << "\n Элемент успешно добавлен! \n";
        Temp->value = _value;
    }
    else
        cout << "\nСвязанный список пуст" << std::endl;
}


void popFromMain()
{
    if (!isMainListEmpty()) {
        string _value;
        MainList* MainCurrent = nullptr;
        MainList* MainPred = nullptr;
        SubList* SubCurrent;
        int i = -1;
        while (i == -1)
        {
            MainCurrent = HeadMain->nextMain;
            MainPred = HeadMain;
            cout << "\n Введите название заголовка связанного списка, чтобы удалить его: ";
            cin.clear();
            std::cin >> _value;
            while (MainCurrent != NULL)
            {
                if (MainCurrent->value == _value)
                    break;
                MainCurrent = MainCurrent->nextMain;
                MainPred = MainPred->nextMain;
            }
            if (MainCurrent != NULL)
            {
                i++;
                cout << "строка " << _value << " найдена. производится удаление..." << std::endl;
            }
            else 
                cout << "строка " << _value << " не найдена. Введите другое значение" << std::endl;
        }
        while (MainCurrent->firstSub->next != NULL)
        {
            SubCurrent = MainCurrent->firstSub;
            MainCurrent->firstSub = MainCurrent->firstSub->next;
            free(SubCurrent);
        }
        delete MainCurrent->firstSub;
        cout << " вспомогательный список '" << MainCurrent->value << "' удален" << std::endl;
        MainPred->nextMain = MainCurrent->nextMain;
        delete MainCurrent;
        cout << " Элемент главного списка удален" << std::endl;
    }
    else
        cout << " Список пуст." << std::endl;
}

void popFromSub()
{
    if (!isMainListEmpty()) {
        showList();
        string _value;
        MainList* CurrentMain = nullptr;
        int i = -1;
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        while (i == -1)
        {
            CurrentMain = HeadMain->nextMain;
            cout << "\n Введите значение заголовка связного списка, в котором хотите удалить элемент: ";
            cin.clear(); getline(cin, _value);
            while ((CurrentMain != NULL) && (CurrentMain->value != _value))
                CurrentMain = CurrentMain->nextMain;
            if (CurrentMain != NULL) i++;
            else { cout << " Строка " << _value << " не найдена. Попробуйте ввести другое значение\n"; }
        }
        if (!isSubListEmpty(CurrentMain->firstSub))
        {
            SubList* Head = CurrentMain->firstSub;
            SubList* Current = nullptr;
            SubList* Pred = nullptr;
            int j = -1;
            while (j == -1)
            {
                i = -1;
                Current = Head->next;
                Pred = Head;
                cout << "\n Введите значение элемента, который хотите удалить: "; cin.clear(); getline(cin, _value);
                while (Current != NULL)
                {
                    if (Current->value == _value) break;
                    Current = Current->next;
                    Pred = Pred->next;
                    i++;
                }
                if (Current != NULL) { i++; cout << " Строка " << _value << " найдена под номером " << i << ")\n"; j++; }
                else { cout << " Строка " << _value << " не найдена\n"; }
            }
            Pred->next = Current->next;
            cout << "\nЭлемент '" << Current->value << "' удален из связанного списка '" << CurrentMain->value << "' \n";
            delete Current;
        }
        else
            cout << "\n Связанный список пуст.\n";
    }
    else
        cout << "\n Список пуст.\n";
}

void find()
{
    if (!isMainListEmpty())
    {
        showList();
        string _value;
        cout << "\n Введите строку, которую хотите найти: ";
        cin.clear(); 
        cin >> _value;
        int j = 0;
        MainList* CurrentMain = HeadMain->nextMain; 
        while (CurrentMain != NULL) {
            std::cout << "\n Поиск среди элементов списка " << CurrentMain->value << "... ";
            if (!isSubListEmpty(CurrentMain->firstSub))
            {
                int i = 0;
                SubList* SubCurrent = CurrentMain->firstSub->next;
                while (SubCurrent != NULL)
                {
                    if (SubCurrent->value == _value) { i++; j++; }
                    SubCurrent = SubCurrent->next;
                }
                if (i != 0) { cout << " Строка '" << _value << "' найдена\n"; }
                else cout << " Строка не найдена\n";
            }
            else
                cout << " Связанный список '" << CurrentMain->value << "' пуст\n";
            CurrentMain = CurrentMain->nextMain;
        }
        if (j == 0) cout << "\n Строка '" << _value << "' не найдена\n";
        else cout << "\n Найдено " << j << " элементов\n";
    }
    else
        cout << "\n Список пуст.\n";
}

void menu()
{
    int number;
    while (true) {
        cout << "___________________________________________________________\n";
        cout << "\nВыберите команду из списка:\n";
        cout << "1. Вывод текущего состояния списка на экран\n";
        cout << "2. Проверка пустоты главного списка\n";
        cout << "3. Добавить элемент в список с пустым связанным списком\n";
        cout << "4. Добавить элемент в связанный список\n";
        cout << "5. Удалить элемент из базового списка\n";
        cout << "6. Удалить элемент из связанного списка\n";
        cout << "7. Поиск элемента с заданной информационной частью\n";
        cout << "0. Завершить работу программы\n";
        cout << "Номер команды: ";
        number = check_num();
        if (number == 1) showList();
        else if (number == 2) {
            if (isMainListEmpty() == 1) cout << "\n Главный список пуст\n";
            else cout << "\n Главный список не пуст\n";
        }
        else if (number == 3) pushInMain();
        else if (number == 4) pushInSub();
        else if (number == 5) popFromMain();
        else if (number == 6) popFromSub();
        else if (number == 7) find();
        else if (number == 0) {
            cout << "\nПрограмма завершена\n\n";
            break;
        }
        else cout << "\n Повторите ввод команды\n";
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    initList();
    menu();
    return 0;
}
