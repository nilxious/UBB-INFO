
#ifndef ACTIUNEUNDO_H
#define ACTIUNEUNDO_H

class ActiuneUndo {
public:
    virtual void doUndo() = 0;

    virtual ~ActiuneUndo(){};
};


#endif //ACTIUNEUNDO_H
