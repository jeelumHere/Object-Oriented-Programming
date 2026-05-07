// ============================================================
//   ROGUE DUNGEON - OOP Concepts Demo (C++)
//   Concepts Covered:
//   1. Class & Object
//   2. Constructor
//   3. Encapsulation  (private/protected members)
//   4. Inheritance    (: public BaseClass)
//   5. Polymorphism   (virtual functions + override)
//   6. Abstraction    (pure virtual function = 0)
//   7. Template Class (GameLog<T>)
//   8. Friend Function (logBattleResult)
//   9. File Handling  (dungeon_log.txt)
// ============================================================

#include <iostream>
#include <string>
#include <cstdlib>   // rand(), srand()
#include <ctime>     // time()
#include <memory>    // unique_ptr (smart pointer)
#include <fstream>   // FILE HANDLING — ofstream, ifstream
using namespace std;


// ============================================================
// TEMPLATE CLASS — GameLog<T>
// A generic list that can collect entries of ANY type.
// Used with GameLog<string> to record battle outcomes,
// and GameLog<int> to track HP snapshots after each fight.
// Both are printed together as a Run Summary at the end.
// ============================================================
template <class T>
class GameLog {
private:
    T   entries[10];   // fixed array — max 10 entries (enough for any dungeon)
    int count;         // how many entries have been added

public:
    // CONSTRUCTOR
    GameLog() : count(0) {}

    // Add a new entry of type T
    void add(T entry) {
        if (count < 10)
            entries[count++] = entry;
    }

    // Print all entries with a heading
    void printAll(string heading) const {
        cout << "\n  " << heading << "\n";
        cout << "  -------------------------------\n";
        for (int i = 0; i < count; i++)
            cout << "  [" << (i + 1) << "] " << entries[i] << "\n";
        cout << "  -------------------------------\n";
    }

    int getCount() const { return count; }
};


// ============================================================
// ABSTRACTION — Abstract Base Class
// pure virtual function (= 0) forces subclasses to implement it
// ============================================================
class Character {
protected:
    // ENCAPSULATION — protected: accessible only by this class
    //                 and its child classes (not outside)
    string name;
    int    hp;
    int    attack;
    int    defense;

public:
    // CONSTRUCTOR — initializes the object when created
    Character(string n, int h, int a, int d)
        : name(n), hp(h), attack(a), defense(d) {}

    // ABSTRACTION — pure virtual function
    // Every subclass MUST override this, or it can't be instantiated
    virtual int specialAbility() = 0;

    // Regular shared methods (inherited by all subclasses)
    void takeDamage(int damage) {
        int actual = max(0, damage - defense);
        hp -= actual;
        cout << "  " << name << " takes " << actual
             << " damage! (HP: " << hp << ")\n";
    }

    bool isAlive()      const { return hp > 0; }
    int  getAttack()    const { return attack; }
    int  getHp()        const { return hp; }
    void addHp(int val)       { hp += val; }

    string getName() const { return name; }

    // Virtual destructor — important in C++ when using inheritance
    virtual ~Character() {}

    // POLYMORPHISM — virtual function for printing info
    virtual void display() const {
        cout << name << " | HP: " << hp
             << " | ATK: " << attack
             << " | DEF: " << defense;
    }
};


// ============================================================
// INHERITANCE — Hero inherits from Character
// ============================================================
class Hero : public Character {
private:
    // ENCAPSULATION — private: only Hero can access these
    string heroClass;
    int    potions;

public:
    // CONSTRUCTOR — calls parent constructor via initializer list
    Hero(string name, string cls) : Character(name, 100, 15, 5) {
        heroClass = cls;
        potions   = 2;

        // Set stats based on chosen class
        if      (cls == "Warrior") { hp = 120; attack = 15; defense = 8; }
        else if (cls == "Mage")    { hp = 80;  attack = 25; defense = 3; }
        else if (cls == "Rogue")   { hp = 100; attack = 18; defense = 5; }
    }

    // POLYMORPHISM — overrides the pure virtual from Character
    // Each hero class has a DIFFERENT special ability (same function name)
    int specialAbility() override {
        int bonus = 0;
        if (heroClass == "Warrior") {
            bonus = 20;
            cout << "  ** " << name << " uses SHIELD BASH! +"
                 << bonus << " bonus damage!\n";
        } else if (heroClass == "Mage") {
            bonus = 35;
            cout << "  ** " << name << " casts FIREBALL! +"
                 << bonus << " bonus damage!\n";
        } else if (heroClass == "Rogue") {
            bonus = 28;
            cout << "  ** " << name << " uses BACKSTAB! +"
                 << bonus << " bonus damage!\n";
        }
        return attack + bonus;
    }

    void usePotion() {
        if (potions > 0) {
            int heal = 30;
            hp += heal;
            potions--;
            cout << "  [POTION] " << name << " heals " << heal
                 << " HP! (HP: " << hp << ") ["
                 << potions << " potions left]\n";
        } else {
            cout << "  No potions left!\n";
        }
    }

    int    getPotions()   const { return potions; }
    string getHeroClass() const { return heroClass; }

    // POLYMORPHISM — override display() to add extra info
    void display() const override {
        cout << "[" << heroClass << "] ";
        Character::display();   // call parent's display()
        cout << " | Potions: " << potions;
    }

    // FRIEND FUNCTION declaration — logBattleResult can access Hero's private members
    friend void logBattleResult(ofstream& logFile, const Hero& hero,
                                const string& enemyName, bool heroWon);
};


// ============================================================
// INHERITANCE — Enemy subclasses, each with own specialAbility
// ============================================================
class Goblin : public Character {
public:
    Goblin() : Character("Goblin", 40, 10, 2) {}

    // POLYMORPHISM — Goblin's version of specialAbility
    int specialAbility() override {
        cout << "  [GOBLIN] throws a ROCK! +5 bonus damage!\n";
        return attack + 5;
    }
};

class Skeleton : public Character {
public:
    Skeleton() : Character("Skeleton", 55, 13, 4) {}

    int specialAbility() override {
        cout << "  [SKELETON] rattles BONES — terrifying attack! +8 bonus damage!\n";
        return attack + 8;
    }
};

class Dragon : public Character {
public:
    Dragon() : Character("Dragon", 90, 20, 10) {}

    int specialAbility() override {
        int bonus = 25;
        cout << "  [DRAGON] breathes FIRE! Massive +" << bonus << " bonus damage!\n";
        return attack + bonus;
    }
};


// ============================================================
// FRIEND FUNCTION — logBattleResult
// Declared as friend of Hero, so it can access Hero's private
// members (heroClass, potions) directly without getters.
// Also handles FILE HANDLING — writes results to dungeon_log.txt
// ============================================================
void logBattleResult(ofstream& logFile, const Hero& hero,
                     const string& enemyName, bool heroWon) {
    // Directly accesses Hero's PRIVATE members (heroClass, potions)
    // — only possible because this is a friend function
    logFile << "-------------------------------\n";
    logFile << "Battle: " << hero.name << " (" << hero.heroClass << ")"
            << " vs " << enemyName << "\n";
    logFile << "Result: " << (heroWon ? "VICTORY" : "DEFEAT") << "\n";
    logFile << "Hero HP Remaining: " << hero.hp << "\n";
    logFile << "Potions Remaining: " << hero.potions << "\n";
    logFile << "-------------------------------\n";
}



// ============================================================
// CLASS & OBJECT — Dungeon manages the game flow
//                  Composition: Dungeon HAS-A Hero
// ============================================================
class Dungeon {

private:
    Hero&          hero;          // reference to the hero object
    int            roomIndex;
    bool           specialUsed;
    ofstream       logFile;       // FILE HANDLING — persistent log file stream
    GameLog<string> battleLog;   // TEMPLATE CLASS — records "Enemy — RESULT" strings
    GameLog<int>    hpLog;       // TEMPLATE CLASS — records hero's HP after each fight

    // Helper: random int between min and max (inclusive)
    static int randInt(int minVal, int maxVal) {
        return minVal + rand() % (maxVal - minVal + 1);
    }

    // Factory: create the right enemy for current room
    // Returns a raw pointer — caller owns it
    Character* spawnEnemy() {
        if (roomIndex == 0) return new Goblin();
        if (roomIndex == 1) return new Skeleton();
        return new Dragon();
    }

    // Run one full battle, returns true if hero survives
    bool battle(Character* enemy) {
        cout << "\n=============================================\n";
        cout << "  BATTLE: " << hero.getName()
             << " vs " << enemy->getName() << "\n";
        cout << "  Hero  -> "; hero.display();  cout << "\n";
        cout << "  Enemy -> "; enemy->display(); cout << "\n";
        cout << "=============================================\n";

        int turn = 0;
        specialUsed = false;

        while (hero.isAlive() && enemy->isAlive()) {
            turn++;
            cout << "\n  --- Turn " << turn << " ---\n";
            cout << "  [1] Attack          (normal hit)\n";
            cout << "  [2] Special Ability (once per fight)\n";
            if (hero.getPotions() > 0)
                cout << "  [3] Use Potion      ("
                     << hero.getPotions() << " left)\n";

            string choice;
            cout << "  Choose: ";
            cin >> choice;

            if (choice == "1") {
                int dmg = hero.getAttack() + randInt(0, 5);
                cout << "  You attack for " << dmg << "!\n";
                enemy->takeDamage(dmg);

            } else if (choice == "2" && !specialUsed) {
                int dmg = hero.specialAbility();   // POLYMORPHISM in action
                enemy->takeDamage(dmg);
                specialUsed = true;

            } else if (choice == "2" && specialUsed) {
                cout << "  Special ability already used this fight!\n";
                continue;  // don't let enemy attack on a skipped turn

            } else if (choice == "3" && hero.getPotions() > 0) {
                hero.usePotion();

            } else {
                cout << "  Invalid choice — you hesitate!\n";
            }

            // Enemy's turn
            if (enemy->isAlive()) {
                int dmg;
                if ((rand() % 10) < 3) {           // 30% chance for special
                    dmg = enemy->specialAbility();   // POLYMORPHISM
                } else {
                    dmg = enemy->getAttack() + randInt(0, 4);
                    cout << "  " << enemy->getName()
                         << " attacks for " << dmg << "!\n";
                }
                hero.takeDamage(dmg);
            }
        }

        return hero.isAlive();
    }

public:
    // CONSTRUCTOR — Dungeon takes a Hero by reference (Composition)
    // FILE HANDLING — opens dungeon_log.txt for writing
    Dungeon(Hero& h) : hero(h), roomIndex(0), specialUsed(false) {
        logFile.open("dungeon_log.txt");   // open log file
        if (logFile.is_open()) {
            logFile << "=============================\n";
            logFile << "  ROGUE DUNGEON - Game Log\n";
            logFile << "=============================\n";
            logFile << "Hero Name  : " << h.getName()      << "\n";
            logFile << "Hero Class : " << h.getHeroClass() << "\n";
            logFile << "=============================\n\n";
        }
    }

    // DESTRUCTOR — FILE HANDLING: close the log file cleanly
    ~Dungeon() {
        if (logFile.is_open())
            logFile.close();
    }

    void run() {
        string rooms[] = { "Goblin's Lair", "Crypt of Bones", "Dragon's Den" };
        int    numRooms = 3;

        cout << "\n=============================================\n";
        cout << "   *** WELCOME TO THE ROGUE DUNGEON ***\n";
        cout << "=============================================\n";
        cout << "  Hero: "; hero.display(); cout << "\n";
        cout << "=============================================\n";

        for (roomIndex = 0; roomIndex < numRooms; roomIndex++) {
            cout << "\n  You enter: " << rooms[roomIndex] << "\n";
            cout << "  Press Enter to face the enemy...";
            cin.ignore(); cin.get();

            // OBJECT CREATION — enemy spawned dynamically
            Character* enemy = spawnEnemy();
            string enemyName = enemy->getName();   // save before deletion

            bool won = battle(enemy);

            // FRIEND FUNCTION + FILE HANDLING — log this battle's result
            if (logFile.is_open())
                logBattleResult(logFile, hero, enemyName, won);

            // TEMPLATE CLASS — record outcome string and hero HP after this fight
            battleLog.add(enemyName + (won ? " — VICTORY" : " — DEFEAT"));
            hpLog.add(hero.getHp());

            // MEMORY MANAGEMENT — delete heap-allocated enemy
            delete enemy;

            if (!won) {
                cout << "\n  *** You have been defeated! Game Over. ***\n";
                // FILE HANDLING — write final outcome
                if (logFile.is_open())
                    logFile << "\nFINAL OUTCOME: DEFEATED in "
                            << rooms[roomIndex] << "\n";
                // TEMPLATE CLASS — still print whatever was logged before defeat
                battleLog.printAll("=== RUN SUMMARY — Battle Results ===");
                hpLog.printAll("=== RUN SUMMARY — HP After Each Fight ===");
                return;
            }

            cout << "\n  [VICTORY] You cleared this room!\n";

            if (roomIndex < numRooms - 1) {
                cout << "  Press Enter to move to the next room...";
                cin.get();
            }
        }

        cout << "\n=============================================\n";
        cout << "  *** VICTORY! You cleared the dungeon! ***\n";
        cout << "=============================================\n";

        // FILE HANDLING — write final victory to log
        if (logFile.is_open())
            logFile << "\nFINAL OUTCOME: DUNGEON CLEARED! Hero survived with "
                    << hero.getHp() << " HP.\n";

        // TEMPLATE CLASS — print full run summary from both GameLog objects
        battleLog.printAll("=== RUN SUMMARY — Battle Results ===");
        hpLog.printAll("=== RUN SUMMARY — HP After Each Fight ===");

        cout << "\n  [LOG] Your adventure has been saved to dungeon_log.txt\n";
    }
};


// ============================================================
// MAIN — Entry point: create objects and start the game
// ============================================================
int main() {
    srand(static_cast<unsigned int>(time(0)));  // seed random

    string heroClass;
    string name;
    bool con = true;

    cout << "\n  === CHARACTER CREATION ===\n";
    cout << "  Enter your hero's name: ";
    cin >> name;


    do{

        cout << "\n  Choose your class:\n";
        cout << "  [1] Warrior  -- High HP, Shield Bash\n";
        cout << "  [2] Mage     -- Low HP, Fireball\n";
        cout << "  [3] Rogue    -- Balanced, Backstab\n";
        cout << "  Choose (1/2/3): ";

        int choice;
        cin >> choice;

        switch(choice){
            case 1 : heroClass = "Warrior"; con = false; break;
            
            case 2 :  heroClass = "Mage"; con = false; break;

            case 3 : heroClass = "Rogue"; con = false; break;

            default : cout<<"Enter  a valid choice."<<endl;
        }

    }
    while(con);



    // OBJECT CREATION — Hero and Dungeon objects
    Hero    hero(name, heroClass);   // Class: Hero, Object: hero
    Dungeon dungeon(hero);           // Class: Dungeon, Object: dungeon

    dungeon.run();

    return 0;
}
