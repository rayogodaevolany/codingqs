#ifndef SCITERATOR_H
#define SCITERATOR_H

#include "studentCollection.h"
#include <cstddef>
using namespace std;


class scIterator {
    public:
        scIterator();
        scIterator(studentCollection::studentNode * initial);
        void advance();
        bool pastEnd();
        studentRecord student();
    private:
        studentCollection::studentNode * current;
};

#endif
