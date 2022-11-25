#pragma once
#include <iostream>

using namespace std;

class Car {
private:
	int id;
    string model;
    string color;
    string plate_number;
    double price;

public:
    Car(): id(0), model("Unknow"), color("Unknown"), plate_number("Unknown"), price(0.0){}
    Car(int id,  string model, string color, string plate_number, double price): id(id),  model(model), color(color), plate_number(plate_number), price(price){}

    void setId(int id) {
        this->id = id;
    }

    int getId() {
        return id;
    }

   
    void setModel(string model) {
        this->model = model;
    }

    string getModel() {
        return model;
    }

    void setColor(string color) {
        this->color = color;
    }

    string getColor() {
        return color;
    }

    void setPlateNumber(string plate_number) {
        this->plate_number = plate_number;
    }

    string getPlateNumber() {
        return plate_number;
    }

    void setPrice(double price) {
        this->price = price;
    }

    double getPrice() {
        return price;
    }
    

   virtual void input_car_info() {
        cout << "Enter CAR's ID: ";
        cin >> id;

        cout << "Enter CAR's Model: ";
        cin >> model;

        cout << "Enter CAR's Color: ";
        cin >> color;

        cout << "Enter CAR's Plate Number: ";
        cin >> plate_number;

        cout << "Enter CAR's Price: ";
        cin >> price;

    }

   virtual void output_car_info() {
        system("cls");
        cout << "\t\t====================== VIEW CAR ====================== " << endl;
        cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
        cout << "\tCAR's ID: " << id << endl;
        cout << "\tCAR's Model: "<< model << endl;
        cout << "\tCAR's Color: " << color << endl;
        cout << "\tCAR's Plate Number: " << plate_number << endl;
        cout << "\tCAR's Price: " << price << endl;
        cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;

    }
};