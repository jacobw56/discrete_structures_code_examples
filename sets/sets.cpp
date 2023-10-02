#include <iostream>  // std::cout
#include <algorithm> // std::set_union, std::sort
#include <set>       // std::set

int main()
{
    std::set<int> set_a;        // make a set of integers
    std::set<int>::iterator it; // create an (empty) iterator

    // set some initial values:
    for (int i = 1; i <= 5; i++)
    {
        set_a.insert(i * 10); // set: 10 20 30 40 50
    }

    it = set_a.find(20);         // get an iterator to the element 20
    set_a.erase(it);             // remove the element 20
    set_a.erase(set_a.find(40)); // same thing, but for the element 40, and in one line

    std::cout << "set_a contains:";
    for (it = set_a.begin(); it != set_a.end(); ++it)
    {
        std::cout << ' ' << *it;
    }
    std::cout << '\n'; // output: 10 30 50

    set_a.insert(10);
    set_a.insert(10);
    set_a.insert(10);
    set_a.insert(10);
    set_a.insert(10);
    set_a.insert(11);

    std::cout << "now set_a contains:";
    for (it = set_a.begin(); it != set_a.end(); ++it)
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
    std::set<int> set_b;    // make another set of integers
    std::set<int> my_union; // make a set to hold the union

    set_b.insert(10);
    set_b.insert(11);
    set_b.insert(-1);
    set_b.insert(-2);
    set_b.insert(-3);
    set_b.insert(-4);

    it = std::set_union(set_a.begin(), set_a.end(), set_b.begin(), set_a.end(), my_union.begin());

    std::cout << "The union has " << (my_union.size()) << " elements:\n";
    for (it = my_union.begin(); it != my_union.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << '\n';

    return 0;
}