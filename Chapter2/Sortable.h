#ifndef SORTABLE_H
#define SORTABLE_H
class Sortable {
public:
    virtual ~Sortable() = default;
    virtual void sort() = 0;
};
#endif