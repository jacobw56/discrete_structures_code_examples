#include <iostream>
#include <set>

int main()
{
    std::set<int> myset;        // make a set of integers
    std::set<int>::iterator it; // create an (empty) iterator

    // set some initial values:
    for (int i = 1; i <= 5; i++)
    {
        myset.insert(i * 10); // set: 10 20 30 40 50
    }

    it = myset.find(20);         // get an iterator to the element 20
    myset.erase(it);             // remove the element 20
    myset.erase(myset.find(40)); // same thing, but for the element 40, and in one line

    std::cout << "myset contains:";
    for (it = myset.begin(); it != myset.end(); ++it)
    {
        std::cout << ' ' << *it;
    }
    std::cout << '\n'; // output: 10 30 50

    myset.insert(10);
    myset.insert(10);
    myset.insert(10);
    myset.insert(10);
    myset.insert(10);
    myset.insert(11);

    std::cout << "now myset contains:";
    for (it = myset.begin(); it != myset.end(); ++it)
    {
        std::cout << ' ' << *it;
    }
    std::cout << '\n'; // output: 10 11 30 50

    /**
     * Note that there is no great option for set operations like union,
     * intersection, difference, etc. There is, e.g., set_union, but it
     * is inefficient and doesn't do what you would want it to do; namely,
     * it destroys the original sets instead of just returning a union.
     * This leaves the developer to implement something that suits their needs.
     **/

    return 0;
}