#ifndef MAGICAL_CONTAINER_HPP
#define MAGICAL_CONTAINER_HPP

#include <iostream>
#include <vector>
#include <cmath>

namespace ariel
{
    using namespace std;
    class MagicalContainer
    {

    public:
        // Iterator classes -  scending order.
        class AscendingIterator
        {
        private:
            MagicalContainer *container;
            vector<int> sortedElements;
            int *currElement;

        public:
            AscendingIterator(); // default costructor
            AscendingIterator(MagicalContainer &container);// creating operator with container
            AscendingIterator(const AscendingIterator &other);            // copy costructor
            ~AscendingIterator();                                         // destructor
            AscendingIterator &operator=(const AscendingIterator &other); // Assignment operator
            bool operator==(const AscendingIterator &other) const;        // Equality comparison
            bool operator!=(const AscendingIterator &other) const;        // Inequality comparison
            bool operator<(const AscendingIterator &other) const;         // less-than
            bool operator>(const AscendingIterator &other) const;         // greater-than
            int &operator*();                                             // Dereference operator
            AscendingIterator &operator++();                              // Pre-increment operator
            vector<int>::iterator begin();                                // Iterator pointing to the first element
            vector<int>::iterator end();                                  // Iterator pointing to the last element
        };

        // Iterator classes that allows traversal of elements in cross order.
        class SideCrossIterator //
        {
        private:
            vector<int> sortedElements;
            MagicalContainer *container;
            int *currElement;

        public:
            SideCrossIterator();                                          // default costructor
            SideCrossIterator(MagicalContainer &container);               // creating operator with container
            SideCrossIterator(const SideCrossIterator &other);            // copy costructor
            ~SideCrossIterator();                                         // destructor
            SideCrossIterator &operator=(const SideCrossIterator &other); // Assignment operator
            bool operator==(const SideCrossIterator &other) const;        // Equality comparison
            bool operator!=(const SideCrossIterator &other) const;        // Inequality comparison
            bool operator<(const SideCrossIterator &other) const;         // less-than
            bool operator>(const SideCrossIterator &other) const;         // greater-than
            int &operator*();                                             // Dereference operator
            SideCrossIterator &operator++();                              // Pre-increment operator
            vector<int>::iterator begin();                                // Iterator pointing to the first element
            vector<int>::iterator end();                                  // Iterator pointing to the last element
        };

        // Iterator classes that allows traversal of elements in prime numbers only.
        class PrimeIterator
        {
        private:
            vector<int> primeElements;
            MagicalContainer *container;
            int *currElement;
            static bool isPrime(int num) // basic prime checker
            {
                double sqrtNum = sqrt(num);
                for (int i = 2; i <= sqrtNum; i++)
                {
                    if (num % i == 0)
                    {
                        return false;
                    }
                }
                return true;
            }

        public:
            PrimeIterator();                                      // default costructor
            PrimeIterator(MagicalContainer &container);           // creating operator with container
            PrimeIterator(const PrimeIterator &other);            // copy costructor
            ~PrimeIterator();                                     // destructor
            PrimeIterator &operator=(const PrimeIterator &other); // Assignment operator
            bool operator==(const PrimeIterator &other) const;    // Equality comparison
            bool operator!=(const PrimeIterator &other) const;    // Inequality comparison
            bool operator<(const PrimeIterator &other) const;     // less-than
            bool operator>(const PrimeIterator &other) const;     // greater-than
            int &operator*();                                     // Dereference operator
            PrimeIterator &operator++();                          // Pre-increment operator
            vector<int>::iterator begin();                        // Iterator pointing to the first element
            vector<int>::iterator end();                          // Iterator pointing to the last element
        };
        ///////////////////////Magic container class////////////////////////////////////////
        vector<int> elements;
        // Create the iterators
        AscendingIterator ascendingIterator;
        SideCrossIterator sideCrossIterator;
        PrimeIterator primeIterator;

        MagicalContainer();              // Magic container constructor
        ~MagicalContainer();             // Magic container destructor
        void addElement(int element);    // adding elements
        void removeElement(int element); // removing elements
        vector<int> getElements() const; // returns all elements
        int size() const;                // retrieving the size of the container
        AscendingIterator &getAscendingIterator();
        SideCrossIterator &getSideCrossIterator();
        PrimeIterator &getPrimeIterator();
        MagicalContainer(const MagicalContainer &other) = delete;
        MagicalContainer &operator=(const MagicalContainer &other) = delete;
    };
}
#endif