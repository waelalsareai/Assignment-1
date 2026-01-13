#ifndef POKEYMON_H
#define POKEYMON_H

#include <string>
// Not "using namespace std;" to avoid namespace pollution
// Use "std::string" explicitly in this file

/**
 * @brief Returns a message verifying that the setup is correct.
 *
 * @return std::string Setup verification message
 */
std::string getSetupVerificationMessage();

/**
 * @brief Type enum represents the different types of Pokeymon.
 */
enum class Type { FIRE, WATER, ICE, NORMAL };
 


/**
 * @brief 'typeToString' converts a Type enum to its string representation.
 *
 * @param type Type of Pokeymon
 * @return std::string Capitalized string representation of the type ("Fire",
 * "Water", etc.)
 */
std::string typeToString(Type type);

/**
 * @brief 'stringToType' converts a string representation of a type to its Type
 * enum.
 *
 * @param typeStr Capitalized string representation of the type ("Fire",
 * "Water", etc.)
 * @return Type Corresponding Type enum
 */
Type stringToType(const std::string& typeStr);

/**
 * @brief isStrongAgainst checks if the attacker type is strong against the
 * defender type.
 * @param attacker Type of the attacking Pokeymon
 * @param defender Type of the defending Pokeymon
 * @return true if attacker is strong against defender, false otherwise
 *
 * Type effectiveness rules:
 * - Fire is strong against Ice
 * - Water is strong against Fire
 * - Ice is strong against Water
 * Other combinations are not strong.
 */
bool isStrongAgainst(Type attacker, Type defender);

/**
 * @brief Pokeymon struct represents a Pokeymon with various attributes.
 */
// TODO - define the Pokeymon struct with the following members

/**
 * @brief getDescription returns a string description of the given Pokeymon.
 *
 * @param p Pokeymon to describe
 * @return std::string Description of the Pokeymon
 *
 * The description format is:
 * "Name: [name], Type: [type], Health: [currentHealth]/[maxHealth], Atk:
 * [attack], Def: [defense]"
 */
std::string getDescription(const Pokeymon& p);

/**
 * @brief getAttackDamage calculates the damage dealt by the attacker to the
 * defender.
 *
 * @param attacker Pokeymon that is attacking
 * @param defender Pokeymon that is defending
 * @return int The damage dealt to the defender
 *
 * Damage calculation:
 * - Base damage is attacker's attack minus defender's defense, but never less
 * than 0.
 * - If the attacker is strong against the defender, damage is doubled.
 */
int getAttackDamage(const Pokeymon& attacker, const Pokeymon& defender);

/**
 * @brief Performs an attack from the attacker Pokeymon to the defender
 * Pokeymon.
 *
 * @param attacker Pokeymon that is attacking
 * @param defender Pokeymon that is defending (will be modified)
 * @return string A message describing the outcome of the attack
 *
 * attack causes the attacker to deal damage to the defender based on the
 * getAttackDamage function. The defender's currentHealth is reduced by the
 * damage dealt, but not below 0. The function returns a message indicating how
 * much damage was dealt. (e.g., "[Attacker Name] dealt [Damage] damage to
 * [Defender Name].")
 */
std::string attack(const Pokeymon& attacker, Pokeymon& defender);

/**
 * @brief Simulates a battle between two Pokeymon until one is defeated.
 *
 * @param p1 First Pokeymon
 * @param p2 Second Pokeymon
 *
 * The function alternates attacks between p1 and p2 until one of them has
 * currentHealth reduced to 0. After each attack, it prints the outcome of the
 * attack and the current health of both Pokeymon.
 * When a Pokeymon is defeated, it prints a message indicating which Pokeymon
 * has been defeated and the battle ends.
 */
void battle(Pokeymon& p1, Pokeymon& p2);

#endif // POKEYMON_H