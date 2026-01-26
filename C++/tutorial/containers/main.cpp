#include <iostream>
#include <list>


#include <iostream>
#include <list>

void list()
{
    std::list<int> lst({10, 9, 11, 2, 8, 6, 7, 14, 5, 3});

    // ---------------------------
    // ADD
    // ---------------------------
    lst.push_back(21);   // add at end
    lst.push_front(1);   // add at beginning

	std::cout << "List contents: ";
    for (auto &x : lst)
        std::cout << x << " ";
    std::cout << std::endl;
    // ---------------------------
    // UPDATE (insert before iterator)
    // Example: insert 100 at the 5th position
    // ---------------------------
    auto it = lst.begin();
    std::advance(it, 5);     // move iterator to index 5
    lst.insert(it, 100);     // insert before that position

    // ---------------------------
    // DELETE
    // Example: remove all occurrences of 8
    // ---------------------------
    lst.remove(8);

    // Example: erase element at index 3
    it = lst.begin();
    std::advance(it, 3);
	std::cout << "remove: " << *it << std::endl;
    lst.erase(it);

    // ---------------------------
    // ACCESS (at)
    // There is no lst[3], but we can access by advancing an iterator
    // ---------------------------
    it = lst.begin();
    std::advance(it, 4); 
    std::cout << "Element at index 4: " << *it << std::endl;

    // ---------------------------
    // FRONT and BACK
    // ---------------------------
    std::cout << "Front element: " << lst.front() << std::endl;
    std::cout << "Back element : " << lst.back() << std::endl;

    // ---------------------------
    // DISPLAY
    // ---------------------------
    std::cout << "List contents: ";
    for (auto &x : lst)
        std::cout << x << " ";
    std::cout << std::endl;
}

#include <map>

void map_example()
{
    std::map<int, std::string> mp;

    // ---------------------------
    // ADD
    // ---------------------------
    mp.insert({1, "apple"});
    mp.insert({5, "orange"});
	// add 3
    mp[6] = "banana";           // also adds if key doesn't exist
    mp[4] = "Kiwi";           // also adds if key doesn't exist
  	std::cout << "Map contents:\n";
    for (auto &p : mp)
        std::cout << p.first << " => " << p.second << std::endl;
    // ---------------------------
    // UPDATE
    // ---------------------------
    mp[5] = "watermelon";       // update value of key 5

    // ---------------------------
    // DELETE
    // ---------------------------
    mp.erase(3);                // delete key 3
    // mp.erase(mp.begin());    // delete first element

    // ---------------------------
    // ACCESS (at)
    // ---------------------------
    std::cout << "Value at key 1: " << mp.at(1) << std::endl;

    // ---------------------------
    // FRONT / END
    // map is ordered by key
    // ---------------------------
    std::cout << "First element: ";
    std::cout << mp.begin()->first << " => " << mp.begin()->second << std::endl;

    std::cout << "Last element: ";
    auto it = mp.end();
    it--;   // last valid element
    std::cout << it->first << " => " << it->second << std::endl;

    // ---------------------------
    // DISPLAY
    // ---------------------------
    std::cout << "Map contents:\n";
    for (auto &p : mp)
        std::cout << p.first << " => " << p.second << std::endl;
}


int main()
{
	list();
	std::cout << "\n\nMap: \n" ;
	map_example();
}