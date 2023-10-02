#include <iostream>  // std::cout
#include <algorithm> // std::set_union, std::sort
#include <iterator>  // std::inserter
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
     * is inefficient and doesn't do what you would want it to do (rtfm).
     * This leaves the developer to implement something that suits their needs.
     **/
    std::set<int> set_b;      // make another set of integers
    std::set<int> output_set; // make a set to hold the set operation

    set_b.insert(10);
    set_b.insert(11);
    set_b.insert(-1);
    set_b.insert(-2);
    set_b.insert(-3);
    set_b.insert(-4);

    std::cout << "set_b contains:";
    for (it = set_b.begin(); it != set_b.end(); ++it)
    {
        std::cout << ' ' << *it;
    }
    std::cout << '\n'; // output: -4 -3 -2 -1 10 11

    /**
     * Here is a simple union implementation. Since elements are unique anyway,
     * just insert everything.
     **/
    for (it = set_a.begin(); it != set_a.end(); ++it)
    {
        output_set.insert(*it);
    }

    for (it = set_b.begin(); it != set_b.end(); ++it)
    {
        output_set.insert(*it);
    }

    std::cout << "union contains:";
    for (it = output_set.begin(); it != output_set.end(); ++it)
    {
        std::cout << ' ' << *it;
    }
    std::cout << '\n'; // output: -4 -3 -2 -1 10 11 30 50

    output_set.clear(); // empty the ouput set

    /**
     * Here is a simple intersection implementation. Check every pair of elements.
     **/
    for (it = set_a.begin(); it != set_a.end(); ++it)
    {
        std::set<int>::iterator it_b; // create an (empty) iterator
        for (it_b = set_b.begin(); it_b != set_b.end(); ++it_b)
        {
            if (*it == *it_b)
            {
                output_set.insert(*it);
            }
        }
    }

    std::cout << "intersection contains:";
    for (it = output_set.begin(); it != output_set.end(); ++it)
    {
        std::cout << ' ' << *it;
    }
    std::cout << '\n'; // output: 10 11

    output_set.clear(); // empty the ouput set

    /**
     * Here is a simple difference implementation. Check every pair of elements.
     **/
    bool add_element;
    for (it = set_a.begin(); it != set_a.end(); ++it)
    {
        std::set<int>::iterator it_b; // create an (empty) iterator
        add_element = true;           // reset the flag
        for (it_b = set_b.begin(); it_b != set_b.end(); ++it_b)
        {
            if (*it == *it_b)
            {
                add_element = false;
            }
        }
        if (add_element)
        {
            output_set.insert(*it);
        }
    }

    std::cout << "difference contains:";
    for (it = output_set.begin(); it != output_set.end(); ++it)
    {
        std::cout << ' ' << *it;
    }
    std::cout << '\n'; // output: 30 50

    return 0;
}