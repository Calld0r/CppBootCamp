/*
    Write a function which can encode the information in the given figure:
        • Speed / 20 (So 1=20km/h, 2=40km/h,...)
        • Distance / 150 (So 1=150mm, 2=300mm,...)

    It is a trade off between memory usage and accuracy.

    Speed    Front  Rear   Right  Left
    1 0 1 1  1 0 1  0 0 1  0 1 1  0 1 1
*/

#include <iostream>
#include <bitset>

using namespace std;

enum bit_frame_mask : uint16_t
{
    speed = 0b1111000000000000,
    front_dist = 0b0000111000000000,
    rear_dist = 0b0000000111000000,
    right_dist = 0b0000000000111000,
    left_dist = 0b0000000000000111
};

int getSpeed(uint16_t &bit_frame, uint16_t &speedVal)
{
    speedVal = (speed & bit_frame) >> 12;
    return speedVal * 20;
}

int getFrontDist(uint16_t &bit_frame, uint16_t &frontDistVal)
{
    frontDistVal = (front_dist & bit_frame) >> 9;
    return frontDistVal * 150;
}

int getRearDist(uint16_t &bit_frame, uint16_t &rearDistVal)
{
    rearDistVal = (rear_dist & bit_frame) >> 6;
    return rearDistVal * 150;
}

int getRightDist(uint16_t &bit_frame, uint16_t &rightDistVal)
{
    rightDistVal = (right_dist & bit_frame) >> 3;
    return rightDistVal * 150;
}

int getLeftDist(uint16_t &bit_frame, uint16_t &leftDistVal)
{
    leftDistVal = left_dist & bit_frame;
    return leftDistVal * 150;
}

int main()
{
    uint16_t bit_frame = 0b1011101001011011;
    uint16_t speed{}, frontDist{}, rearDist{}, rightDist{}, leftDist{};

    cout << "Speed: " << getSpeed(bit_frame, speed) << " km/h"
         << " (" << bitset<4>(speed) << ") " << endl;
    cout << "Front Distance: " << getFrontDist(bit_frame, frontDist) << " mm"
         << " (" << bitset<3>(frontDist) << ") " << endl;
    cout << "Rear Distance: " << getRearDist(bit_frame, rearDist) << " mm"
         << " (" << bitset<3>(rearDist) << ") " << endl;
    cout << "Right Distance: " << getRightDist(bit_frame, rightDist) << " mm"
         << " (" << bitset<3>(rightDist) << ") " << endl;
    cout << "Left Distance: " << getLeftDist(bit_frame, leftDist) << " mm"
         << " (" << bitset<3>(leftDist) << ") " << endl;

    return 0;
}