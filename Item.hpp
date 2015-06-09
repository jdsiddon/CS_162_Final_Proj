#ifndef ITEM_HPP
#define ITEM_HPP

#include <vector>
#include <string>

class Item {

  private:
    std::string name;
    bool visible;

    /* Setters */
    void setName(std::string);

  public:
    Item();
    Item(std::string);

    /* Setters */
    void setVisible(bool);

    /* Getters */
    std::string getName();
    bool getVisible();


};

#endif
