#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct NewPlatformGamepadData {
    uint32_t data[5];
};
struct PackedInput {
    unsigned int rightTrigger : 4;    // 0-15
    unsigned int leftTrigger : 4;     // 0-15
    unsigned int unused : 4;          // Reserved for future use
    unsigned int a : 1;               // On/off
    unsigned int b : 1;               // On/off
    unsigned int x : 1;               // On/off
    unsigned int y : 1;               // On/off
    unsigned int rightThumbstick : 8; // 0-255
    unsigned int leftThumbstick : 8;  // 0-255

    PackedInput() { memset(this, 0xFF, sizeof(*this)); }
}; // sizeof(PackedInput) == sizeof(uint32_t)
class ControllerPackingProblem {
  public:
    static PackedInput GetPackedInput(NewPlatformGamepadData np) { int leftTri, rightTri; }
};
int main() {
    NewPlatformGamepadData gamepadData;
    for (int i = 0; i < 5; i++) { std::cin >> gamepadData.data[i]; }
    PackedInput packedInput = ControllerPackingProblem::GetPackedInput(gamepadData);

    std::cout << packedInput.leftTrigger << std::endl;
    std::cout << packedInput.rightTrigger << std::endl;
    std::cout << packedInput.a << std::endl;
    std::cout << packedInput.b << std::endl;
    std::cout << packedInput.x << std::endl;
    std::cout << packedInput.y << std::endl;
    std::cout << packedInput.rightThumbstick << std::endl;
    std::cout << packedInput.leftThumbstick << std::endl;
    return 0;
}