/*
Key components of the Builder Pattern in C++

    Director: The Director is the main component of the builder pattern it basically responsible
     for the construction process of the program.
     It works with a Builder to build an object. 
     The Director knows the actual steps required to build an object, but it does not know the details of how each step is implemented.

    Builder: The Builder is the main interface or an abstract class that defines the construction steps required to create an object.

    Concrete Builder: Basically, these are the classes that implement the Builder interface. 
    Each Concrete Builder is responsible for constructing a particular variant of the object.

    Product: The Product is the complex object that we want to create.
     The Product class may have methods to access or manipulate these components. It often has multiple parts or components that are built by the Builder.
*/

#include <iostream>
using namespace std;

// Product class
class Computer {
    string cpu;
    string memory;
    string storage;
public:
    void setCPU(const string& c) {
        cpu = c;
    }
    void setMemory(const string& m) {
        memory = m;
    }
    void setStorage(const string& st) {
        storage = st;
    }

    void display() {
        cout << "C.P.U : " << cpu << endl;
        cout << "Memory : " << memory << endl;
        cout << "Storage : " << storage << endl;
    }
};

// Builder interface
class ComputerBuilder {
public:
    virtual void buildCpu(const string& cpu) = 0;
    virtual void buildMemory(const string& memo) = 0;
    virtual void buildStorage(const string& storage) = 0;
    virtual Computer getResult() = 0;
};

// Concrete Builder for Desktop
class DesktopBuilder : public ComputerBuilder {
    Computer comp;
public:
    void buildCpu(const string& cpu) override {
        comp.setCPU(cpu);
    }
    void buildMemory(const string& memo) override {
        comp.setMemory(memo);
    }
    void buildStorage(const string& storage) override {
        comp.setStorage(storage);
    }
    Computer getResult() override {
        return comp;
    }
};

int main() {
    // Create a DesktopBuilder
    DesktopBuilder dskBuild;
    
    // Build the computer directly in the main
    dskBuild.buildCpu("Intel i7");
    dskBuild.buildMemory("16GB");
    dskBuild.buildStorage("512 GB SSD");
    
    // Get the resulting computer
    Computer desktop = dskBuild.getResult();

    // Display the result
    desktop.display();

    return 0;
}
