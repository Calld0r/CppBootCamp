/*
    Implement a function that can read the information shown in the figure.

    Seat Belts   Windows    Doors      Lights
    1 0 1 1 1    0 1 0 0    1 0 1 1    0 1 1
*/

#include <iostream>
#include <bitset>

using namespace std;

const uint16_t bit_frame = 0b1011101001011011;

enum function_mask : uint16_t
{
    seat_belt = 0b1111100000000000,
    window = 0b0000011110000000,
    doors = 0b0000000001111000,
    lights = 0b0000000000000111
};

enum belt_mask : uint8_t
{
    driver = 0b00000001,
    passanger = 0b00000010,
    rear_driver = 0b00000100,
    rear_passanger = 0b00001000,
    rear_middle = 0b00010000
};

enum window_mask : uint8_t
{
    driver_window_opn = 0b00000001,
    passanger_window_opn = 0b00000010,
    rear_driver_window_opn = 0b00000100,
    rear_passanger_window_opn = 0b00001000
};

enum door_mask : uint8_t
{
    driver_door_opn = 0b00000001,
    passanger_door_opn = 0b00000010,
    rear_driver_door_opn = 0b00000100,
    rear_passanger_door_opn = 0b00001000
};

enum light_mask : uint8_t
{
    full_beam = 0b00000001,
    fog_light = 0b00000010,
    hazard = 0b00000100
};

int main()
{
    uint16_t seatBeltVal = (seat_belt & bit_frame) >> 11;
    uint16_t windowVal = (window & bit_frame) >> 7;
    uint16_t doorVal = (doors & bit_frame) >> 3;
    uint16_t lightVal = lights & bit_frame;

    // SEAT BELT
    cout << "Seat Belts val: " << seatBeltVal << " (" << bitset<5>(seatBeltVal) << ")" << endl;
    if (driver & seatBeltVal)
    {
        cout << "Driver Seated" << endl;
    }
    if (passanger & seatBeltVal)
    {
        cout << "Passanger seated" << endl;
    }
    if (rear_driver & seatBeltVal)
    {
        cout << "Rear Driver Seated" << endl;
    }
    if (rear_passanger & seatBeltVal)
    {
        cout << "Rear Passanger Seated" << endl;
    }
    if (rear_middle & seatBeltVal)
    {
        cout << "Rear Middle Seated" << endl;
    }
    if (!seatBeltVal)
    {
        cout << "None Seated" << endl;
    }
    cout << endl;

    // WINDOWS
    cout << "Windows val: " << windowVal << " (" << bitset<4>(windowVal) << ")" << endl;
    if (driver_window_opn & windowVal)
    {
        cout << "Driver Window Open" << endl;
    }
    if (passanger_window_opn & windowVal)
    {
        cout << "Passanger Window Open" << endl;
    }
    if (rear_driver_window_opn & windowVal)
    {
        cout << "Rear Driver Window Open" << endl;
    }
    if (rear_passanger_window_opn & windowVal)
    {
        cout << "Rear Passanger Window Open" << endl;
    }
    cout << endl;

    // DOORS
    cout << "Doors val: " << doorVal << " (" << bitset<4>(doorVal) << ")" << endl;
    if (driver_door_opn & doorVal)
    {
        cout << "Driver Door Open" << endl;
    }
    if (passanger_door_opn & doorVal)
    {
        cout << "Passanger Door Open" << endl;
    }
    if (rear_driver_door_opn & doorVal)
    {
        cout << "Rear Driver Door Open" << endl;
    }
    if (rear_passanger_door_opn & doorVal)
    {
        cout << "Rear Passanger Door Open" << endl;
    }
    cout << endl;

    // LIGHTS
    cout << "Lights val: " << lightVal << " (" << bitset<3>(lightVal) << ")" << endl;
    if (full_beam & lightVal)
    {
        cout << "Full Beam Headlights ON" << endl;
    }
    if (fog_light & lightVal)
    {
        cout << "Fog Lights ON" << endl;
    }
    if (hazard & lightVal)
    {
        cout << "Hazard Warning Lights ON" << endl;
    }
    cout << endl;
}