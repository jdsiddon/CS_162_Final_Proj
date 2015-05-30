#ifndef ITEM_HPP
#define ITEM_HPP

#include <vector>
#include <string>

class Item {

  private:
    std::string name;
    void setName(std::string);

  public:
    Item();
    Item(std::string);
    std::string getName();
    
};

#endif
