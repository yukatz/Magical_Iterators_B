#include "MagicalContainer.hpp"
#include <algorithm>

namespace ariel
{
    MagicalContainer::MagicalContainer() {}
    MagicalContainer::~MagicalContainer() {}

    void MagicalContainer::addElement(int newElement)
    {
        auto it = lower_bound(elements.begin(), elements.end(), newElement); // find the iterator pointing to the first element in the elements
        // container that is not less than newElement
        elements.insert(it, newElement); // inserts the new element

        ///////preparing the containers with slear and allocate///////
        this->asceindingElements.clear();
        this->asceindingElements.reserve(this->elements.size());
        this->sideCrossElements.clear();
        this->sideCrossElements.reserve(this->elements.size());
        this->primeElements.clear();
        this->primeElements.reserve(this->elements.size());

        size_t start = 0;
        size_t end = elements.size() - 1;

        for (size_t i = 0; i < elements.size(); i++) // iterating over elements in O(n) and inserting each element to the right pvector and position
        {
            ////add to ascendig order, same order as the main container
            this->asceindingElements.push_back(&elements[i]);

            ////add to sideCross order, same order as the main container
            if (i % 2 == 0) // even index pushed from the beggining
            {
                sideCrossElements.push_back(&elements[start]);
                start++;
            }
            else // odd index pushed from the end
            {
                sideCrossElements.push_back(&elements[end]);
                end--;
            }
            if (isPrime(elements[i])) // only if prime, insert
            {
                this->primeElements.push_back(&elements[i]);
            }
        }
    }

    void MagicalContainer::removeElement(int element)
    {
        bool exist = false;
        for (auto currElement : elements)
        {
            if (currElement == element)
            {
                elements.erase(find(elements.begin(), elements.end(), element));
                exist = true;
            }
        }
        if (!exist)
        {
            throw runtime_error("Try to remove not excisted element");
        }
    }

    vector<int> MagicalContainer::getElements() const
    {
        return this->elements;
    }

    size_t MagicalContainer::size() const
    {
        return this->elements.size();
    }

    bool MagicalContainer::operator==(MagicalContainer &other)
    {
        return (this->elements == other.elements);
    }

    bool MagicalContainer::operator!=(MagicalContainer &other)
    {
        return (this->elements != other.elements);
    }
    bool MagicalContainer::isPrime(int num)
    {
        if (num == 1)
        {
            return false;
        }

        if (num == 2)
        {
            return true;
        }

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
    /////////////////Ascending Iterator/////////////////////
    MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer &container)
        : container(container), position(0) {}
    MagicalContainer::AscendingIterator::AscendingIterator(const AscendingIterator &other)
        : container(other.container), position(other.position) {}
    MagicalContainer::AscendingIterator::~AscendingIterator() {}

    MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator=(const AscendingIterator &other)
    {
        if (this->container != other.container)
        {
            throw runtime_error("Not the same container");
        }

        this->container = other.container;
        this->position = other.position;
        return *this;
    }

    int MagicalContainer::AscendingIterator::operator*()
    {
        return *(this->container.asceindingElements[position]);
    }

    MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator++()
    {
        if (this->position == this->end().position)
        {
            throw runtime_error("Out of range");
        }
        ++this->position;
        return *this;
    }

    bool MagicalContainer::AscendingIterator::operator==(const AscendingIterator &other) const
    {
        return (&this->container == &other.container && this->position == other.position);
    }

    bool MagicalContainer::AscendingIterator::operator!=(const AscendingIterator &other) const
    {
        return !(*this == other);
    }

    bool MagicalContainer::AscendingIterator::operator<(const AscendingIterator &other) const
    {
        return this->position < other.position;
    }

    bool MagicalContainer::AscendingIterator::operator>(const AscendingIterator &other) const
    {
        return this->position > other.position;
    }

    MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::begin()
    {
        AscendingIterator ascndIter(this->container);
        ascndIter.position = 0;
        return ascndIter;
    }

    MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::end()
    {
        AscendingIterator ascndIter(this->container);
        ascndIter.position = this->container.size();
        return ascndIter;
    }

    /////////////////Side Cross Iterator/////////////////////
    MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer &container)
        : container(container), position(0) {}
    MagicalContainer::SideCrossIterator::SideCrossIterator(const SideCrossIterator &other)
        : container(other.container), position(other.position) {}
    MagicalContainer::SideCrossIterator::~SideCrossIterator() {}
    MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator=(const SideCrossIterator &other)
    {
        if (this->container != other.container)
        {
            throw runtime_error("Not the same container");
        }
        this->container = other.container;
        this->position = other.position;
        return *this;
    }

    int MagicalContainer::SideCrossIterator::operator*()
    {
        return *(this->container.sideCrossElements[position]);
    }

    MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator++()
    {
        if (this->position == this->end().position)
        {
            throw runtime_error("Out of range");
        }
        ++this->position;
        return *this;
    }

    bool MagicalContainer::SideCrossIterator::operator==(const SideCrossIterator &other) const
    {
        return (&this->container == &other.container && this->position == other.position);
    }

    bool MagicalContainer::SideCrossIterator::operator!=(const SideCrossIterator &other) const
    {
        return !(*this == other);
    }

    bool MagicalContainer::SideCrossIterator::operator<(const SideCrossIterator &other) const
    {
        return this->position < other.position;
    }

    bool MagicalContainer::SideCrossIterator::operator>(const SideCrossIterator &other) const
    {
        return this->position > other.position;
    }

    MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::begin()
    {
        SideCrossIterator sideCrossIter(this->container);
        sideCrossIter.position = 0;
        return sideCrossIter;
    }

    MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::end()
    {
        SideCrossIterator sideCrossIter(this->container);
        sideCrossIter.position = this->container.size();
        return sideCrossIter;
    }

    /////////////////Prime Iterator/////////////////////
    MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer &container) : container(container), position(0) {}
    MagicalContainer::PrimeIterator::PrimeIterator(const PrimeIterator &other) : container(other.container), position(other.position) {}
    MagicalContainer::PrimeIterator::~PrimeIterator() {}
    MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator=(const PrimeIterator &other)
    {
        if (this->container != other.container)
        {
            throw runtime_error("Not the same container");
        }
        this->container = other.container;
        this->position = other.position;
        return *this;
    }

    int MagicalContainer::PrimeIterator::operator*()
    {
        return *(this->container.primeElements[this->position]);
    }

    MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator++()
    {
        if (this->position == this->end().position) // if the iterator is NULL (the end of container)
        {
            throw runtime_error("Out of range");
        }
        ++this->position;
        return *this;
    }

    bool MagicalContainer::PrimeIterator::operator==(const PrimeIterator &other) const
    {
        return (&this->container == &other.container && this->position == other.position);
    }

    bool MagicalContainer::PrimeIterator::operator!=(const PrimeIterator &other) const
    {
        return !(*this == other);
    }

    bool MagicalContainer::PrimeIterator::operator<(const PrimeIterator &other) const
    {
        return this->position < other.position;
    }

    bool MagicalContainer::PrimeIterator::operator>(const PrimeIterator &other) const
    {
        return this->position > other.position;
    }

    MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::begin()
    {
        PrimeIterator primeIter(this->container);
        primeIter.position = 0;
        return primeIter;
    }

    MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::end()
    {
        PrimeIterator primeIter(this->container);
        primeIter.position = this->container.primeElements.size();
        return primeIter;
    }
}