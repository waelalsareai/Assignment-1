#include <iostream>
using namespace std;

// Include your function declarations and struct/enum definitions
#include "Pokeymon.h"


// Define functions here based on the declarations in Pokeymon.h

string getSetupVerificationMessage() {
    return "Setup is correct!";
}

Type stringToType(const string& typeStr) { if (typeStr == "Fire") return Type::FIRE;
  return Type::NORMAL; }