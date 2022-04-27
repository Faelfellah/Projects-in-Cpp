// Aufgabe 2.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <iostream>
#include <string>
using namespace std;

typedef struct {
    string manufacturer; // Herstellername
    string model; //Modelname
    string serialNumber; // Seriennummer
    int weight; // Leergewicht
    int power;
    int numDoors;

}vehicle;

bool readVehicle(vehicle &vehicle);
void writeVehicle(const vehicle &vehicle);

//id copyvehicle();

int main()

{
    vehicle vehicle[20];
    readVehicle(*vehicle);
//riteVehicle(*vehicle);
}



bool readVehicle(vehicle &vehicle) {
    string eingabe;
    cout << " soll ein weiteres Fahrzeug eingelesen werden" << endl;
    cin >> eingabe;
    if (eingabe == "Ja") {
        
        
        return true;
    }
    else {
        return false;
    }
    cout << "Hersteller" << endl;
    cin >> vehicle.manufacturer;
    cout << "Modell" << endl;
    cin >> vehicle.model;
    cout << "Seriennmmer" << endl;
    cin >> vehicle.serialNumber;
    cout << "Gewicht" << endl;
    cin >> vehicle.weight;
    cout << "Leistung" << endl;
    cin >> vehicle.power;
    cout << "Anzahltüren " << endl;
    cin >> vehicle.numDoors;
}


void writeVehicle(const vehicle& vehicle) {
    cout << "Hersteller :" << vehicle.manufacturer << endl;
    cout << "Modell :" << vehicle.model << endl;
    cout << "Seriennummer :" << vehicle.serialNumber << endl;
    cout << "Leergewicht :" << vehicle.weight << endl;
    cout << "Leistung :" << vehicle.power<<endl;
    cout << "Anzahltüen c" << vehicle.numDoors << endl;
}


    



