#pragma once
#include <functional>
#include <ostream>
#include <vector>

class Item;


class Inventory
{
friend std::ostream& operator<<( std::ostream& os, const Inventory& inventory );

public:
    Inventory();
    ~Inventory();

    void AddItem( Item* pItem );
    void RemoveItem( const char* name );

    void SortByName();
    void SortByNameReverse();
    void SortByWeight();
    void SortByWeightReverse();

    void FilterItems( const std::function<bool( const Item* pItem )>& filter );
    void ClearFilters();

    void PrintItem( const char* name );

protected:
    [[nodiscard]] std::vector<Item*>::iterator FindItem( const char* name );

protected:
    std::vector<Item*> m_items;
    float m_totalWeight;
};
