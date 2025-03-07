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


    Bird(int id, string name, string species, short age, string place, Gender gender)
        : birdId(id), name(name), species(species), age(age), placeOfOrigin(place), gender(gender) {}

    int getId() {
        return birdId;
    }
    void setId(int id){
        birdId = id;
    }

    string getName() {
        return name;
    }

    void setName(string name){
        this -> name = name;
    }

    string getSpecies() {
        return species;
    }

    void setSpecies(string spcs){
        species = spcs;
    }

    int getAge() {
        return age;
    }

    void setAge(int a){
        age = a;
    }

    string getPlaceOfOrigin() {
        return placeOfOrigin;
    }

    void setPlace(string place){
        placeOfOrigin = place;
    }

    Gender getGender() {
        return gender;
    }

    void setGender(Gender gen){
        gender = gen;
    }

    bool operator<(const Bird& b) const{
        return birdId < b.birdId ;
    }

    void displayBirds() {
        cout << "Bird ID: " << birdId << ", Name: " << name << ", Species: " << species
        << ", Age: " << age << ", Place of Origin: " << placeOfOrigin
        << ", Gender: " << (gender == MALE ? "Male" : gender == FEMALE ? "Female" : "Other") << endl;

    }

   
};

struct BirdComparator{
    bool operator()(const unique_ptr<Bird>& a, const unique_ptr<Bird>& b) const {
        return a->getId() < b->getId();
    }
};

class BirdRepository{
public :
    set<unique_ptr<Bird>,BirdComparator> sanc;

    int getBirdCount(){
        return sanc.size();
    }

    void addBird(unique_ptr<Bird> bd){
        sanc.insert(move(bd));
    }



};

int main()
{
    BirdRepository b1;
    // Bird* bird1 = new Bird();
    // bird1->setId(1);
    // bird1->setName("Parrot");
    // bird1->setSpecies("Macaw");
    // bird1->setAge(3);
    // bird1->setPlace("Amazon Rainforest");
    // bird1->setGender(MALE);

    // b1.addBird(*bird1);

    // Bird* b2 = new Bird();
    // b2 -> setId(2);
    // b2 -> setName("Test_name");
    // b2 -> setSpecies("test_species");
    // b2 -> setAge(5);
    // b2 -> setPlace("Home");
    // b2 -> setGender(OTHER);

    // b1.addBird(*b2);

    b1.addBird(make_unique<Bird>(1, "Parrot", "Macaw", 3, "Amazon Rainforest", MALE));

    Bird* b2 = new Bird(2, "Eagle", "Golden Eagle", 5, "Mountains", FEMALE);
    Bird* b3 = b2;
    
    unique_ptr<Bird> b4 = make_unique<Bird>(7, "Flamingo", "Greater Flamingo", 5, "Africa", FEMALE);
    unique_ptr<Bird> b5 = b4;

    shared_ptr<Bird> b6 = make_shared<Bird>(10, "Pigeon", "Rock Pigeon", 4, "Worldwide", FEMALE);
    shared_ptr<Bird> b7 = b6;

    cout << b1.getBirdCount() << endl;

    
return 0;
}