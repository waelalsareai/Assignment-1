#include <iostream>
#include <sstream>
using namespace std;

// Include your function declarations and struct/enum definitions
#include "Pokeymon.h"


// Define functions here based on the declarations in Pokeymon.h

string getSetupVerificationMessage() {
    return "Setup is correct!";
}

Type stringToType(const string& typeStr) {
   if (typeStr == "Fire") return Type::FIRE;
   if (typeStr == "Water") return Type::WATER;
   if (typeStr == "Ice") return Type::ICE;
   return Type::NORMAL; 
 }

 string typeToString(Type type) { 
  if (type == Type::FIRE) return "Fire";   
  if (type == Type::WATER) return "Water";
  if (type == Type::ICE) return "Ice";    
  return "Normal"; }

  bool isStrongAgainst(Type attacker, Type defender)
{
    if (attacker == Type::FIRE  && defender == Type::ICE)   return true;
    if (attacker == Type::WATER && defender == Type::FIRE)  return true;
    if (attacker == Type::ICE   && defender == Type::WATER) return true;
    return false;
}

std::string getDescription(const Pokeymon& p)
{
  std::ostringstream out;
  out << "Name: " << p.name
      << ", Type: " << typeToString(p.type)
      << ", Health: " << p.currentHealth << "/" << p.maxHealth
      << ", Atk: " << p.attack
      << ", Def: " << p.defense;
  return out.str();
}

int getAttackDamage(const Pokeymon& attacker, const Pokeymon& defender)
{
  int dmg = attacker.attack - defender.defense;
  if (dmg < 0) dmg = 0;

  if (isStrongAgainst(attacker.type, defender.type))
    dmg *= 2;

  return dmg;
}




