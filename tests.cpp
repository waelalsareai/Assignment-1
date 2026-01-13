#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

using doctest::Approx;

#include "Pokeymon.h"
#include <string>

using namespace std;

TEST_CASE("setup verification")
{
  string message = getSetupVerificationMessage();
  cout << message << endl;
}

 TEST_CASE("stringToType")
 {
   cout << "(1) stringToType tests..." << endl;
   CHECK(stringToType("Fire") == Type::FIRE);
   CHECK(stringToType("Water") == Type::WATER);
   CHECK(stringToType("Ice") == Type::ICE);
//   CHECK(stringToType("Normal") == Type::NORMAL);

//   // Test unknown string defaults to NORMAL
//   CHECK(stringToType("") == Type::NORMAL);
 }

 TEST_CASE("typeToString")
 {
//   cout << "(2) typeToString tests..." << endl;
//   CHECK(typeToString(Type::FIRE) == "Fire");
//   CHECK(typeToString(Type::WATER) == "Water");
//   CHECK(typeToString(Type::ICE) == "Ice");
//   CHECK(typeToString(Type::NORMAL) == "Normal");
 }

 TEST_CASE("isStrongAgainst")
 {
   cout << "(3) isStrongAgainst tests..." << endl;
   CHECK(isStrongAgainst(Type::FIRE, Type::ICE) == true);
   CHECK(isStrongAgainst(Type::WATER, Type::FIRE) == true);
   CHECK(isStrongAgainst(Type::ICE, Type::WATER) == true);

   CHECK(isStrongAgainst(Type::FIRE, Type::WATER) == false);
   CHECK(isStrongAgainst(Type::WATER, Type::ICE) == false);
   CHECK(isStrongAgainst(Type::ICE, Type::FIRE) == false);
   CHECK(isStrongAgainst(Type::NORMAL, Type::FIRE) == false);
 }

 TEST_CASE("getDescription")
 {
   cout << "(4) getDescription tests..." << endl;
   Pokeymon p = {"Testmon", Type::WATER, 80, 120, 40, 15};
   std::string desc = getDescription(p);
   CHECK(desc == "Name: Testmon, Type: Water, Health: 80/120, Atk: 40, Def: 15");

   Pokeymon p2 = {"Icy", Type::ICE, 82, 90, 25, 15};
   std::string desc2 = getDescription(p2);
   CHECK(desc2 == "Name: Icy, Type: Ice, Health: 82/90, Atk: 25, Def: 15");
 }

 TEST_CASE("getAttackDamage")
{ 
  Pokeymon attacker;
   attacker.attack = 50;
   attacker.type = Type::FIRE;

   Pokeymon defender;
   defender.defense = 20;
   defender.type = Type::ICE;

    Attacker is strong against defender, damage should be doubled
   int damage = getAttackDamage(attacker, defender);
   CHECK(damage == (50 - 20) * 2);

   // Change defender type to WATER, not strong anymore
   defender.type = Type::WATER;
   damage = getAttackDamage(attacker, defender);
   CHECK(damage == (50 - 20));

   // High defense case
   defender.defense = 60;
   damage = getAttackDamage(attacker, defender);
   CHECK(damage == 0); // Damage cannot be negative
 }

// TEST_CASE("attack")
// {
//   cout << "(6) attack tests..." << endl;
//   Pokeymon charmy;
//   charmy.name = "Charmy";
//   charmy.type = Type::FIRE;
//   charmy.currentHealth = 100;
//   charmy.maxHealth = 100;
//   charmy.attack = 30;
//   charmy.defense = 10;

//   Pokeymon icy;
//   icy.name = "Icy";
//   icy.type = Type::ICE;
//   icy.currentHealth = 90;
//   icy.maxHealth = 90;
//   icy.attack = 25;
//   icy.defense = 15;

//   string result = attack(charmy, icy);
//   CHECK(icy.currentHealth == 60);
//   CHECK(result
//         == "Charmy dealt 30 damage to Icy. Icy has 60 health remaining.");

//   result = attack(icy, charmy);
//   CHECK(charmy.currentHealth == 85);
//   CHECK(result
//         == "Icy dealt 15 damage to Charmy. Charmy has 85 health remaining.");

//   // Defender should not end with negative health
//   icy.attack = 9000;
//   result = attack(icy, charmy);
//   CHECK(charmy.currentHealth == 0);
// }