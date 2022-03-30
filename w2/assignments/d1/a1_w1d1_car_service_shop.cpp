/*
================================================================================================================

A car service shop needs to keep track of the records of services they provide to their customer. Create a system
for them so they could keep ATLEAST the below records:

    • Date the customer visited
    • Services performed (at least 2 different services)
    • Parts changed (at least 2 different parts)
    • Payment (method & amount)

================================================================================================================
*/

#include <iostream>
#include <ctime>
#include <string>
#define MAX_PARTS 4
#define MAX_SERVICES 4

using namespace std;

class CarServiceRecord {
    private:
        string dt;
        string customer_name, car_brand;
        string changed_parts[4];
        string performed_services[4];
        enum Services {oil_level, oil_filter, washer_fluid, coolant_fluid};
        enum Parts {tire, windshield, brakes, exhaust_pipe};

        int SetNoPartsChanged() {
            int no_parts{};
            do {
                cout << ">> Number of parts changed: ";
                cin >> no_parts;
            } while (no_parts > MAX_PARTS || no_parts < 0);
            return no_parts;
        }

        int SetNoServices() {
            int no_services{};
            do {
                cout << ">> Number of performed services: ";
                cin >> no_services;
            } while (no_services > MAX_SERVICES || no_services < 0);
            return no_services;
        }

        string payment_method;
        void SetPaymentMethod (int payment_id) {
            switch(payment_id) {
                case 1 : payment_method = "Cash" ; break;
                case 2 : payment_method = "Credit" ; break;
                case 3 : payment_method = "Invoice" ; break;
            }
        }

        float customer_balance;
        int i_parts = 0;
        int i_services = 0;
        void UpdateCustomerBalance (int id) {
            switch(id) {
                case 11 : customer_balance -= 9.90; performed_services[i_services++]  = "Oil level:          $9.90"; break;
                case 12 : customer_balance -= 74.90; performed_services[i_services++] = "Oil filter:         $74.90"; break;
                case 13 : customer_balance -= 12.90; performed_services[i_services++] = "Washer Fluid:       $12.90"; break;
                case 14 : customer_balance -= 14.90; performed_services[i_services++] = "Coolant Fluid:      $14.90"; break;
                case 21 : customer_balance -= 99.90; changed_parts[i_parts++]          = "Tire:              $99.90"; break;
                case 22 : customer_balance -= 249.90; changed_parts[i_parts++]         = "Windshield:        $249.90"; break;
                case 23 : customer_balance -= 179.90; changed_parts[i_parts++]         = "Brakes:            $179.90"; break;
                case 24 : customer_balance -= 129.90; changed_parts[i_parts++]         = "Exhaust Pipe:      $129.90"; break;
            }
        }
    public:
        CarServiceRecord() {
            time_t now = time(0);
            dt = ctime(&now);
            customer_balance = 0;
            payment_method = "-";
        }

        void SetCustomerName() {
            getline(cin, customer_name);
        }

        void SetCarBrand() {
            cin >> car_brand;
        }

        string GetRecordCreated() {
            return dt;
        }

        string GetCustomerName() {
            return customer_name;
        }

        string GetCarBrand() {
            return car_brand;
        }

        void SetPartsChanged() {
            int parts = SetNoPartsChanged();
            int part_id;
            cout << ">> Enter Part ID for changed part(s)" << endl;
            for (int i = 1; i < parts + 1; i++) {
                cout << ">> No." << i << ", Part ID: ";
                cin >> part_id;
                UpdateCustomerBalance(part_id);
            }
        }

        void SetPerformedService() {
            int services = SetNoServices();
            int service_id;
            cout << ">> Enter Service ID for performed service(s)" << endl;
            for (int i = 1; i < services + 1; i++) {
                cout << ">> No." << i << ", Service ID: ";
                cin >> service_id;
                UpdateCustomerBalance(service_id);
            }
        }

        void SetPaymentMethod() {
            int payment_id;
            cout << ">> Enter Payment Option ID: ";
            cin >> payment_id;
            SetPaymentMethod(payment_id);
        }
        void GetReceipt() {
            cout <<  endl << "RECEIPT: " << dt;
            cout << "=================================" << endl;;
            cout << "Customer Name: " << customer_name << endl;
            cout << "Car: " << car_brand << endl;
            cout << "Payment method: " << payment_method << endl;
            if (changed_parts[0] != "") {
                cout << endl << "Changed parts" << endl <<
                                "--------------------------" << endl;
                for (int i = 0; i < sizeof(changed_parts)/sizeof(string); i++) {
                    if (changed_parts[i] != "") {
                        cout << changed_parts[i] << endl;
                    }
                }
            }
            if (performed_services[0] != "") {
                cout << endl << "Performed services" << endl <<
                                "--------------------------" << endl;
                for (int i = 0; i < sizeof(performed_services)/sizeof(string); i++) {
                    if (performed_services[i] != "") {
                        cout << performed_services[i] << endl;
                    }
                }
            }
            cout << "--------------------------" << endl <<
                    "Total balance:     $" << customer_balance << endl << endl;
        }
};

int main () {

    CarServiceRecord* custom_ptr[2] = {
        new CarServiceRecord,
        new CarServiceRecord
    };

    for (int i = 0; i < 2; i++) {
        cout << "============================================" << endl <<
                "| CARL'S CAR MECHANICS AND SERVICE CENTER  |" << endl <<
                "|          CUSTOMER RECORD FORM            |"<< endl <<
                "============================================" << endl;
        cout << "Customer Name: ";
        custom_ptr[i]->SetCustomerName();
        cout << "Car brand: ";
        custom_ptr[i]->SetCarBrand();
        cout << endl << "--------------------------------------" << endl <<
                        "Service                     Service ID" << endl <<
                        "Replaced: Oil filter                11" << endl <<
                        "Refill: Engine oil                  12" << endl <<
                        "Refill: Washer fluid                13" << endl <<
                        "Refill: Coolant fluid               14" << endl <<
                        "--------------------------------------" << endl;
        custom_ptr[i]->SetPerformedService();  
        cout << endl << "--------------------------------------" << endl <<
                        "Part                           Part ID" << endl <<
                        "Tire                                21" << endl <<
                        "Windshield                          22" << endl <<
                        "brakes                              23" << endl <<
                        "Exhaust Pipe                        24" << endl <<
                        "--------------------------------------" << endl;
        custom_ptr[i]->SetPartsChanged();              
        cout << endl << "--------------------------------------" << endl <<
                        "Payment Method       Payment Option ID" << endl <<
                        "Cash                                 1" << endl <<
                        "Credit                               2" << endl <<
                        "Invoice                              3" << endl <<
                        "--------------------------------------" << endl;
        custom_ptr[i]->SetPaymentMethod();
        cin.ignore();
    }

    for (int i = 0; i < 2; i++) {
        cout << endl << endl;
        cout << "RECORD OF CUSTOMER NO." << i+1 << endl <<
                "-----------------------" << endl;
        custom_ptr[i]->GetReceipt();
        delete custom_ptr[i];
    }
    return 0;
}

