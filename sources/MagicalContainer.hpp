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
    private:
        vector<int> elements;
        vector<const int *> asceindingElements;
        vector<const int *> sideCrossElements;
        vector<const int *> primeElements;

    public:
        class AscendingIterator
        {
        private:
            MagicalContainer &container;
            size_t position;

        public:
            AscendingIterator(MagicalContainer &container);               // creating operator with container
            AscendingIterator(const AscendingIterator &other);            // copy costructor
            ~AscendingIterator();                                         // destructor
            AscendingIterator &operator=(const AscendingIterator &other); // Assignment operator
            bool operator==(const AscendingIterator &other) const;        // Equality comparison
            bool operator!=(const AscendingIterator &other) const;        // Inequality comparison
            bool operator<(const AscendingIterator &other) const;         // less-than
            bool operator>(const AscendingIterator &other) const;         // greater-than
            int operator*();                                              // Dereference operator
            AscendingIterator &operator++();                              // Pre-increment operator
            MagicalContainer::AscendingIterator begin();                  // Iterator pointing to the first element
            MagicalContainer::AscendingIterator end();                    // Iterator pointing to the last element
        };

        class SideCrossIterator
        {
        private:
            MagicalContainer &container;
            size_t position;

        public:
            SideCrossIterator(MagicalContainer &container);               // creating operator with container
            SideCrossIterator(const SideCrossIterator &other);            // copy costructor
            ~SideCrossIterator();                                         // destructor
            SideCrossIterator &operator=(const SideCrossIterator &other); // Assignment operator
            bool operator==(const SideCrossIterator &other) const;        // Equality comparison
            bool operator!=(const SideCrossIterator &other) const;        // Inequality comparison
            bool operator<(const SideCrossIterator &other) const;         // less-than
            bool operator>(const SideCrossIterator &other) const;         // greater-than
            int operator*();                                              // Dereference operator
            SideCrossIterator &operator++();                              // Pre-increment operator
            MagicalContainer::SideCrossIterator begin();                  // Iterator pointing to the first element
            MagicalContainer::SideCrossIterator end();                    // Iterator pointing to the last element
        };

        class PrimeIterator
        {
        private:
            MagicalContainer &container;
            size_t position;

        public:
            PrimeIterator(MagicalContainer &container);           // creating operator with container
            PrimeIterator(const PrimeIterator &other);            // copy costructor
            ~PrimeIterator();                                     // destructor
            PrimeIterator &operator=(const PrimeIterator &other); // Assignment operator
            bool operator==(const PrimeIterator &other) const;    // Equality comparison
            bool operator!=(const PrimeIterator &other) const;    // Inequality comparison
            bool operator<(const PrimeIterator &other) const;     // less-than
            bool operator>(const PrimeIterator &other) const;     // greater-than
            int operator*();                                      // Dereference operator
            PrimeIterator &operator++();                          // Pre-increment operator
            MagicalContainer::PrimeIterator begin();              // Iterator pointing to the first element
            MagicalContainer::PrimeIterator end();                // Iterator pointing to the last element
        };

        ///////////////////////Magic container class////////////////////////////////////////

        MagicalContainer();              // Magic container constructor
        ~MagicalContainer();             // Magic container destructor
        void addElement(int element);    // adding elements
        void removeElement(int element); // removing elements
        vector<int> getElements() const; // returns all elements
        size_t size() const;             // retrieving the size of the container
        bool operator==(MagicalContainer &other);
        bool operator!=(MagicalContainer &other);
        MagicalContainer(const MagicalContainer &other) = delete;
        MagicalContainer &operator=(const MagicalContainer &other) = default;
        MagicalContainer(MagicalContainer &&other) noexcept = delete;
        MagicalContainer &operator=(MagicalContainer &&other) noexcept = delete;
        static bool isPrime(int num);
    };
}
#endif