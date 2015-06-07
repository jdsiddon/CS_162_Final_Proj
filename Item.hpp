#ifndef ITEM_HPP
#define ITEM_HPP

#include <vector>
#include <string>

class Item {

  private:
    std::string name;

    /* Setters */
    void setName(std::string);

  public:
    Item();
    Item(std::string);

    /* Getters */
    std::string getName();


};

#endif
