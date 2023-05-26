#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>

#include "Vehicle.h"
#include "AirV.h"
#include "Boots.h"
#include "Broom.h"
#include "Camel.h"
#include "CamelFast.h"
#include "Carpet.h"
#include "Eagle.h"
#include "Race.h"
#include "GroundV.h"
#include "Centaur.h"

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
            Vehicle::Race r(type);
            double distance = -1;
            do {
                std::cout << "Укажите длину дистанции (должна быть положительна): ";
                std::cin >> distance;
                if (distance <= 0) std::cout << "Длина должна быть положительна! Попробуйте еще раз." << std::endl;
            } while (distance <= 0);
            std::cout << "Должно быть зарегистрировано хотя бы 2 транспортных средства" << std::endl;
            std::cout << "1. Зарегистрировать транспорт" << std::endl;
            std::cout << "Выберите действие: ";
            std::cin >> action;
            int i = 0;
            Vehicle::Vehicle** arr = new Vehicle::Vehicle * [7];
            int* arrCounter = new int[7];
            for (int j = 0; j < 7; ++j) {
                arrCounter[j] = 0;
            }
            bool wrongType = false;
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
                                if (arrCounter[0] != 0) {
                                    std::cout << "Ботинки-вездеходы уже зарегистрированы!" << std::endl;
                                    wrongType = true;
                                }
                                if (arrCounter[0] == 0) {
                                    arr[i] = new Vehicle::Boots(distance);
                                    arrCounter[0] = arrCounter[0] + 1;
                                }
                            }
                            else std::cout << "Попытка зарегистрировать неправильный тип транспортного средства!" << std::endl;
                            break;
                        }

                        case 2: {
                            if ((r.get_type() == 2 || r.get_type() == 3)) {
                                if (arrCounter[1] != 0) {
                                    std::cout << "Метла уже зарегистрирована!" << std::endl;
                                    wrongType = true;
                                }
                                if (arrCounter[1] == 0) {
                                    arr[i] = new Vehicle::Broom(distance);
                                    arrCounter[1] = arrCounter[1] + 1;
                                }
                            }
                            else std::cout << "Попытка зарегистрировать неправильный тип транспортного средства!" << std::endl;
                            break;
                        }
                        case 3: {
                            if ((r.get_type() == 1 || r.get_type() == 3)) {
                                if (arrCounter[2] != 0) {
                                    std::cout << "Верблюд уже зарегистрирован!" << std::endl;
                                    wrongType = true;
                                }
                                if (arrCounter[2] == 0) {
                                    arr[i] = new Vehicle::Camel(distance);
                                    arrCounter[2] = arrCounter[2] + 1;
                                }
                            }
                            else std::cout << "Попытка зарегистрировать неправильный тип транспортного средства!" << std::endl;
                            break;
                        }
                        case 4: {
                            if ((r.get_type() == 1 || r.get_type() == 3)) {
                                if (arrCounter[3] != 0) {
                                    std::cout << "Кентавр уже зарегистрирован!" << std::endl;
                                    wrongType = true;
                                }
                                if (arrCounter[3] == 0) {
                                    arr[i] = new Vehicle::Centaur(distance);
                                    arrCounter[3] = arrCounter[3] + 1;
                                }
                            }
                            else std::cout << "Попытка зарегистрировать неправильный тип транспортного средства!" << std::endl;
                            break;
                        }
                        case 5: {
                            if ((r.get_type() == 2 || r.get_type() == 3)) {
                                if (arrCounter[4] != 0) {
                                    std::cout << "Орел уже зарегистрирован!" << std::endl;
                                    wrongType = true;
                                }
                                if (arrCounter[4] == 0) {
                                    arr[i] = new Vehicle::Eagle(distance);
                                    arrCounter[4] = arrCounter[4] + 1;
                                }
                            }
                            else std::cout << "Попытка зарегистрировать неправильный тип транспортного средства!" << std::endl;
                            break;
                        }
                        case 6: {
                            if ((r.get_type() == 1 || r.get_type() == 3)) {
                                if (arrCounter[5] != 0) {
                                    std::cout << "Верблюд-быстроход уже зарегистрирован!" << std::endl;
                                    wrongType = true;
                                }
                                if (arrCounter[5] == 0) {
                                    arr[i] = new Vehicle::CamelFast(distance);
                                    arrCounter[5] = arrCounter[5] + 1;
                                }
                            }
                            else std::cout << "Попытка зарегистрировать неправильный тип транспортного средства!" << std::endl;
                            break;
                        }
                        case 7: {
                            if ((r.get_type() == 2 || r.get_type() == 3)) {
                                if (arrCounter[6] != 0) {
                                    std::cout << "Ковер-самолет уже зарегистрирован!" << std::endl;
                                    wrongType = true;
                                }
                                if (arrCounter[6] == 0) {
                                    arr[i] = new Vehicle::Carpet(distance);
                                    arrCounter[6] = arrCounter[6] + 1;
                                }
                            }
                            else std::cout << "Попытка зарегистрировать неправильный тип транспортного средства!" << std::endl;
                            break;
                        }
                        default:
                            std::cout << "Попытка зарегистрировать неправильный тип транспортного средства!" << std::endl;
                            break;
                        }
                        if (wrongType == false) {
                            std::cout << arr[i]->get_type() << " успешно зарегистрирован!" << std::endl;
                            i++;
                        }
                        else wrongType = false;
                    }
                    else  if (vehicle == 0 && i < 1) {
                        std::cout << "Должно быть зарегистрировано хотя бы 2 транспортных средства!" << std::endl;
                        vehicle = -1;
                    }
                }
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
                        if (arrT[j] > arrT[j + 1]) {
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
    catch (...) {
        std::cout << "Неизвестная ошибка!" << std::endl;
    }
}
