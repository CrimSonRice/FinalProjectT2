#pragma once
#include <iostream>
#include "Car.cpp"

using namespace std;

class CarManager : public Car {
private:
	string name;
	Car cars[20];
	int count = 0;

public:
	CarManager(): Car(), name("Unknown"){}
	CarManager(string name): name(name){}

	void AddCar(Car cars[], int number, int& count) {
		cars[count] = car;
		count++;
	}

	void ViewCar() {
		for (int i = 0; i < count; i++) {
			cars[i].output_car_info();
		}
	}

	int FindCarById(int id) {
		for (int i = 0; i < count; i++) {
			if (cars[i].getId() == id) {
				return i;
			}
		}
		return -1;
	}

    void edit_car_info(Car cars, int number, int key) {
        int new_id;
        string new_license;
        string new_model;
        string new_color;
        string new_plate_number;
        double new_price;

            int found = searchCar(cars, number, key);
            if (found == -1) {
                cout << "The CAR's ID was not found at " << found << endl;
            }
            else {
                int choice;
                cout << "\t========EDIT BY========" << endl;
                cout << "1.ID.\n2.Model.\n3.Color\n4.Plate_number.\n5.Price.\n6.All.\n7.Return to menu. " << endl << endl;
                cout << "Enter command: ";

                cin >> choice;
                switch (choice) {
                case 1:
                    cout << "Enter new ID: ";
                    cin >> new_id;
                    cars[found].getId () = setId() ;
                    break;

                case 2:
                    cout << "Enter new model: ";
                    cin >> new_model;
                    cars[found].model = new_model;
                    break;

                case 3:
                    cout << "Enter new color: ";
                    cin >> new_color;
                    cars[found].color = new_color;
                    break;

                case 4:
                    cout << "Enter new plate number: ";
                    cin >> new_plate_number;
                    cars[found].plate_number = new_plate_number;
                    break;

                case 5:
                    cout << "Enter new Price: ";
                    cin >> new_plate_number;
                    cars[found].price = new_price;
                    break;

                case 6:
                    cout << "Enter new ID: ";
                    cin >> new_id;
                    cars[found].id = new_id;

                    cout << "Enter new Model: ";
                    cin >> new_model;
                    cars[found].model = new_model;

                    cout << "Enter new color: ";
                    cin >> new_color;
                    cars[found].color = new_color;

                    cout << "Enter new plate number: ";
                    cin >> new_plate_number;
                    cars[found].plate_number = new_plate_number;

                    cout << "Enter new Price: ";
                    cin >> new_price;
                    cars[found].price = new_price;
                    
                    

                    break;

                case 7:
                   
                    break;
                    
                }

            }
            
            
	}

    int searchCar(Car cars[], int number, int key) {
        for (int i = 0; i < number; i++) {
            if (key == cars[i].getId()) {
                return i;
            }
        }
        return -1;
    }

    void deleteCar(Car cars[], int& number, int key) {
        int found = searchCar(cars, number, key);
        if (found == -1) {
            cout << "The CAR's license was not found at" << found << endl;
        }
        else {
            for (int i = found; i < number; i++) {
                cars[i] = cars[i + 1];
            }
            number = number - 1;
        }

    }

    void SortCar(Car cars[], int number) {
        Car temp;
        for (int i = 0; i < number - 1; i++) {
            for (int j = 0; j < number - i - 1; j++) {
                if (cars[j].getId() > cars[j + 1].getId()) {
                    temp = cars[j];
                    cars[j] = cars[j + 1];
                    cars[j + 1] = temp;
                }
            }
        }
    }


};