/**
 * factory pattern -> creational pattern that creates objects without specifying their 
 * exact class 
 * 
 * 2. Structure of Abstract Factory
*   Key Components
*
    Abstract Product Interfaces → Define common behavior for products (Button, Checkbox).
    Concrete Product Classes → Implement product interfaces for each OS (Windows, MacOS).
    Abstract Factory Interface → Declares creation methods for products.
    Concrete Factory Classes → Implement creation methods for a specific OS.
    Client Code → Uses the factory without knowing the concrete classes.
 */

#include <bits/stdc++.h>
using namespace std;

// abstract product interface
class Button {
public:
    virtual void render() = 0;
};

class Checkbox {
public:
    virtual void render() = 0;
};

// concrete products
// Concrete Product: WindowsButton
class WindowsButton : public Button {
public:
    void render() override {
        cout << "Rendering Windows Button\n";
    }
};

// Concrete Product: MacOSButton
class MacOSButton : public Button {
public:
    void render() override {
        cout << "Rendering MacOS Button\n";
    }
};

// Concrete Product: WindowsCheckbox
class WindowsCheckbox : public Checkbox {
public:
    void render() override {
        cout << "Rendering Windows Checkbox\n";
    }
};

// Concrete Product: MacOSCheckbox
class MacOSCheckbox : public Checkbox {
public:
    void render() override {
        cout << "Rendering MacOS Checkbox\n";
    }
};

class GUIfactory{
public:
    virtual unique_ptr<Button> createButton() = 0;
    virtual unique_ptr<Checkbox> createCheckbox() = 0;
};

// Concrete Factory: WindowsFactory
class WindowsFactory : public GUIfactory {
    public:
        unique_ptr<Button> createButton()  override {
            return make_unique<WindowsButton>();
        }
        unique_ptr<Checkbox> createCheckbox()  override {
            return make_unique<WindowsCheckbox>();
        }
    };
    
    // Concrete Factory: MacOSFactory
class MacOSFactory : public GUIfactory {
public:
    unique_ptr<Button> createButton()  override {
        return make_unique<MacOSButton>();
    }
    unique_ptr<Checkbox> createCheckbox()  override {
        return make_unique<MacOSCheckbox>();
    }
};
    
void renderUI(GUIfactory& obj){
    auto button = obj.createButton();
    auto checkbox = obj.createCheckbox();
    button->render();
    checkbox->render();
}

int main() 
{
    WindowsFactory win;
    MacOSFactory mac;

    cout << "Windows UI" << endl;
    renderUI(win);

    cout << "MAC UI " << endl;
    renderUI(mac);

    
    
    return 0;
}

/**
 * client do not know which concrete class he is dealing with only interacts with GUI factory
 * Scalable -> easily add new class (with same family) which inherits gui factory -> without modifying existing code 
 * 
 * disadvantage 
 * - hard to add new products.
 */
