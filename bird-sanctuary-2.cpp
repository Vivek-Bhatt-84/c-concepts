#include <bits/stdc++.h>
using namespace std;

enum Gender{
    MALE, FEMALE, OTHER
};

class Bird{
public :
    int birdId;
    string name;
    string species;
    short age;
    string placeOfOrigin;
    Gender gender;

    int getId() const {
        return birdId;
    }
    void setId(int id) {
        birdId = id;
    }

    string getName() const {
        return name;
    }

    void setName(string name) {
        this->name = name;
    }

    string getSpecies() const {
        return species;
    }

    void setSpecies(string spcs) {
        species = spcs;
    }

    int getAge() const {
        return age;
    }

    void setAge(int a) {
        age = a;
    }

    string getPlaceOfOrigin() const {
        return placeOfOrigin;
    }

    void setPlace(string place) {
        placeOfOrigin = place;
    }

    Gender getGender() const {
        return gender;
    }

    void setGender(Gender gen) {
        gender = gen;
    }

    void displayBirds() const {
        cout << "Bird ID: " << birdId << ", Name: " << name << ", Species: " << species
        << ", Age: " << age << ", Place of Origin: " << placeOfOrigin
        << ", Gender: " << (gender == MALE ? "Male" : gender == FEMALE ? "Female" : "Other") << endl;
    }
};

struct BirdComparator{
    bool operator()(const Bird* a, const Bird* b) const {
        return a->getId() < b->getId();
    }
};

class BirdRepository{
public :
    set<Bird*, BirdComparator> sanc;

    int getBirdCount() const {
        return sanc.size();
    }

    void addBird(Bird* bd) {
        sanc.insert(bd);
    }

    void removeBirdById(int id) {
        auto it = find_if(sanc.begin(), sanc.end(), [id](Bird* bird) {
            return bird->getId() == id;
        });

        if (it != sanc.end()) {
            delete *it; 
            sanc.erase(it);
            cout << "Bird with ID " << id << " removed." << endl;
        } else {
            cout << "Bird with ID " << id << " not found." << endl;
        }
    }

    void displayAllBirds() const {
        if (sanc.empty()) {
            cout << "No birds in the repository." << endl;
        } else {
            for (const auto& bird : sanc) {
                bird->displayBirds();
            }
        }
    }

   
};

int main()
{
    BirdRepository b1;

    Bird* bird1 = new Bird();
    bird1->setId(1);
    bird1->setName("Parrot");
    bird1->setSpecies("Macaw");
    bird1->setAge(3);
    bird1->setPlace("Amazon Rainforest");
    bird1->setGender(MALE);

    b1.addBird(bird1);

    Bird* b2 = new Bird();
    b2->setId(2);
    b2->setName("Test_name");
    b2->setSpecies("Test_species");
    b2->setAge(5);
    b2->setPlace("Home");
    b2->setGender(OTHER);

    b1.addBird(b2);

    cout << "Before removal:" << endl;
    b1.displayAllBirds();

    b1.removeBirdById(1);

    cout << "\nAfter removal:" << endl;
    b1.displayAllBirds();

    
    
    return 0;
}
