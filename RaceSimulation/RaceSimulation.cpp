#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
/*
#include "Vehicle.h"
#include "AirV.h"
#include "Boots.h"
#include "Broom.h"
#include "Camel.h"
#include "CamelFast.h"
#include "Carpet.h"
#include "Eagle.h"
#include "Race.h"
#include "GroundV.h"*/

#include "../RSDll/Vehicle.h"
#include "../RSDll/AirV.h"
#include "../RSDll/Carpet.h"
#include "../RSDll/Eagle.h"
#include "../RSDll/Broom.h"
#include "../RSDll/GroundV.h"
#include "../RSDll/Camel.h"
#include "../RSDll/CamelFast.h"
#include "../RSDll/Centaur.h"
#include "../RSDll/Boots.h"
#include "../RSDll/Exceptions.h"
#include "../RSDll/Race.h"
int main()
{
    try {
        setlocale(LC_ALL, "Russian");
        int action = 0;
        do {
            std::cout << "Добро пожаловать в гоночный симулятор!" << std::endl;
            std::cout << "1. Гонка для наземного транспорта" << std::endl;
            std::cout << "2. Гонка для воздушного транспорта" << std::endl;
            std::cout << "3. Гонка для наземного и воздушного транспорта" << std::endl;
            std::cout << "Выберите тип гонки: ";
            int type;
            std::cin >> type;
            Race r(type);
            std::cout << "Укажите длину дистанции (должна быть положительна): ";
            double distance;
            std::cin >> distance;
            if (distance <= 0) throw Exceptions("Длина должна быть положительна!");
            std::cout << "Должно быть зарегистрировано хотя бы 2 транспортных средства" << std::endl;
            std::cout << "1. Зарегистрировать транспорт" << std::endl;
            std::cout << "Выберите действие: ";
            std::cin >> action;
            int i = 0;
            Vehicle** arr = new Vehicle * [7];
            int* arrCounter = new int[7];
            for (int j = 0; j < 7; ++j) {
                arrCounter[j] = 0;
            }
            int vehicle = -1;
            do {
                while (vehicle != 0) {
                    if (r.get_type() == 1) {
                        std::cout << "Гонка для наземного транспорта. Расстояние: " << distance << "\n";
                    }
                    if (r.get_type() == 2) {
                        std::cout << "Гонка для воздушного транспорта. Расстояние: " << distance << "\n";
                    }
                    if (r.get_type() == 3) {
                        std::cout << "Гонка для наземного и воздушного транспорта. Расстояние: " << distance << "\n";
                    }
                    if (vehicle > 0) {
                        std::cout << "Зарегистрированные транспортные средства: ";
                        for (int j = 0; j < i; ++j) {
                            std::cout << arr[j]->get_type();
                            if (j != i - 1) std::cout << ", ";
                        }
                        std::cout << std::endl;
                    }
                    std::cout << "1. Ботинки-вездеходы\n"
                        << "2. Метла\n"
                        << "3. Верблюд\n"
                        << "4. Кентавр\n"
                        << "5. Орел\n"
                        << "6. Верблюд-быстроход\n"
                        << "7. Ковер-самолет\n"
                        << "0. Закончить регистрацию\n"
                        << "Выберите транспорт или 0 для окончания процесса регистрации: ";

                    std::cin >> vehicle;
                    if (vehicle != 0) {
                        switch (vehicle)
                        {
                        case 1: {
                            if ((r.get_type() == 1 || r.get_type() == 3)) {
                                if (arrCounter[0] != 0) throw Exceptions("Ботинки-вездеходы уже зарегистрированы!");
                                arr[i] = new Boots(distance);
                                arrCounter[0] = arrCounter[0] + 1;
                            }
                            else throw Exceptions("Попытка зарегистрировать неправильный тип транспортного средства!");
                            break;
                        }

                        case 2: {
                            if ((r.get_type() == 2 || r.get_type() == 3)) {
                                if (arrCounter[1] != 0) throw Exceptions("Метла уже зарегистрирована!");
                                arr[i] = new Broom(distance);
                                arrCounter[1] = arrCounter[1] + 1;
                            }
                            else throw Exceptions("Попытка зарегистрировать неправильный тип транспортного средства!");
                            break;
                        }
                        case 3: {
                            if ((r.get_type() == 1 || r.get_type() == 3)) {
                                if (arrCounter[2] != 0) throw Exceptions("Верблюд уже зарегистрирован!");
                                arr[i] = new Camel(distance);
                                arrCounter[2] = arrCounter[2] + 1;
                            }
                            else throw Exceptions("Попытка зарегистрировать неправильный тип транспортного средства!");
                            break;
                        }
                        case 4: {
                            if ((r.get_type() == 1 || r.get_type() == 3)) {
                                if (arrCounter[3] != 0) throw Exceptions("Кентавр уже зарегистрирован!");
                                arr[i] = new Centaur(distance);
                                arrCounter[3] = arrCounter[3] + 1;
                            }
                            else throw Exceptions("Попытка зарегистрировать неправильный тип транспортного средства!");
                            break;
                        }
                        case 5: {
                            if ((r.get_type() == 2 || r.get_type() == 3)) {
                                if (arrCounter[4] != 0) throw Exceptions("Орел уже зарегистрирован!");
                                arr[i] = new Eagle(distance);
                                arrCounter[4] = arrCounter[4] + 1;
                            }
                            else throw Exceptions("Попытка зарегистрировать неправильный тип транспортного средства!");
                            break;
                        }
                        case 6: {
                            if ((r.get_type() == 1 || r.get_type() == 3)) {
                                if (arrCounter[5] != 0) throw Exceptions("Верблюд-быстроход уже зарегистрирован!");
                                arr[i] = new CamelFast(distance);
                                arrCounter[5] = arrCounter[5] + 1;
                            }
                            else throw Exceptions("Попытка зарегистрировать неправильный тип транспортного средства!");
                            break;
                        }
                        case 7: {
                            if ((r.get_type() == 2 || r.get_type() == 3)) {
                                if (arrCounter[6] != 0) throw Exceptions("Ковер-самолет уже зарегистрирован!");
                                arr[i] = new Carpet(distance);
                                arrCounter[6] = arrCounter[6] + 1;
                            }
                            else throw Exceptions("Попытка зарегистрировать неправильный тип транспортного средства!");
                            break;
                        }
                        default:
                            throw Exceptions("Попытка зарегистрировать неправильный тип транспортного средства!");
                            break;
                        }
                        std::cout << arr[i]->get_type() << " успешно зарегистрирован!" << std::endl;
                        i++;
                    }
                }
                if (i < 1) throw Exceptions("Должно быть зарегистрировано хотя бы 2 транспортных средства!");
                std::cout << "1. Зарегистрировать транспорт\n"
                    << "2. Начать гонку\n"
                    << "Выберите действие: ";
                std::cin >> action;
                if (action == 1) vehicle = -1;
            } while (action == 1);
            if (action == 2) {
                std::cout << "Результаты гонки: " << std::endl;
                double* arrT = new double[7];
                int* arr_i = new int[7];
                for (int j = 0; j < i; ++j) {
                    arr_i[j] = j;
                    arrT[j] = arr[j]->summTime();
                }
                for (int k = 0; k < i - 1; ++k) {
                    for (int j = 0; j < i - 1; ++j) {
                        if (arrT[j] < arrT[j + 1]) {
                            std::swap(arrT[j], arrT[j + 1]);
                            std::swap(arr_i[j], arr_i[j + 1]);
                        }
                    }
                }
                for (int j = 0; j < i; ++j) {
                    std::cout << j + 1 << ". " << arr[arr_i[j]]->get_type() << ". Время: " << arr[arr_i[j]]->summTime() << std::endl;
                }
                delete[] arrT;
                delete[] arr_i;
            }
            delete[] arr;
            std::cout << std::endl;
            std::cout << "1. Провести еще одну попытку\n"
                << "2. Выйти\n"
                << "Выберите действие: ";
            std::cin >> action;
        } while (action == 1);
    }
    catch (const Exceptions& e) {
        std::cout << e.what() << std::endl;
    }
}
